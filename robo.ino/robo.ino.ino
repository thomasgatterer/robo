int in1 = 9;
int in2 = 10;
int enA = 8;
int in3 = 11;
int in4 = 12;
int enB = 13;

int ultraA = 5;
int ultraA = 6;
int servo = 7;


//Ultrasonic Sensor Programm

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int pos = 0;    // variable to store the servo position

int duration;
int distance;

int getDistance()
{
  duration = 0;
  distance = 0;

  digitalWrite(5, LOW);
  delay(5);

  digitalWrite(5, HIGH);
  delay(10);

  digitalWrite(5, LOW);
  duration = pulseIn(6, HIGH);

  distance = (duration / 2) * 0.03432;

  // or = ||
  if (distance >= 400 || distance <= 0) {
    Serial.println("Kein Messwert");
    return 0;
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    return distance;
  }
  delay(100);
}

//--------------------------------------
bool someInfront() {
  int stepWith = 50;
  int dist45=0;
  int dist90=0;
  int dist135=0;
  
    myservo.write(45);
    dist45=getDistance();
    delay(1000);
    myservo.write(90);
    dist90=getDistance();
    delay(1000);
    myservo.write(135);
    dist135=getDistance();
    delay(1000);

    if (dist45<stepWith||dist90<stepWith||dist135<stepWith)
      return true;
    else
      return false;
}



void _mLeft(int pin1,int pin2)
{
digitalWrite(pin1,LOW);
digitalWrite(pin2,HIGH);
}

void _mRight(int pin1, int pin2)
{
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
}

void setup() {

  pinMode(5, OUTPUT);
  pinMode(6, INPUT);

  Serial.begin(9600); //Sets the data rate in bits per second for serial data transmission
//--------------------------------------
  myservo.attach(7);  // attaches the servo on pin 9 to the servo object
//--------------------------------------

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);

  
}



void loop() {

   /* if(someInfront())
    {
     Serial.print("STOP!!!!"); 
    }
   
*/

  digitalWrite(enA, HIGH);   // turn the Motor on (HIGH is the voltage level)
  digitalWrite(enB, HIGH);   // turn the Motor on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(enA, LOW);    // turn the Motor off by making the voltage LOW
  digitalWrite(enB, LOW);    // turn the Motor off by making the voltage LOW
  delay(1000);    
  
  _mRight(in1, in2);
  _mRight(in3, in4);
   
         
}



