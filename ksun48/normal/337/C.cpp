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
#define MOD 1000000009
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  
  LL n, m, k;
  cin >> n >> m >> k;
  if((n-m+1)*(k-1) >= m){
    cout << m << endl;
    exit(0);
  } else {
    LL a = n-k*(n-m);
    LL b = (a)/k;
    LL endscore = (a % k)+(k-1)*(n-m);
    LL pow2[31];
    pow2[0] = 2;
    for(int i = 1; i < 30; i++){
      pow2[i] = (pow2[i-1]*pow2[i-1]) % MOD;
    }
    LL c = b+1;
    LL pow2c = 1;
    for(int i = 0; i < 30; i++){
      if(c % 2 == 1){
	pow2c = (pow2c*pow2[i]) % MOD;
      }
      c /= 2;
    }
    cout << ((pow2c+MOD-2)*k + endscore) % MOD << endl;
    exit(0);
  }
}