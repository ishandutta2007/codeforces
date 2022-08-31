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
  if(a == 3){
    cout << 5;
    exit(0);
  }
  if(a % 4 == 1){
    for(int i = 1; i < 100; i+= 2){
      if((i*i+1)/2 >= a){
	cout << i << endl;
	exit(0);
      }
    }
  } else if(a % 4 == 0){
    for(int i = 1; i < 100; i+= 2){
      if((i*i-1)/2 >= a){
	cout << i << endl;
	exit(0);
      }
    }   
  } else if(a % 4 == 3){
    for(int i = 1; i < 100; i+= 2){
      if((i*i-3)/2 >= a){
	cout << i << endl;
	exit(0);
      }
    }   
  } else if(a % 4 == 2){
    for(int i = 1; i < 100; i+= 2){
      if((i*i-5)/2 >= a){
	cout << i << endl;
	exit(0);
      }
    }   
  }
  
}