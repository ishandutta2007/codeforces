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
#include <utility>
#include <limits>
// numeric_limits<int>::max()
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
int Min(int a, int b) {
  return (a < b ? a : b);
}
int Max(int a, int b) {
  return (a > b ? a : b);
}
int Abs(int a) {
  return (a >= 0 ? a : -a);
}
LL pow2[40];
int DEBUG = 0;
LL nCr[40][40];
LL choose(int n, int r){
  if( n >= 0 && r >= 0) return nCr[n][r];
  return 0;
}
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  LL n, t;
  cin >> n >> t;
  n++;
  pow2[0] = 1;
  int k = -1;
  if(t == 1) k = 0;
  for(int i = 1; i < 40; i++){
    pow2[i] = 2*pow2[i-1];
    if(t == pow2[i]) k = i;
  }
  for(int i = 1; i < 40; i++){
    nCr[0][i] = 0;
  }
  nCr[0][0] = 1;
  for(int i = 1; i < 40; i++){
    for(int j = 0; j < 40; j++){
      nCr[i][j] = nCr[i-1][j];
      if(j > 0) nCr[i][j] += nCr[i-1][j-1];
    }
  }
  if(k == -1){
    cout << 0 << endl;
    exit(0);
  }
  LL cur = 0;
  LL col = 0;
  LL numt = 0;
  if(k == 0) numt--;
  while(cur < n){
    if(cur+pow2[col] <= n){
      cur += pow2[col];
      numt += choose(col, k);
      col ++;
    } else if(cur + pow2[col-1] <= n){
      cur += pow2[col-1];
      numt += choose(col-1, k);
      col--;
      k--;
    } else {
      col--;      
    }
  }
  
  cout << numt << endl;
}