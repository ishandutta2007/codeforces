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
int Max(int a, int b) {
  return (a > b ? a : b);
}
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int max = -1;
  int maxn = -1;
  int n;
  cin >> n;
  int l[n];
  int r[n];
  
  for(int i = 0; i < n; i++){
    cin >> l[i] >> r[i];
    if(max < r[i]-l[i]){
      max = r[i]-l[i];
      maxn = i;
    }
  }
  for(int i = 0; i < n; i++){
    if(r[maxn] < r[i] || l[i] < l[maxn]){
      cout << -1 << endl;
      exit(0);
    }
  }
  cout << maxn + 1 << endl;
}