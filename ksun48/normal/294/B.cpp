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
  int t[n], w[n];
  int one[n];
  int no = 0;
  int two[n];
  int nt = 0;
  for(int i = 0; i < n; i++){
    cin >> t[i] >> w[i];
    if(t[i] == 1){
      one[no++] = w[i];
    } else {
      two[nt++]= w[i];
    }
  }
  sort(one, one + no);
  sort(two, two + nt);
  int a = no;
  int b = nt;
  int sum1[a+1];
  int sum2[b+1];
  sum2[0] = sum1[0] = 0;
  for(int i = 1; i <= a; i++){
    sum1[i] = sum1[i-1] + one[i-1];
  }
  for(int i = 1; i <= b; i++){
    sum2[i] = sum2[i-1] + two[i-1];
  }
  int ans = 100000;
  for(int i = 0; i <= a; i++){
    for(int j = 0; j <= b; j++){
      int len = (a - i) + 2*(b-j);
      if(len >= sum1[i] + sum2[j]){
	ans = min(ans, len);
      }
    }
  } 
  cout << ans << endl;
  
}