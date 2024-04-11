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
int Max(int a, int b) {
  return (a > b ? a : b);
}
int Abs(int a) {
  return (a >= 0 ? a : -a);
}
int DEBUG = 0;
int pairs[4010][4010];
int lastnum[4010][4010];
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n;
  cin >> n;
  int num[n];
  int mn[n];
  mn[0] = 0;
  for(int i = 0; i < 4010; i++){
    for(int j = 0; j < 4010; j++){
      pairs[i][j] = 0;
      lastnum[i][j] = 0;
    }
  }
  map<int,int> maps;
  for(int i = 0; i < n; i++){
    cin >> num[i];
    if(maps.find(num[i]) == maps.end()){
      maps[num[i]] = maps.size();
    }
    mn[i] = maps[num[i]];
  }
  for(int i = 0; i < n; i++){
    for(int j = 1; j < 4010; j++){
      if(mn[i] != lastnum[mn[i]][j] || mn[i] == j){
	pairs[mn[i]][j]++;
	lastnum[mn[i]][j] = mn[i];
      }
      if(mn[i] != lastnum[j][mn[i]]){
	pairs[j][mn[i]]++;
	lastnum[j][mn[i]] = mn[i];
      }
    }
  }
  int max1 = 0;
  for(int i = 0; i < 4010; i++){
    for(int j = 0; j < 4010; j++){
      max1 = Max(max1, pairs[i][j]);
    }
  }
  cout << max1 << endl;
}