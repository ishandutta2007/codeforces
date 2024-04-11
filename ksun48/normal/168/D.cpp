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
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
double dp[220][220][2];
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n, l, c;
  cin >> n >> l >> c;
  double p[n];
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> p[i];
    p[i] = p[i]/100;
  }
  for(int i = 0; i < n; i++){
    cin >> a[i];
    a[i]++;
  }
  // cout << "pwn\n" ;
  for(int j = 0; j < 220; j++){
    for(int k = 0; k < 220; k++){
      dp[j][k][0] = 0;
    }
  }
  dp[0][0][0] = 1.0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 219; j++){
      for(int k = 0; k < 220; k++){
	dp[j][k][1-i%2] = (1.0-p[i])*dp[j][k][i%2];
      }
    }
    //cout << "i= " << i << endl;
    for(int j = 0; j < 219; j++){
      for(int k = 0; k < 220; k++){
	//cout << "i= " << i << " j= " << j << " k= " << k << endl;
	if(a[i] + k >= 220){
	  dp[j+1][219][1-i%2] += p[i]*dp[j][k][i%2];
	} else {
	  dp[j+1][a[i]+k][1-i%2] += p[i]*dp[j][k][i%2];
	}
      }
    }
  }
  double probability = 0;
  for(int j = l; j < 219; j++){
    for(int k = 0; k < 220; k++){
      if(k+c >= j){
	probability += dp[j][k][n%2];
      }
      if(dp[j][k][n%2] > 0){
	//cout << j << " " << k << " " << dp[j][k][n%2] << endl;
      }
    }
  }
  printf("%.10lf\n", probability);
  exit(0);
}