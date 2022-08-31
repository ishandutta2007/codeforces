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
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  char num[100010];
  cin >> num;
  int len = strlen(num);
  int first0 = 0;
  for(int i = 0; i < len; i++){
    if(num[i] == '0'){
      first0 = i;
      break;
    }
  }
  for(int i = 0; i < len; i++){
    if(i != first0) cout << num[i];
  }
  cout << endl;
}