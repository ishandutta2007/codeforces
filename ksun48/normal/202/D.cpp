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
int Abs(int a) {
  return (a >= 0 ? a : -a);
}
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n, m;
  cin >> n >> m;
  LL rare[n][m];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> rare[i][j];
    }
  }
  LL rowr[n];
  LL colr[m];
  for(int i = 0; i < n; i++){
    rowr[i] = 0;
  }
  for(int i = 0; i < m; i++){
    colr[i] = 0;
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      rowr[i] += rare[i][j];
      colr[j] += rare[i][j];
    }
  }
  LL maxi = 1000000000000000000;
  int maxin = -1;
  for(int i = 0; i < n; i++){
    LL time = 0;
    for(int j = 0; j < n; j++){
      time += rowr[j]*(LL)(2*i-2*j-1)*(LL)(2*i-2*j-1);  
    }
    if(time < maxi){
      maxi = time;
      maxin = i;
    }
  } 

  LL maxj = 1000000000000000000;
  int maxjn = -1;
  for(int i = 0; i < m; i++){
    LL time = 0;
    for(int j = 0; j < m; j++){
      time += colr[j]*(LL)(2*i-2*j-1)*(LL)(2*i-2*j-1);  
    }
    if(time < maxj){
      maxj = time;
      maxjn = i;
    }
  }
  cout << 4*(maxj+maxi) << endl;
  cout << maxin << " " << maxjn<< endl;;
}