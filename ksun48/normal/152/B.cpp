#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
LL Min(LL a, LL b) {
  return (a < b ? a : b);
}
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  LL n, m, xc, yc, k;
  cin >> n >> m >> xc >> yc >> k;
  LL vx, vy;
  LL nsteps = 0;
  for(int i = 0; i < k; i++){
    cin >> vx >> vy;
    LL steps = 2000000000;
    if(vx >= 1){
      steps = Min(steps, (int((n-xc)/vx)));
    } else if (vx <= -1){
      steps = Min(steps, int((1-xc)/vx));
    }
    if(vy >= 1){
      steps = Min(steps, int((m-yc)/vy));
    } else if (vy <= -1){
      steps = Min(steps, int((1-yc)/vy));
    }
    nsteps += steps;
    xc += steps*vx;
    yc += steps*vy;
  }
  cout << nsteps << endl;
}