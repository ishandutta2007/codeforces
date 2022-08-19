#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf

int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int a;
  cin >> a;
  int k;
  int num[4];
  for(int i = 0; i < 4; i++){
    num[i] = 0;
  }
  for(int i = 0; i < a; i++){
    cin >> k;
    num[k-1] ++;
  }
  if(num[2] >= num[0]){
    cout << num[3] + num[2] + int((num[1]+1)/2) << endl;
  } else {
    cout << num[3] + num[2] + int((num[1]*2+num[0]-num[2]+3)/4) << endl;
  }
}