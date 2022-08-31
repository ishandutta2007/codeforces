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
#define reorder(a, b) if(a>b) swap(a,b);
int gcd(int a, int b) { 
  reorder(a, b);
  while(a != 0) { 
    b = b % a;
    reorder(a, b);
  }
  return b;
}
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
//n 1 p 2 tie 0
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n;
  cin >> n;
  char str1[1010];
  char str2[1010];
  cin >> str1 >> str2;
  int l1 = strlen(str1);
  int l2 = strlen(str2);
  int lcm = l1*l2/gcd(l1, l2);
  int ns = 0;
  int ps = 0;
  for(int i = 0; i < lcm; i++){
    if(str1[i%l1] == 'R' && str2[i%l2] == 'S'){
      ps++;
    } else if(str1[i%l1] == 'S' && str2[i%l2] == 'P'){
      ps++;
    } else if(str1[i%l1] == 'P' && str2[i%l2] == 'R'){
      ps++;
    } else if(str1[i%l1] == 'R' && str2[i%l2] == 'P'){
      ns++;
    } else if(str1[i%l1] == 'P' && str2[i%l2] == 'S'){
      ns++;
    } else if(str1[i%l1] == 'S' && str2[i%l2] == 'R'){
      ns++;
    }
  }
  ns *= int(n/lcm);
  ps *= int(n/lcm);
  for(int i = 0; i < n-lcm*int(n/lcm); i++){
    if(str1[i%l1] == 'R' && str2[i%l2] == 'S'){
      ps++;
    } else if(str1[i%l1] == 'S' && str2[i%l2] == 'P'){
      ps++;
    } else if(str1[i%l1] == 'P' && str2[i%l2] == 'R'){
      ps++;
    } else if(str1[i%l1] == 'R' && str2[i%l2] == 'P'){
      ns++;
    } else if(str1[i%l1] == 'P' && str2[i%l2] == 'S'){
      ns++;
    } else if(str1[i%l1] == 'S' && str2[i%l2] == 'R'){
      ns++;
    }    
  }
  cout << ns << " " << ps << endl;
}