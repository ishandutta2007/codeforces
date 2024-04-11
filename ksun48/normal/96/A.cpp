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
  char a[120];
  cin >> a;
  int len = strlen(a);
  int k[120];
  for(int i = 0; i < len; i++){
    k[i] = a[i]-'0';
  }
  for(int i = 0; i < len - 6; i++){
    if((k[i]+k[i+1]+k[i+2]+k[i+3]+k[i+4]+k[i+5]+k[i+6] ) % 7 == 0){
      cout << "YES" << endl;
      exit(0);
    }
  }

  cout << "NO" << endl;
  exit(0);
}