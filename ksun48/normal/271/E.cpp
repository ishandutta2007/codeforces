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
  while(1){
    if(b > a){
      LL c = a;
      a = b;
      b = c;
    }
    a = a % b;
    if(a == 0) return b;
  }
  
}
main(int argc, char **argv) {
  //int a;
  //scanf("%d", &a);

  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  LL n, m;
  cin >> n >> m;
  LL a[n];
  LL god;
  for(LL i = 0; i < n; i++){
    cin >> a[i];
    a[i]--;
    while(a[i] % 2 == 0) a[i] = a[i]/2;
    if(i == 0){
      god = a[i];
    } else {
      god = gcd(god, a[i]);
    }
  }
  LL ans = 0;
  for(LL d = 1; d*d <= god; d++){
    if(god % d != 0) continue;
    LL gd = d;
    while(gd < m){
      ans += (m-gd);
      gd *= 2;
    }
    if(d*d != god){
      LL gd1 = god/d;
      while(gd1 < m){
	ans += (m-gd1);
	gd1 *= 2;
      }
    }
  }
  cout << ans << endl;
}