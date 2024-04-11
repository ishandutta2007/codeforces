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
  int n;
  cin >> n;
  int l1 = 0;
  int d1 = 0;
  int l2 = 0;
  int d2 = 0;
  for(int i = 0; i < n; i++){
    int a, b, c;
    cin >> a >> b >> c;
    if(a == 1){
      l1 += b;
      d1 += c;
    } else {
      l2 += b; 
      d2 += c;
    }
  }
  if(l1 >= d1){
    cout << "LIVE" << endl;
  } else {
    cout << "DEAD" << endl;
  }
  if(l2 >= d2){
    cout << "LIVE" << endl;
  } else {
    cout << "DEAD" << endl;
  }
}