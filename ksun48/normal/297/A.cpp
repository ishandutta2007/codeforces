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
  char a[2000];
  char b[2000];
  cin >> a >> b;
  int a1 = 0;
  int b1 = 0;
  int len1 = strlen(a);
  int len2 = strlen(b);
  for(int i = 0; i < len1; i++){
    if(a[i] == '1'){
      a1++;
    }
  }
  if(a1 % 2 == 1) a1++;
  for(int i = 0; i < len2; i++){
    if(b[i] == '1'){
      b1++;
    }
  }
  if(a1 >= b1){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}