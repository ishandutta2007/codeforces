#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
#include <set>
#include <queue>
#include <complex>
#include <deque>
#include <map>
using namespace std;
#define LL int64_t // 64-bit long long int, use %Ixx64d for scan and printf

int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  char strs[5010], strt[5010];
  cin >> strs >> strt;
  int s = strlen(strs);
  int t = strlen(strt);
  int dp[s+1][2];
  for(int i = 0; i <= s; i++){
    dp[i][0] = 0;
  }
  for(int j = 1; j <= t; j++){
    dp[0][j%2] = 0;
    for(int i = 1; i <= s; i++){
      if(strs[i-1] == strt[j-1]){
	dp[i][j%2] = (1 + dp[i-1][(j-1)%2] + dp[i][(j-1)%2]) % 1000000007;
      } else {
	dp[i][j%2] = dp[i][(j-1)%2];
      }
    }
  }
  int sum = 0;
  for(int i = 0; i <= s; i++){
    sum += dp[i][t%2];
    sum = sum % 1000000007;
  }
  cout << sum << endl;
}