#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
#include <set>
#include <queue>
#include <algorithm>
#include <complex>
#include <deque>
#include <map>
#include <math.h>
#include <utility>
#include <limits>
#include <vector>
// numeric_limits<int>::max()
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  double w, h, a;
  cin >> w >> h >> a;
  if(a == 0 || a == 180){
    printf("%.10lf\n", w*h);
    exit(0);
  }
  if(a >= 90){
    a = 180-a;
  }
  a /= 180;
  a *= 3.1415926535;
  if(h > w){
    double x = h;
    h = w;
    w = x;
  }
  if(a >= 2*atan2(h,w)){
    printf("%.10lf\n", h*h/sin(a));
  } else {
    double c = cos(a);
    double s = sin(a);
    double x = ((1+c)*h-s*w)/((1+c+s)*(1+c-s));
    double y = (w+h)/(1+c+s)-x;
    //cout << x + y << endl;
    //cout << c << " " << s << " " << x << " " << y << " " << endl;
    
    printf("%.10lf\n", w*h - x*x*c*s-y*y*c*s);
  }
}