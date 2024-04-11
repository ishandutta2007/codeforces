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
  int n, k;
  cin >> n >> k;
  if(n < 3*k){
    cout << -1 << endl;
    exit(0);
  }
  for(int i = 0; i < k; i++){
    cout << i+1 << " " << i+1 << " ";
  }
  for(int i = 0; i < k; i++){
    cout << i+1 << " ";
  }
  for(int i = 0; i < n-3*k; i++) cout << 1 << " ";
  cout << endl;
}