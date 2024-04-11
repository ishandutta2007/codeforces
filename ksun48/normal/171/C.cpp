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
  int carrots = 2;
  cin >> carrots;
  int egg = 1;
  int flour = 1;
  int spread = 100;
  int mix = 0;
  for(int i = 0; i < carrots; i++){
    cin >> spread;
    spread *= flour;
    mix += spread;
    flour += egg;
  }
  cout << mix << endl; 
}