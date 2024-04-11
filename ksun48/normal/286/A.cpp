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
  
  int n;
  cin >> n;
  if(n == 1){
    cout << 1 << endl;
    exit(0);
  } else if(n % 4== 2 || n % 4 == 3){
    cout << -1 << endl;
  } else if(n % 4== 1){
    int p[n+1];
    p[(n+1)/2] = (n+1)/2;
    for(int i = 0; i*4 < n-1; i++){
      p[2*i+1] = 2*i+2;
      p[2*i+2] = n-2*i;
      p[n-2*i] = n-2*i-1;
      p[n-2*i-1] = 2*i+1;
      //cout << 2*i+2 << " " << n - 2*i << " " << n-2*i-1 << " " << 2*i+1 << endl;
    }
    for(int i = 1; i <= n; i++){
      cout << p[i] << " ";
    }
    cout << endl;
  } else {
    int p[n+1];
    for(int i = 0; i*4 < n; i++){
      p[2*i+1] = 2*i+2;
      p[2*i+2] = n-2*i;
      p[n-2*i] = n-2*i-1;
      p[n-2*i-1] = 2*i+1;
    }
    for(int i = 1; i <= n; i++){
      cout << p[i] << " ";
    }
    cout << endl;
  }
  
}