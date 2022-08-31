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
  char str[20];
  cin >> str;
  //cout << str << endl;
  char max = 'a';
  int k = 0;
  
  for(int i = 0; i < strlen(str); i++){
    if(str[i] == max){
      k++;
    } else if(str[i] > max){
      max = str[i];
      k = 1;
    }
  }
  for(int i = 0; i < k; i++){
    cout << max;
  }
  cout << endl;
}