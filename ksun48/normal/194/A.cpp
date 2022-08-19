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
  int n, k;
  cin >> n >> k;
  int a = 0;
  for(int i = n; i > 0; i--){
    if(k >= 3 *(i) ){
      cout << a << endl;
      exit(0);
    } else {
      a++;
      k -= 2;
    }
  }
   cout << a << endl;
   exit(0);
}