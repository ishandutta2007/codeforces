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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int nd = 1;
  if(b != a){
    nd++;
  }
  if(c != b && c != a){
    nd++;
  }
  if(d != b && d != c && d!= a){
    nd++;
  }
  cout << 4 - nd << endl;
  exit(0);
}