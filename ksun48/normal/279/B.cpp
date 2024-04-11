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
  int n, t;
  cin >> n >> t;
  int book[n];
  for(int i = 0; i < n; i++) cin >> book[i];
  int j = 0;
  int sum = 0;
  int ans = 0;
  for(int i = 0; i < n; i++){
    while(j < n && (sum + book[j] <= t)){
      sum += book[j];
      j++;
      //cout << "ZZZ" << sum << endl;
    }
    //cout << j << endl;
    ans = max(ans, j-i);
    if(i == j){
      j++;
    } else {
      sum -= book[i];
    }
    //cout << sum << endl;
  }  
  cout << ans << endl;
}