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
  int array[1000];
  for(int i = 0; i < 1000; i++){
    array[i] = 0;
  }
  int month[13] = {0,31,59,90,120,151,181,212,243,273,304,334,365};
  for(int i = 0; i < n; i++){
    int m, d, p, t;
    cin >> m >> d >> p >> t;
    int time = month[m-1]+d;
    //cout << time << endl;
    for(int j = 1; j <= t; j++){
      array[time-j+500] += p;
    }
  }
  int max = 0;
  for(int i = 0; i < 1000; i++){
    if(max < array[i]){
      max = array[i];
    }
  }
  cout << max << endl;
}