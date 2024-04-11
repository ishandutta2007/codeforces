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
main(int argc, char **argv) {
  //int a;
  //scanf("%d", &a);
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  LL n, q, t;
  cin >> n >> q >> t;
  LL a[n];
  for(LL i = 0; i < n; i++){
    cin >> a[i];
  }
  LL greater[n];
  for(LL i = 0; i < n; i++){
    greater[i] = -1;
  }
  for(LL i = 0; i < q; i++){
    LL b, c;
    cin >> b >> c;
    b--;
    c--;
    greater[b] = c;
  }
  LL newa[n];
  for(LL i = 0; i < n; i++) newa[i] = a[i];
  for(LL i = 0; i < n; i++){
    LL m = i;
    while(greater[m] != -1){
      if(greater[m] == i){
	cout << 0 << endl;
	exit(0);
      }
      m = greater[m];
      newa[m] += a[i];
    }    
  }
  for(LL i = 0; i < n; i++){
    if(greater[i] != -1) t -= newa[i];
  }
  if(t < 0){
    cout << 0 << endl;
    exit(0);
  }
  LL dp[2][t+1];
  dp[0][0] = 1;
  for(LL i = 1; i <= t; i++){
    dp[0][i] = 0;
  }
  for(LL i = 1; i <= n; i++){
    for(LL j = 0; j <= t; j++){
      if(j < newa[i-1]){
	dp[i%2][j] = dp[1-i%2][j];
      } else {
	dp[i%2][j] = dp[1-i%2][j] + dp[i%2][j-newa[i-1]];
	dp[i%2][j] %= 1000000007;
      }
      /*for(int k = 0; k*newa[i-1] <= j; k++){
	dp[i % 2][j] += dp[1 - i % 2][j - k*newa[i-1]];
      }*/
    }
  }
  cout << dp[n % 2][t] % 1000000007 << endl;
}