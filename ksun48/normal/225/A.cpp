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
  int n, x;
  cin >> n >> x;
  int a[n], b[n];
  for(int i = 0; i < n; i++){
    cin >> a[i] >> b[i];
  }
  for(int i = 0; i < n; i++){
    if(a[i] == b[i]){
      cout << "NO" << endl;
      exit(0);
    }
    if(a[i] + b[i] == 7){
      cout << "NO" << endl;
      exit(0);
    }
    if(x == a[i]){
      cout << "NO" << endl;
      exit(0);
    }
    if(x == b[i]){
      cout << "NO" << endl;
      exit(0);
    }
    if(x == 7- a[i]){
      cout << "NO" << endl;
      exit(0);
    }
    if(x == 7 - b[i]){
      cout << "NO" << endl;
      exit(0);
    }
    
  }
  cout << "YES" << endl;
  exit(0);
}