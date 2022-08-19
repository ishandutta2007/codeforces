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
  char str1[1000090];
  char str2[1000090];
  cin >> str1 >> str2;
  if(strlen(str1) != strlen(str2)){
    cout << "NO" << endl;
  } else {
    int i = strlen(str1);
    int a = 0, b = 0;
    for(int j = 0; j < i; j++){
      if(str1[j] == '1') a = 1;
      if(str2[j] == '1') b = 1;
    }
    if(a == b) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  
}