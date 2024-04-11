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
  int k;
  cin >> k;
  int d[k];
  vector<int> nums;
  for(int i = 0; i < k; i++) cin >> d[i];
  for(int i = 0; i < k; i++){
    if(d[i] == 0){
      nums.push_back(d[i]);
      break;
    }
  }
  int is1 = 0;
  for(int i = 0; i < k; i++){
    if(d[i] > 0 && d[i] < 10){
      nums.push_back(d[i]);
      is1 = 1;
      break;
    }
  }
  int is2 = 0;
  for(int i = 0; i < k; i++){
    if(d[i] == 100){
      nums.push_back(d[i]);
      break;
    }
  }
  for(int i = 0; i < k; i++){
    if(d[i] % 10 == 0 && d[i] > 0 && d[i] < 100){
      nums.push_back(d[i]);
      is2 = 1;
      break;
    }
  }
  if(is2+is1 == 0){
    for(int i = 0; i < k; i++){
      if(d[i] > 0 && d[i] < 100){
	nums.push_back(d[i]);
	break;
      }
    }
  }
  cout << nums.size() << endl;
  for(int i = 0; i < nums.size(); i++){
    cout << nums[i] << " ";
  }
  cout << endl;
}