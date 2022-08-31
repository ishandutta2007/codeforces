#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
int Min(int a, int b) {
  return (a < b ? a : b);
}
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  char k[100001]; int a;
  cin >> k >> a;
  char pairs[a][3];
  for(int i = 0; i < a; i++){
    cin >> pairs[i];
  }
  int num = 0;
  int currpair = -1;
  int curr0 = 0;
  int curr1 = 0;
  int len = strlen(k);
  for(int i = 0; i < len; i++){
    if(currpair >= 0){
      if(k[i] == pairs[currpair][0]){
	curr0 ++;
      } else if (k[i] == pairs[currpair][1]){
	curr1 ++;
      } else {
	int c = 0;
	num += Min(curr0, curr1);
	curr0 = 0, curr1 = 0;
	for(int j = 0; j < a; j++){
	  if(k[i] == pairs[j][0]){
	    curr0++;
	    currpair = j;
	    c++;
	    break;
	  } 
	  if(k[i] == pairs[j][1]){
	    curr1++;
	    currpair = j;
	    c++;
	    break;
	  } 
	}
	if(c != 1) {
	  currpair = -1;
	}
      }
    } else {
      int c = 0;
      curr0 = 0, curr1 = 0;
      for(int j = 0; j < a; j++){
	if(k[i] == pairs[j][0]){
	  curr0++;
	  currpair = j;
	  c++;
	  break;
	} 
	if(k[i] == pairs[j][1]){
	  curr1++;
	  currpair = j;
	  c++;
	  break;
	} 
      }
      if(c != 1) {
	currpair = -1;
      }
    }
  }
  num += Min(curr0, curr1);
  cout << num << endl;
  exit(0);
}