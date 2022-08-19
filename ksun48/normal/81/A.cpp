#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdint.h>
#include <iostream>
#include <set>
#include <math.h>
#include <deque>
#define LL int64_t
using namespace std;
int Min(int a, int b) {
  return (a < b ? a : b);
}
int Max(int a, int b) {
  return (a > b ? a : b);
}
int Abs(int a) {
  return (a >= 0 ? a : -a);
}
int compare_dec (const void * a, const void * b) {
  if ( Abs(*(int*)a) < Abs(*(int*)b) ) return 1;
  if ( Abs(*(int*)a) > Abs(*(int*)b) ) return -1;
  return 0;
}
main(int argc, char **argv) {
  char stuff[250000];
  cin >> stuff;
  int len = strlen(stuff);
  deque<char> end;
  for(int i = 0; i < len; i++){
    if(!end.empty()){
      if(*end.begin() == stuff[i]){
	end.pop_front();
      } else {
	end.push_front(stuff[i]);
      }
    } else {
      end.push_front(stuff[i]);
    }
  }  
  for(int i = 0; i < end.size(); i++){
    cout << end[end.size()-i-1];    
  }
  cout << endl;
  exit(0);
}