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
#include <map>
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf

int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  double x1, y1, r1, x2, y2, r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
  double dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
  double k;
  if(r1 + r2 <= dist){
    k = (dist - r1 - r2)/2;
  } else if(r1 - r2 > dist){
    k = (r1 - dist - r2)/2;
  } else if(r2 - r1 > dist){
    k = (r2 - dist - r1)/2;
  } else {
    k = 0;
  }
  printf("%.50lf\n", k);
}