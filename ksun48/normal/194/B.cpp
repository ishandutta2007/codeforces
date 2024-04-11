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
  long long t, k;
  cin >> k;
  for(int i = 0; i < k; i++){
    cin >> t;
    if(t % 2 == 0){
      cout << 4*t + 1 << endl;
    } else if (t % 4 == 3){
      cout << t + 1 << endl;
    } else {
      cout << 2*t + 1 << endl;
    }
  }

}