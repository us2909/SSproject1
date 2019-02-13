#include <AFMotor.h>
#include <Servo.h>
#define TRIG_PIN A0
#define ECHO_PIN A1
#define MAX_DISTANCE 200 
#define TURN_DIST COLL_DIST+10 

AF_DCMotor motorright(1);
AF_DCMotor motorleft(2);
const int trigPin = A0;
const int echoPin = A1;
void setup() {
  
  Serial.begin(9600); 
motorright.setSpeed(255);
motorleft.setSpeed(255);
   pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // put your setup code here, to run once:

}

void loop() {
  long duration, distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;
  Serial.print(distance);
  delay(10);
 
if(distance<20)  
 {
  motorright.run(BACKWARD); 
  motorleft.run(FORWARD);            
 } 
 else if (distance>20)
 {
   motorright.run(BACKWARD);
   motorleft.run(BACKWARD);
 }
 
}