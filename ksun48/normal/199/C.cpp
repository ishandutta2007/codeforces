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
  LL k, b, n, t;
  cin >> k >> b >> n >> t;
  LL a = 1;
  LL i = 0;
  while(a < t){
    a = a*k + b;
    i++;
  }
  //cout << i << endl;
  if(i>n){
    cout << 0 << endl;
  } else if (a == t){
    cout << n-i << endl;
  } else {
    cout << n-i+1 << endl;
  }
}