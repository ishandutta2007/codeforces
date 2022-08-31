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
  int x, t, a, b, da, db;
  cin >> x >> t >> a >> b >> da >> db;
  for(int i = 0; i < t; i++){
    for(int j = 0; j < t; j++){
      if(a-i*da+b-j*db == x){
	cout << "YES" << endl;
	exit(0);
      }
    }
  }
  for(int j = 0; j < t; j++){
    if(b-j*db == x){
      cout << "YES" << endl;
      exit(0);
    }
  } 
  for(int j = 0; j < t; j++){
    if(a-j*da == x){
      cout << "YES" << endl;
      exit(0);
    }
  }
  if(0 == x){
    cout << "YES" << endl;
    exit(0);
  }
  cout << "NO" << endl;
}