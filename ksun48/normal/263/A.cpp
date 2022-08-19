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
// numeric_limits<int>::max()
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
int Min(int a, int b) {
  return (a < b ? a : b);
}
int Max(int a, int b) {
  return (a > b ? a : b);
}
int Abs(int a) {
  return (a >= 0 ? a : -a);
}
int DEBUG = 0;
main(int argc, char **argv) {
  //int a;
  //scanf("%d", &a);

  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int a;
  int k,l;
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      cin >> a;
      if(a==1){
	k = i;
	l = j;
      }
    }    
  }
  cout << Abs(k-2)+Abs(l-2) << endl;
}