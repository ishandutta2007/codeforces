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
  char hello[100];
  cin >> hello;
  int len = strlen(hello);
  int l = 0;
  for(int i = 0; i < len; i++){
    if(l == 0){
      if(hello[i] == 'h'){
	l++;
      }
    } else if(l == 1){
      if(hello[i] == 'e'){
	l++;
      }
    } else if(l == 2 || l == 3){
      if(hello[i] == 'l'){
	l++;
      }
    } else if(l == 4){
      if(hello[i] == 'o'){
	l++;
      }
    }   
  }
  if(l == 5){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  exit(0);
}