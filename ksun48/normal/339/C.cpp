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
  int n;
  int m;
  cin >> n;
  cin >> m;
  int num[11];
  for(int i = 10; i >= 1; i--){
    num[i] = n % 10;
    n /= 10;
  }
  int dp[1001][11][11];
  for(int i = 0; i <= 1000; i++){
    for(int j = 0; j <= 10; j++){
      for(int k = 0; k <= 10; k++){
	dp[i][j][k] = 0;
      }
    }
  }
  for(int i = 1; i <= 10; i++){
    if(num[i] == 1){
      dp[1][i][i] = -1;
    }
  }
  for(int i = 1; i < 1000; i++){
    for(int j = 0; j <= 10; j++){
      for(int k = 0; k <= 10; k++){
	if(dp[i][j][k] != 0){
	  for(int q = 1; q <= 10; q++){
	    if(num[q] == 1 && q != j && q>k){
	      dp[i+1][q][q-k] = j;
	    }
	  }
	}
      }
    }
  }
  
  for(int j = 0; j <= 10; j++){
    for(int k = 0; k <= 10; k++){
      if(dp[m][j][k] != 0){
	cout << "YES\n";
	int j1 = j, k1 = k;
	int wgt[m];
	for(int r = m; r > 0; r--){
	  wgt[r-1] = j1;
	  int a = dp[r][j1][k1];
	  k1 = j1-k1;
	  j1 = a;
	}
	for(int i = 0; i < m; i++){
	  cout << wgt[i] << " ";
	}
	cout << endl;
	exit(0);
      }
    }
  }
  cout << "NO\n";
  exit(0);
}