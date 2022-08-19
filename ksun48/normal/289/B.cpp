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
  int n, m, d;
  cin >> n >> m >> d;
  n = n*m;
  int stuff[n];
  for(int i = 0; i < n; i++){
    cin >> stuff[i];
  }
  int minimum = 109182577;
  for(int k = 0; k <= 10000; k++){
    int yes = 1;
    int moves = 0;
    for(int i = 0; i < n; i++){
      if((stuff[i] - (k % d) + d) % d != 0){
	yes = 0;
	break;
      } else if(stuff[i] > k){
	moves += (stuff[i]-k)/d;
      } else {
	moves += (k - stuff[i])/d;
      }
    }
    if(yes){
      minimum = min(minimum, moves);
    }
  }
  if(minimum == 109182577){
    cout << -1 << endl;
  } else {
    cout << minimum << endl;
  }
}