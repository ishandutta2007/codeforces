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
#define MOD 1000000009
LL pascal[5000][5000];
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  LL factorial[5000];
  factorial[0] = 1;
  for(int i = 1; i < 5000; i++){
    factorial[i] = (factorial[i-1] * i) % 1000000009;
  }
  for(int i = 0; i < 5000; i++){
    pascal[i][0] = pascal[i][i] = 1;
  }
  for(int i = 1; i < 5000; i++){
    for(int j = 1; j < 5000; j++){
      pascal[i][j] = (pascal[i-1][j-1] + pascal[i-1][j]) % MOD;
    }
  }
  int n, w, b;
  cin >> n >> w >> b;
  LL ans = (factorial[w]*factorial[b]) % MOD;
  LL mult = 0;
  for(int i = 1; i < n; i++){
    if((n-i) <= w && i <= b){
      LL here = 0;
      
      here = n-i-1;
      here = (here * (pascal[b-1][i-1])) % MOD;
      here = (here * (pascal[w-1][n-i-1])) % MOD;
      //cout << i << " " << here << endl;
      mult = (mult + here) % MOD;
    }
  }
  ans = (ans * mult) % MOD;
  cout << ans << endl;
}