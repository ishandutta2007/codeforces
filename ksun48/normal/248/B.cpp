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
  if(n == 1){
    cout << -1 << endl;
    exit(0);
  }
  if(n == 2){
    cout << -1 << endl;
    exit(0);
  }
  if(n == 3){
    cout << "210" << endl;
    exit(0);
  }
  if(n % 6 == 4){
    cout << "10";
    for(int i = 0; i < (n-4)/6; i++){
      cout << "000000";
    }
    cout << "50" << endl;
  }
  if(n % 6 == 5){
    cout << "100";
    for(int i = 0; i < (n-5)/6; i++){
      cout << "000000";
    }
    cout << "80" << endl;
  }
  if(n % 6 == 0){
    cout << "100";
    for(int i = 1; i < n/6; i++){
      cout << "000000";
    }
    cout << "170" << endl;
  }
  if(n % 6 == 1){
    cout << "10000";
    for(int i = 1; i < (n-1)/6; i++){
      cout << "000000";
    }
    cout << "20" << endl;
  }
  if(n % 6 == 2){
    cout << "10000";
    for(int i = 1; i < (n-2)/6; i++){
      cout << "000000";
    }
    cout << "200" << endl;
  }
  if(n % 6 == 3){
    cout << "100000";
    for(int i = 1; i < (n-3)/6; i++){
      cout << "000000";
    }
    cout << "110" << endl;
  }
  exit(0);
}