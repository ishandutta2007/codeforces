#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdint.h>
#include <iostream>
#include <set>
#include <math.h>
#define LL int64_t
using namespace std;
int Max(int a, int b) {
  return (a > b ? a : b);
}

int compare_dec (const void * a, const void * b) {
  if ( *(int*)a < *(int*)b ) return 1;
  if ( *(int*)a > *(int*)b ) return -1;
  return 0;
}
main(int argc, char **argv) {
  int n, k;
  cin >> n >> k;
  int a = 0;
  for(int i = 0; i < n; i++){
    int b;
    cin >> b;
    int c = 0;
    while(b > 0){
      if (b % 10 == 4 || b % 10 == 7){
	c++;
      }
      b = (b-b%10)/10;
    }
    if(c <= k) a++;
  }
  cout << a << endl;
  exit(0);
}