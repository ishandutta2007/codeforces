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
#define MOD 1000000007
int DEBUG = 0;
LL fact[2011];
LL factinv[2011];
LL inv(LL a){
  LL p = 1000000005;
  LL k = a;
  LL inv = 1;
  while(p > 0){
    if(p % 2) inv = (inv*k) % MOD;
    k = (k*k) % MOD;
    p /= 2;
  }
  return inv;
}
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  fact[0] = 1;
  factinv[0] = inv(fact[0]);
  for(int i = 1; i <= 2000; i++){
    fact[i] = (fact[i-1]*i) % MOD;
    factinv[i] = inv(fact[i]);
  }
  //cout << fact[2] << " " << factinv[2] << endl;
  int n;
  cin >> n;
  int a[n];
  int b[n];
  for(int i = 0; i < n; i++){
    b[i] = 1;
  }
  int k = n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    a[i]--;
    if(a[i] >= 0){
      k--;
      b[a[i]] = 0;
      b[i] = 0;
    }
  }
  int c = 0;
  for(int i = 0; i < n; i++){
    if(b[i] == 1) c++;
  }//sum (-1)^d C(b,d) (k-d)!
  LL ans= 0;
  for(int d = 0; d <= c; d++){
    LL num = 1;
    num = ((fact[c]*fact[k-d] % MOD)*(factinv[d]*factinv[c-d] % MOD)) % MOD;
    //cout << num << endl;
    if(d % 2) ans -= num;
    if(d % 2 == 0) ans += num;
  }
  while(ans < 0){
    ans += MOD;
  }
  cout << ans % MOD << endl;
}