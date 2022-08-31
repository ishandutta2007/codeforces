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
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n;
  cin >> n;
  LL a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  int dp[n];
  LL k[n];
  int v[n];
  for(int i = 0; i < n; i++){
    dp[i] = 1;
    v[i] = 0;
    k[i] = a[i];
    while(k[i] % 2 == 0){
      k[i]/=2; v[i]++;
    }
  }
  int ans = 1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < i; j++){
      if(a[j] % k[i] == 0){
	if(i-j > v[i]){
	  dp[i] = max(dp[i], dp[j]+1);
	} else if(i-j == v[i]-v[j]){
	  dp[i] = max(dp[i], dp[j]+1);
	}	
	
      }      
      /*if(a[i] % 2 == 1){
	if(a[j] % a[i] == 0){
	  dp[i] = max(dp[i], dp[j]+1);
	}
      } else {
	if((a[j] - a[i]/2) % a[i] == 0){
	  dp[i] = max(dp[i], dp[j]+1);
	}
      }*/
    }
    ans = max(ans, dp[i]);
    //cout << dp[i] << endl;
  }
  cout << n-ans << endl;
}