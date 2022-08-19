#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf

int Min(int a, int b) {
  return (a < b ? a : b);
}
int Max(int a, int b) {
  return (a > b ? a : b);
}
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n;
  cin >> n;
  int minr[2011], minc[2011], maxr[2011], maxc[2011];
  int vx[n], vy[n];
  for(int i = 0; i < 2011; i++){
    minr[i] = 99999;
    minc[i] = 99999;
    maxr[i] = 0;
    maxc[i] = 0;
  }
  for(int i = 0; i < n; i++){
    cin >> vx[i] >> vy[i];
    vx[i] += 1002;
    vy[i] += 1002;
    minr[vx[i]] = Min(vy[i], minr[vx[i]]);
    maxr[vx[i]] = Max(vy[i], maxr[vx[i]]);
    minc[vy[i]] = Min(vx[i], minc[vy[i]]);
    maxc[vy[i]] = Max(vx[i], maxc[vy[i]]);
  }
  int nsc = 0;
  for(int i = 0; i < n; i++){
    if(vx[i] != minc[vy[i]] && vx[i] != maxc[vy[i]] && vy[i] != minr[vx[i]] && vy[i] != maxr[vx[i]]){
      nsc++;
    }
  }
  cout << nsc << endl;
}