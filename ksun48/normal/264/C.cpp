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
LL Max(LL a, LL b) {
  return (a > b ? a : b);
}
int Abs(int a) {
  return (a >= 0 ? a : -a);
}
int DEBUG = 0;
main(int argc, char **argv) {
  //int a;
  //scanf("%d", &a);

  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n, q;
  cin >> n >> q;
  LL v[n];
  int c[n];
  for(int i = 0; i < n; i++) cin >> v[i];
  for(int i = 0; i < n; i++){ cin >> c[i]; c[i]--; }
  for(int jj = 0; jj < q; jj++){
    LL a, b;
    cin >> a >> b;
    LL max1 = 0;
    int max1c = -1;
    LL max2 = 0;
    int max2c = -1;
    LL dp[110000];
    for(int i = 0; i < 110000; i++){
      dp[i] = -10010010010010010;
    }
    for(int i = 0; i < n; i++){
      //dp[c[i]] = Max(dp[c[i]], Max(dp[c[i]] +a*v[i], a*v[i]));    
      if(dp[c[i]] != -10010010010010010) {
	dp[c[i]] += Max(a*v[i], 0);
      }
      if(max1c == c[i]){
	dp[c[i]] = Max(dp[c[i]], max2 + b*v[i]);
      } else {
	dp[c[i]] = Max(dp[c[i]], max1 + b*v[i]);
      }
      if(max1c == c[i]){
	max1 = Max(max1, dp[c[i]]);
      } else if(max2c == c[i]){
	if(dp[c[i]] > max1){
	  max2 = max1;
	  max2c = max1c;
	  max1 = dp[c[i]];
	  max1c = c[i];
	} else if( dp[c[i]] > max2){
	  max2 = dp[c[i]];
	}
      } else {
	if(dp[c[i]] > max1){
	  max2 = max1;
	  max2c = max1c;
	  max1 = dp[c[i]];
	  max1c = c[i];
	} else if(dp[c[i]] > max2){
	  max2 = dp[c[i]];
	  max2c = c[i];
	}
      }
    }
    cout << max1 << endl;
  }
}