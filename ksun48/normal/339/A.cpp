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
  char str[200];
  cin >> str;
  int len = strlen(str);
  int a[4];
  a[1] = a[2]=a[3] = 0;
  for(int i = 0; i < len; i += 2){
    if(str[i] == '1'){
      a[1]++;
    } else if(str[i] == '2'){
      a[2]++;
    } else if(str[i] == '3'){
      a[3]++;
    }
  }
  for(int i = 0; i < a[1]; i++){
    cout << 1;
    if(i < a[1] - 1 || a[2] > 0 || a[3] > 0){
      cout << '+';
    }
  }
  for(int i = 0; i < a[2]; i++){
    cout << 2;
    if(i < a[2] - 1 || a[3] > 0){
      cout << '+';
    }
  }
  for(int i = 0; i < a[3]; i++){
    cout << 3;
    if(i < a[3] - 1){
      cout << '+';
    }
  }
  cout << endl;
}