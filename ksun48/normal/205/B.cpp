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

int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n;
  cin >> n;
  LL numbers[n];
  for(int i = 0; i < n; i++){
    cin >> numbers[i];
  }
  LL diff[n-1];
  for(int i = 0; i < n-1; i++){
    diff[i] = numbers[i+1]-numbers[i];
  }
  LL sum = 0;
  for(int i = 0; i < n-1; i++){
    if(diff[i] < 0){
      sum -= diff[i];
    }
  }
  cout << sum << endl;
}