#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
#include <math.h>
int Min(int a, int b) {
  return (a < b ? a : b);
}
int Max(int a, int b) {
  return (a > b ? a : b);
}
#define EPSILON .000001
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
using namespace std;
double Abs(double a) {
  return (a >= 0 ? a : -a);
}
int DEBUG = 0;
int gcd(int a, int b){
  while(a != b){
    if(a > b){
      if(a % b == 0){
	a = b;
      } else {
	a = a % b;
      }
    } else {
      int tmp = b;
      b = a;
      a = tmp;
    }
  }
  return a;
}
const double PI = 3.141592653589793238462;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  double ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  ax += .0000001; cx -= .0000001; ay += .0000001; cy -= .0000001;
  double mabx = (ax+bx)/2;
  double maby = (ay+by)/2;
  double macx = (ax+cx)/2;
  double macy = (ay+cy)/2;
  double abperp = -1*(bx-ax)/(by-ay);
  double acperp = -1*(cx-ax)/(cy-ay);
  double abint = maby - abperp*mabx;
  double acint = macy - acperp*macx;
  double centx = ((acint-abint)/(abperp-acperp));
  double centy = abperp*centx+abint;
  double anglea = atan2(ay-centy, ax-centx);
  double angleb = atan2(by-centy, bx-centx);
  double anglec = atan2(cy-centy, cx-centx);
  double max = anglea;
  double middle = anglea;
  double min = anglea;
  double rsq = (ay-centy)*(ay-centy)+(ax-centx)*(ax-centx); 
  int d[2];
  double k[2];
  double first;
  double second;
  int i;
  int num;
  double area;
  if(angleb > max){
    max = angleb;
  }
  if(angleb < min){
    min = angleb;
  } 
  if(anglec > max){
    max = anglec;
  }
  if(anglec < min){
    min = anglec;
  }
  middle = anglea+angleb+anglec-min-max;
  first = (max-middle)/(2*PI);
  for(i = 2; i <= 100; i++){
    if(Abs(first*i+EPSILON-int(first*i+EPSILON) <= EPSILON*10)){
      d[0] = i;
      break;
    }
  }
  second = (middle-min)/(2*PI);
  for(i = 2; i <= 100; i++){
    if(Abs(second*i+EPSILON-int(second*i+EPSILON) <= EPSILON*10)){
      d[1] = i;
      break;
    }
  }
  //cout << d[0] << " " << d[1] << endl;
  num = (d[0]*d[1])/gcd(d[0], d[1]);
  //cout << rsq << endl;
  area = rsq*num*sin(2*PI/num)/2;
  printf("%lf\n", area);
  exit(0);
}