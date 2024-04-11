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
int Abs(int a) {
  return (a >= 0 ? a : -a);
}
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n, k;
  cin >> n;
  int sum = 0;
  for(int i = 0; i < n; i++){
    cin >> k;
    sum += k;
  }
  if(sum % n == 0){
    cout << n << endl;
  } else {
    cout << n-1 << endl;
  }
}