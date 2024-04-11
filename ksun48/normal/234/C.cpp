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

int Min(int a, int b) {
  return (a < b ? a : b);
}
int Max(int a, int b) {
  return (a > b ? a : b);
}
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  FILE *fin = (argc>=2) ? freopen(argv[1], "r", stdin) :
    freopen("input.txt", "r", stdin);
  assert( fin!=NULL );
  DEBUG = (argc>=3) ? atoi(argv[2]) : 0;
  if(!DEBUG) freopen("output.txt", "w", stdout);
  int n;
  cin >> n;
  int w[n];
  for(int i = 0; i < n; i++){
    cin >> w[i];
  }

  int count = 0;
  if(w[0] >= 0){
    count++;
  }
  for(int i = 1; i < n; i++){
    if(w[i] <= 0){
      count++;
    }
  }
  int minc = count;
  //cout << count << endl;
  for(int i = 1; i < n-1; i++){
    if(w[i] > 0){
      count += 1;
    } else if (w[i] == 0){
      
    } else if (w[i] < 0){
      count -= 1;
    }
    minc = Min(minc, count);
    //cout << count << endl;
  }
  cout << minc << endl;;
}