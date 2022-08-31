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
  int a;
  scanf("%d", &a);
  if(a == 1){
    //tc2
    cout << 2 << endl;
  } else if (a == 2){
    //tc4
    cout << 3 << endl;
  } else if (a == 3){
    //tc1
    cout << 1 << endl;
  } else if (a == 4){
    //tc3
    cout << 2 << endl;
  } else if (a == 5){
    cout << 1 << endl;
  }
}