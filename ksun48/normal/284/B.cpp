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
  int n;
  cin >> n;
  char str[n+10];
  cin >> str;
  int a, f, i;
  a=f=i=0;
  for(int j = 0; j < n; j++){
    if(str[j] == 'A') a++;
    else if(str[j] == 'I') i++;
    else if(str[j] == 'F') f++;
  }
  if(i == 1) cout << 1 << endl;
  else if(i == 0) cout << a << endl;
  else cout << 0 << endl;
  
}