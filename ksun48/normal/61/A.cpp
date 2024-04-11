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
  char scan1[150];
  char scan2[150];
  cin >> scan1 >> scan2;
  int len = strlen(scan1);
  for(int i = 0; i < len; i++){
    if(scan1[i] != scan2[i]){
      cout << 1;
    } else {
      cout << 0;
    }
  }
  cout << endl;
  exit(0);
}