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
  int n;
  cin >> n;
  int coin[n+1];
  for(int i = 0; i < n; i++){
    cin >> coin[i+1];
  }
  if(n == 1){
    cout << -1 << endl;
    exit(0);
  }
  if(n % 2 == 0){
    cout << -1 << endl;
    exit(0);
  }
  int nmoves = 0;
  for(int i = n; i > 0; i--){
    if(coin[i] > 0){
      nmoves += coin[i];
      if(i % 2 == 0){
	coin[i+1] -= coin[i];
	coin[i/2] -= coin[i];
	coin[i] = 0;
      } else {
	coin[i-1] -= coin[i];
	coin[(i-1)/2] -= coin[i];
	coin[i] = 0;
      }
    }
  }
  cout << nmoves << endl;
  exit(0);
}