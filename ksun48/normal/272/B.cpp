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
  LL k = 0;
  int tmp;
  cin >> n;
  int f[n];
  LL freq[1000];
  for(int i = 0; i < 1000; i++) freq[i] = 0;
  for(int i = 0; i < n; i++){
    cin >> tmp;
    f[i] = 0;
    while(tmp > 0){
      f[i] += tmp % 2;
      tmp = (tmp - tmp % 2)/2;
    }
    freq[f[i]]++;
  }
  for(int i = 0; i < 1000; i++){
    k += freq[i]*(freq[i]-1)/2;
  }
  cout << k << endl;
}