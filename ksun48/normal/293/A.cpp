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
char char1[2000100];
char char2[2000100];
int stuff[2000100];
main(int argc, char **argv) {
  //int a;
  //scanf("%d", &a);

  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n;
  cin >> n;
  cin >> char1 >> char2;
  int diff = 0;
  for(int i = 0; i < 2*n; i++){
    stuff[i] = (char1[i] - '0') + (char2[i] - '0');    
    diff += (char1[i] - char2[i]);
  }
  sort(stuff, stuff + 2*n);
  for(int i = 2*n-1; i >= 0; i--){
    if(i % 2) diff += stuff[i];
    else diff -= stuff[i];
  }
  if(diff > 0){
    cout << "First" << endl;
  } else if(diff < 0){
    cout << "Second " << endl;
  } else {
    cout << "Draw" << endl;
  }
  
}