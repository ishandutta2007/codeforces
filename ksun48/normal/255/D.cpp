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
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  LL n, x, y, c;
  cin >> n >> x >> y >> c;
  LL p = 1;
  if(p >= c){
    cout << 0 << endl;
    exit(0);
  }
  LL ur = 0, dr = 0, ul = 0, dl = 0;
  LL u = 1, d = 1, r = 1, l = 1;
  if(x == 1){
    u = -1;
  }
  if(x == n){
    d = -1;
  }
  if(y == 1){
    l = -1;
  }
  if(y == n){
    r = -1;
  }
  for(LL i = 1; i <= 2*n; i++){
    //cout << u << " " << d << " " << r << " " << l << endl;
    //cout << ur << " " << dr << " " << ul << " " << dl << endl;
    if(u == 1) p++;
    if(d == 1) p++;
    if(r == 1) p++;
    if(l == 1) p++;
    p += (ur+dr+ul+dl);
    if(u == 1 && r == 1){
      ur ++;
    } else if ( u == -1 && r == -1 && ur > 0){
      ur --;
    }
    if(d == 1 && r == 1){
      dr ++;
    } else if ( d == -1 && r == -1 && dr > 0){
      dr --;
    }
    if(u == 1 && l == 1){
      ul ++;
    } else if ( u == -1 && l == -1 && ul > 0){
      ul --;
    }
    if(d == 1 && l == 1){
      dl ++;
    } else if ( d == -1 && l == -1 && dl > 0){
      dl --;
    }
    if(x-i <= 1) u = -1;
    if(x+i >= n) d = -1;
    if(y-i <= 1) l = -1;
    if(y+i >= n) r = -1;
    //if(DEBUG) cout << p << endl;
    if(p >= c){
      cout << i << endl;
      exit(0);
    }
  }
  
}