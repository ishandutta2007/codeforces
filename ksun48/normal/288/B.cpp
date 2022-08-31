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
LL ans[10];
void flip(int k, int n, int *a){
  if(k == n){
    int oyes = 1;
    for(int j = 0; j < n; j++){
      int c = j;
      int yes = 0;
      for(int i = 0; i < 2*n; i++){
	c = a[c];
	if(c == 0){
	  yes = 1;
	  break;
	}
      }
      oyes &= yes;
    }
    if(oyes){
      ans[n]++;
    }
  } else {
    for(int i = 0; i < n; i++){
      a[k] = i;
      flip(k+1,n,a);
    }
  }
}
main(int argc, char **argv) {
  //int a;
  //scanf("%d", &a);

  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n, k;
  cin >> n >> k;
  int a[10];
  for(int i = 0; i < 10; i++){
    ans[i] = 0;
    a[i] = 0;
  }
  flip(0, k, a);
  
  for(int i = k; i < n; i++){
    ans[k] *= (n-k);
    ans[k] %= 1000000007;
  }
  cout << ans[k] << endl;
}