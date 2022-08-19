#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <iostream>
#include <set>
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
  char hello[210];
  cin >> hello;
  int len = strlen(hello);
  int wub = 0;
  int start = 0;
  int j = 0;
  while (j < len){
    if(hello[j] == 'W' && hello[j+1] == 'U' && hello[j+2] == 'B'){
      if(start != 0){
	wub = 1;
      }
      j += 3;
    } else {
      if(wub){
	start = 1;
	cout << " " << hello[j];
	j++;
	wub = 0;
      } else {
	start = 1;
	cout << hello[j];
	j++;
      }
    }
    
  }
  cout << endl;
  exit(0);
}