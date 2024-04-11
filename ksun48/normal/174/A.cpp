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
  double b;
  cin >> n >> b;
  double a[n];
  double sum = b;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    sum += a[i];
  }
  double frac = sum/n;
  for(int i = 0; i < n; i++){
    if(frac < a[i]){
      cout << -1 << endl;
      exit(0);
    }
  }
  for(int i = 0; i < n; i++){
    printf("%.10lf\n", frac-a[i]);
  }
}