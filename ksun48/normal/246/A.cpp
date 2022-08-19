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
  if(n == 1 || n == 2){
    cout << -1 << endl;
  } else {
    for(int i = n; i >= 1; i--){
      cout << i << " ";
    }
    cout << endl;
    exit(0);
  }
}