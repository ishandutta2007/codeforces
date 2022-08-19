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
  if(k > n){
    cout << -1 << endl;
    return 0;
  }
  if(k == 1 && n > 1){
    cout << -1 << endl;
    return 0;
  }
  if(n == 1){
    cout << 'a' << endl;
    return 0;
  }
  int m = k-2;
  for(int i = 0; i < n-m; i++){
    char c = 'a' + (i % 2);
    cout << c;
  }
  for(int i = 2; i < k; i++){
    char c = 'a' + i;
    cout << c;
  }
  cout << endl;
}