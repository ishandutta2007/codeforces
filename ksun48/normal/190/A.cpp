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
  int n, m;
  cin >> n >> m;
  if(n == 0 && m == 0){
    cout << "0 0" << endl;
  } else if(n == 0){
    cout << "Impossible" << endl;
  } else {
    if(n > m){
      cout << n << " ";
    } else {
      cout << m << " ";
    }
    if(m > 0){
      cout << n + m - 1 << endl;
    } else {
      cout << n << endl;
    }
  }

}