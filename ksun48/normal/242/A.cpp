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
  int n = 0;
  int x,y,a,b;
  cin >> x >> y >> a >> b;
  for(int i = a; i <= x; i++){
    for(int j = b; j <= y; j++){
      if(i > j){
	n++;
      }
    }
  }
  cout << n << endl;
  cin >> x >> y >> a >> b;
  for(int i = a; i <= x; i++){
    for(int j = b; j <= y; j++){
      if(i > j){
	cout << i << " " << j << endl;
      }
    }
  }
}