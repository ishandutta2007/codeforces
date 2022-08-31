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
  char str[150];
  cin >> str;
  int len = strlen(str);
  for(int i = 0; i < len; i++){
    if(str[i] >= 'A' && str[i] <= 'Z'){
      str[i] -= ('A'-'a');
    }
    if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'y'){

    } else {
      cout << ".";
      cout << str[i];
    }
    
  }
  cout << endl;
}