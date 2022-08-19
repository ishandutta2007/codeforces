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
  int n, m;
  cin >> n;
  
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  cin >> m;
  int x[m], y[m];
  for(int i = 0; i < m; i++){
    cin >> x[i] >> y[i];
    x[i]--;
    if(x[i] > 0){
      a[x[i]-1] += y[i]-1;
    }
    if(x[i] < n-1){
      a[x[i]+1] += a[x[i]]-y[i];
    }
    a[x[i]] = 0;
  }
  for(int i = 0; i < n; i++){
    cout << a[i] << endl;
  }
}