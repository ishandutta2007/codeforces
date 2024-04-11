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
int nways(int k){
  
}
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n, m;
  cin >> n >> m;
  int a[n];
  for(int i = 0; i < n; i++) a[i] = 0;
  int d = n;
  for(int i = 0; i < m; i++){
    int k;
    cin >> k;
    a[k-1]++;
    d--;
  }				       
  //cout << d << endl;
  LL c[1010][1010];
  for(int i = 0; i < 1010; i++){
    c[i][0] = 1;
    c[i][i] = 1;
  }
  for(int i = 1; i < 1010; i++){
    for(int j = 1; j < 1010; j++){
      c[i][j] = (c[i-1][j] + c[i-1][j-1]) % 1000000007;
    }
  }
  int last = -1;
  LL ans = 1;
  for(int i = 0; i < n; i++){
    if(a[i] == 1){
      if(last == -1){
	
      } else {
	if(i - last > 1){
	  for(int j = 2; j < i-last; j++){
	    ans = (ans * 2) % 1000000007;
	  }
	}
      }
      ans = (ans * c[d][i-last-1]) % 1000000007;
      //cout << i-last-1 << endl;
      d -= (i-last-1);
      last = i;
    }
  }
  cout << ans << endl;
}