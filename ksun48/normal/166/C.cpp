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
int compare_inc (const void * a, const void * b) {
  if ( *(int*)a > *(int*)b ) return 1;
  if ( *(int*)a < *(int*)b ) return -1;
  return 0;
}
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n, x;
  cin >> n >> x;
  int ifnum = 0;
  int numbers[n+1];
  for(int i = 0; i < n; i++){
    cin >> numbers[i];
    if(numbers[i] == x){
      ifnum = 1;
    }
  }
  int num = 0;
  if(ifnum == 0){
    n++;
    num++;
    numbers[n-1] = x;
  }
  qsort(numbers, n, sizeof(int), compare_inc);
  int min, max;
  for(int i = 0; i < n; i++){
    if(numbers[i] == x){
      min = i;
      break;
    }
  }  
  for(int i = n-1; i >= 0; i--){
    if(numbers[i] == x){
      max = i;
      break;
    }
  }
  //cout << min << endl << max << endl;
  if(max >= int((n-1)/2) && min <= int((n-1)/2)){
    cout << num << endl;
  } else if(min > int((n-1)/2)){
    cout << 2*min+1-n + num << endl;
  } else {
    cout << (n-2*max-2) + num << endl;
  }
}