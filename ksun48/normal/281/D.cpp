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
  int array[n];
  for(int i = 0; i < n; i++){
    cin >> array[i];
  }
  int ans = 0;
  for(int mm = 0; mm < 1; mm++){
    int firstmore[n+1];
    for(int i = n-1; i >= 0; i--){
      firstmore[i] = i + 1;
      while(firstmore[i] < n){
	if(array[firstmore[i]] > array[i]){
	  break;
	}
	firstmore[i] = firstmore[firstmore[i]];
      }
      if(firstmore[i] < n) ans = max(ans, array[i] ^ array[firstmore[i]]);
    }
  }
  int newans[n];
  for(int i = 0; i < n; i++){
    newans[n-1-i] = array[i];
  }
  for(int i = 0; i < n; i++) array[i] = newans[i];
  for(int mm = 0; mm < 1; mm++){
    int firstmore[n+1];
    for(int i = n-1; i >= 0; i--){
      firstmore[i] = i + 1;
      while(firstmore[i] < n){
	if(array[firstmore[i]] > array[i]){
	  break;
	}
	firstmore[i] = firstmore[firstmore[i]];
      }
      if(firstmore[i] < n) ans = max(ans, array[i] ^ array[firstmore[i]]);
    }
  }
  cout << ans << endl;
}