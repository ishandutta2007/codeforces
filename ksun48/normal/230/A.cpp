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

  int str, n;
  cin >> str >> n;
  int numdef = 0;
  int drag[n];
  int bonus[n];
  int def[n];
  for(int i = 0; i < n; i++){
    cin >> drag[i] >> bonus[i];
    def[i] = 0;
  }
  while(numdef < n){
    int thisround = 0;
    for(int i = 0; i < n; i++){
      if(str > drag[i] && def[i] == 0){
	str += bonus[i];
	numdef++;
	thisround++;
	def[i] = 1;
      }
    }
    if(thisround == 0){
      cout << "NO" << endl;
      exit(0);
    }
  }
  cout << "YES" << endl;
  exit(0);
}