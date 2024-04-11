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
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  FILE *fin = (argc>=2) ? freopen(argv[1], "r", stdin) :
    freopen("input.txt", "r", stdin);
  assert( fin!=NULL );
  DEBUG = (argc>=3) ? atoi(argv[2]) : 0;
  if(!DEBUG) freopen("output.txt", "w", stdout);
  int n;
  cin >> n;
  char s[n+1];
  cin >> s;
  for(int i = 0; i < n/2; i++){
    if(s[i] == 'R' && s[i+n/2] == 'L'){
      cout << i+n/2 + 1 << " " << i + 1<< endl;
    } else {
      cout << i + 1 << " " << i+n/2 + 1 << endl;
    }
  }
  exit(0);
}