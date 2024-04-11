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
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n;
  cin >> n;
  
  deque<int> stuff;
  for(int i = 0; i < n; i++){
    stuff.push_back(i+1);
  }
  for(int i = 2; i <= n; i++){
    stuff.push_back(stuff[i* int((n-1)/i)]);
    for(int j = int((n-1)/i); j > 0; j--){
      stuff[j*i] = stuff[(j-1)*i];
    }
    stuff.pop_front();
  }
  for(int i = 0; i < n; i++){
    cout << stuff[i] << " ";
  }
  cout << endl;
}