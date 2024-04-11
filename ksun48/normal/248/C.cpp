#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
#include <set>
#include <queue>
#include <complex>
#include <deque>
#include <math.h>
#include <map>
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf

int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  
  double y1,y2,yw,xb,yb,r;
  cin >> y1 >> y2 >> yw >> xb >> yb >> r;
  double newy = 2*(yw-r)-yb;
  double miny = r+y1;
  double dist = (xb*y2-xb*miny)/sqrt((newy-miny)*(newy-miny)+xb*xb);
  //printf("miny = %.10g\n", miny);
  //printf("dist = %.10g\n", dist);
  if(dist < r + 0.0000001){
    cout << -1 << endl;
    exit(0);
  }
  //cout << yw-r-miny << endl;
  double k = ((xb)*(yw-r-miny))/(newy-miny);
  printf("%.10lf\n", k);
}