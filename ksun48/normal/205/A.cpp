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
  int city[n];
  for(int i = 0; i < n; i++){
    cin >> city[i];
  }
  int min = 1100000000;
  int idx = -1;
  for(int i = 0; i < n; i++){
    if(city[i] == min){
      idx = -1;
    } else if (city[i] < min){
      min = city[i];
      idx = i;
    }
  }
  if(idx >= 0){
    cout << idx + 1 << endl;
  } else {
    cout << "Still Rozdil" << endl;
  }
}