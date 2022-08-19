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
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf

int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  FILE *fin = (argc>=2) ? freopen(argv[1], "r", stdin) :
    freopen("input.txt", "r", stdin);
  assert( fin!=NULL );
  DEBUG = (argc>=3) ? atoi(argv[2]) : 0;
  if(!DEBUG) freopen("output.txt", "w", stdout);   

  int n, m;
  cin >> n >> m;
  if(n >= m){
    for(int i = 0; i < m; i++){
      cout << "BG";
    }
    for(int i = 0; i < n-m; i++){
      cout << 'B';
    }
    cout << endl;
  } else {
    for(int i = 0; i < n; i++){
      cout << "GB";
    }
    for(int i = 0; i < m-n; i++){
      cout << 'G';
    }
    cout << endl;
  }
  exit(0);

}