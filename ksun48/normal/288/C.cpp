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
  //int a;
  //scanf("%d", &a);

  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  LL n;
  cin >> n;
  cout << n*n+n << endl;
  int k = n;
  int stuff[n+1];
  while(k >= 0){
    int i = 0;
    if(k == 0){
      k = -1;
      stuff[0] = 0;
    } else {
      while(i < k){
	i = i*2+1;
      }
      for(int j = k; j >= i-k; j--){
	stuff[j] = i-j;
      }
      k = i-k-1;
    }
  }
  for(int i = 0; i <= n; i++){
    cout << stuff[i] << " ";
  }
  cout << endl;
}