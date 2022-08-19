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
LL gcd(LL a, LL b){
  if(b > a) return gcd(b,a);
  if(a % b == 0) return b;
  return gcd(b,a % b);
}
main(int argc, char **argv) {
  //int a;
  //scanf("%d", &a);
  LL pow2[24];
  pow2[0] = 1;
  for(int i = 1; i < 24; i++){
    pow2[i] = pow2[i-1]*2;
  }
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  LL n, x;
  cin >> n >> x;
  for(LL d = 2; d*d <= (n+1); d++){
    if((n+1) % d == 0){
      cout << -1 << endl;
      exit(0);
    }
  }
  LL p = n+1;
  for(LL b = x-1; b > 1; b--){
    int yes = 1;
    LL a = b % p;
    if(a == 0){
      continue;
    }
    LL powmod[24];
    powmod[0] = a;
    for(int i = 1; i < 24; i++){
      powmod[i] = (powmod[i-1]*powmod[i-1]) % p;
    }
    LL cur = n;
    for(LL d = 2; d*d <= cur; d++){
      if(cur % d == 0){
	while(cur % d == 0){
	  cur /= d;
	}
	LL k = n/d;
	LL pm = 1;
	for(int i = 23; i >= 0; i--){
	  if(k >= pow2[i]){
	    k -= pow2[i];
	    pm = (pm *powmod[i]) % p;
	    if(pm == 1) yes = 0;
	  }
	}
      }
    }
    if(cur > 1){
      LL k = n/cur;
      LL pm = 1;
      for(int i = 23; i >= 0; i--){
	if(k >= pow2[i]){
	  k -= pow2[i];
	  pm = (pm *powmod[i]) % p;
	  if(pm == 1) yes = 0;
	}
      }
    }
    if(yes == 1){
      cout << b << endl;
      exit(0);
    }
    
  }
  
  cout << -1 << endl;
  exit(0);
}