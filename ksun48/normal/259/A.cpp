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
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  
  char chess[9][9];
  for(int i = 0; i < 8; i++){
    cin >> chess[i];
  }
  int yes = 1;
  for(int i = 0; i < 8; i++){
    if(chess[i][0] == 'W' && chess[i][1] == 'B' && 
       chess[i][2] == 'W' && chess[i][3] == 'B' && 
       chess[i][4] == 'W' && chess[i][5] == 'B' && 
       chess[i][6] == 'W' && chess[i][7] == 'B'){
      continue;
    } 
    if(chess[i][0] == 'B' && chess[i][1] == 'W' && 
       chess[i][2] == 'B' && chess[i][3] == 'W' && 
       chess[i][4] == 'B' && chess[i][5] == 'W' && 
       chess[i][6] == 'B' && chess[i][7] == 'W'){
      continue;
    } 
    yes = 0;
  }
  if(yes){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  
}