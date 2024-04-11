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
int dp[301][301][301];

main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n;
  cin >> n;
  int a[3];
  a[0] = a[1] = a[2] = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  if(n == 2){
    for(int i = 0; i < 300; i++){
      for(int j = 0; j < 300; j++){
	for(int k = 0; k < 300; k++){
	  if(dp[i][j][k] == 0){
	    for(int a = i+1; a < 300; a++){
	      dp[a][j][k] = 1;
	    }
	    for(int a = j+1; a < 300; a++){
	      dp[i][a][k] = 1;
	    }
	    for(int a = k+1; a < 300; a++){
	      dp[i][j][a] = 1;
	    }
	    for(int a = 1; a+i < 300 && a+j < 300 && a + k < 300; a++){
	      dp[i+a][j+a][k+a] = 1;
	    }
	    if(i == 0){
	      for(int a = 1; a+i < 300 && a+j < 300 && a + k < 300; a++){
		dp[0][j+a][k+a] = 1;
	      }
	    }
	    if(j == 0){
	      for(int a = 1; a+i < 300 && a+j < 300 && a + k < 300; a++){
		dp[i+a][0][k+a] = 1;
	      }
	    }
	    if(k == 0){
	      for(int a = 1; a+i < 300 && a+j < 300 && a + k < 300; a++){
		dp[i+a][j+a][0] = 1;
	      }
	    }
	  }
	}
      }
    }
    if(dp[a[0]][a[1]][0]){
      cout << "BitLGM" << endl;
    } else {
      cout << "BitAryo" << endl;
    }
    exit(0);
  }
  for(int i = 0; i < 300; i++){
    for(int j = 0; j < 300; j++){
      for(int k = 0; k < 300; k++){
	dp[0][0][0] = 0;
      }      
    }
  }
  //cout << ((184 ^ 222) ^ 102 )<< endl;
  for(int i = 0; i < 300; i++){
    for(int j = 0; j < 300; j++){
      for(int k = 0; k < 300; k++){
	if(dp[i][j][k] == 0){
	  for(int a = i+1; a < 300; a++){
	    dp[a][j][k] = 1;
	  }
	  for(int a = j+1; a < 300; a++){
	    dp[i][a][k] = 1;
	  }
	  for(int a = k+1; a < 300; a++){
	    dp[i][j][a] = 1;
	  }
	  for(int a = 1; a+i < 300 && a+j < 300 && a + k < 300; a++){
	    dp[i+a][j+a][k+a] = 1;
	  }
	  /*if(i == 0){
	    for(int a = 1; a+i < 300 && a+j < 300 && a + k < 300; a++){
	      dp[0][j+a][k+a] = 1;
	    }
	  }
	  if(j == 0){
	    for(int a = 1; a+i < 300 && a+j < 300 && a + k < 300; a++){
	      dp[i+a][0][k+a] = 1;
	    }
	  }
	  if(k == 0){
	    for(int a = 1; a+i < 300 && a+j < 300 && a + k < 300; a++){
	      dp[i+a][j+a][0] = 1;
	    }
	    }*/
	}
      }
    }
  }
  //cout << dp[155][193][73] << endl;
  if(dp[a[0]][a[1]][a[2]]){
    cout << "BitLGM" << endl;
  } else {
    cout << "BitAryo" << endl;
  }
}