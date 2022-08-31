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
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf

int DEBUG = 0;
main(int argc, char **argv) {
  FILE *fin = (argc>=2) ? freopen(argv[1], "r", stdin) :
    freopen("input.txt", "r", stdin);
  assert( fin!=NULL );
  DEBUG = (argc>=3) ? atoi(argv[2]) : 0;
  if(!DEBUG) freopen("output.txt", "w", stdout);
  int n;
  cin >> n;
  int freq[5001];
  for(int i = 0; i < 5001; i++){
    freq[i] = 0;
  }
  vector<int> vec[5001];
  for(int i = 0; i < n+n; i++){
    int k;
    cin >> k;
    freq[k]++;
    vec[k].push_back(i);
  }

  for(int i = 0; i < 5001; i++){
    if(freq[i] % 2 == 1){
      cout << -1 << endl;
      exit(0);
    }    
  }
  for(int i = 0; i < 5001; i++){
    for(int j = 0; j < vec[i].size()/2; j++){
      cout << vec[i][2*j] + 1 << " " << vec[i][2*j+1] + 1 << endl;
    }    
  } 
  exit(0);
}