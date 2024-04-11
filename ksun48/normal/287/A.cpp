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
  char stuff[5][5];
  for(int i = 0; i < 4; i++){
    cin >> stuff[i];
  }
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      int k = 0;
      if(stuff[i][j] == '.') k++;
      if(stuff[i][j+1] == '.') k++;
      if(stuff[i+1][j] == '.') k++;
      if(stuff[i+1][j+1] == '.') k++;
      if(k != 2){
	cout << "YES" << endl;
	exit(0);
      }
    }
  }
  cout << "NO" << endl;
  exit(0);
}