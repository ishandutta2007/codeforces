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
#include <vector>
// numeric_limits<int>::max()
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
int DEBUG = 0;
LL pow2[63];
LL maxor(LL l, LL r){
  //cout << l << " " << r << endl;
  if(l == r) return 0;
  for(int i = 0; i < 61; i++){
    if(pow2[i] > l && pow2[i] <= r && pow2[i+1] > r){
      return (pow2[i+1]-1);
    }
  }
  for(int i = 0; i < 61; i++){
    if(pow2[i] <= l && pow2[i+1] > r){
      return maxor(l-pow2[i], r-pow2[i]);
    } 
  }
  
}
main(int argc, char **argv) {
  //int a;
  //scanf("%d", &a);
  pow2[0] = 1;
  for(int i = 1; i < 62; i++){
    pow2[i] = pow2[i-1]*2;
  }
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  LL l, r;
  cin >> l >> r;
  cout << maxor(l, r) << endl;
  
  
}