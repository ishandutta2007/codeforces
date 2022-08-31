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
  char k[120];
  cin >> k;
  int len = strlen(k);
  int n = 0;
  for(int i = 0; i < len; i++){
    if(k[i] == '4' || k[i] == '7'){
      n++;
    }
  }
  if(n == 4 || n == 7){
    cout << "YES" << endl;
  } else{
    cout << "NO" << endl;
  }
  exit(0);
}