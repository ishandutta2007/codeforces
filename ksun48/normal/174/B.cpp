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
  char str[500000];
  cin >> str;
  int len = strlen(str);
  int between[500000];
  for(int i = 0; i < 500000; i++){
    between[i] = 0;
  }
  int counter = 0;
  for(int i = 0; i < len; i++){
    if(str[i] == '.'){
      counter++;
    } else {
      between[counter]++;
    }
  }
  for(int i = 0; i <= counter; i++){
    if(between[i] == 0 || between[i] > 11){
      cout << "NO" << endl;
      exit(0);
    }
    if(between[i] == 1 && (i != 0 && i != counter)){
      cout << "NO" << endl;
      exit(0);
    }
    if(between[i] > 8 && i == 0){
      cout << "NO" << endl;
      exit(0);
    }
    if(i == counter && between[i] > 3){
      cout << "NO" << endl;
      exit(0);
    }
  }
  if(counter == 0){
    cout << "NO" << endl;
    exit(0);
  }
  int curcounter = 0;
  cout << "YES" << endl;
  int csc = 0;
  for(int i = 0; i < len; i++){
    cout << str[i];
    if(str[i] == '.'){
      curcounter++;
      csc = 0;
    } else {
      csc++;
      if(csc == Min(between[curcounter]-1, 3) && curcounter != 0 && curcounter != counter){
	cout << endl;
      }
      
    }
  }
  cout << endl;
}