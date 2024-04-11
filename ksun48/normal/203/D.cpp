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
  double a, b, m, vx, vy, vz;
  cin >> a >> b >> m >> vx >> vy >> vz;
  double tx = -m/vy;
  double tz = -m/vy;
  double x = a/2;
  double z = 0;
  double dx = x+tx*vx;
  while (dx > a || dx < 0){
    if(dx > a){
      dx = 2*a-dx;
    } else if(dx < 0){
      dx = -dx;
    }
  } 

  double dz = z+tz*vz;
  while (dz > b || dz < 0){
    if(dz > b){
      dz = 2*b-dz;
    } else if(dz < 0){
      dz = -dz;
    }
  }
  printf("%.10f %.10f\n", dx, dz);
}