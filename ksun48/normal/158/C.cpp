#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf

int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n;
  int numnames = 0;
  cin >> n;
  char names[100042][242];
  int len[100042];
  len[0] = 0;
  for(int i = 0; i < n; i++){
    char c[6];
    cin >> c;
    if(c[0] == 'p'){
      cout << "/";
      for(int j = 0; j < numnames; j++){
	for(int k = 0; k < len[j]; k++){
	  cout << names[j][k];
	}
	cout << "/";
      }
      cout << endl;
    } else {
      char stuff[242];
      cin >> stuff;
      int length = strlen(stuff);
      //cout << length << endl;
      stuff[length] = '/';
      length ++;
      int counter;
      if(stuff[0] == '/'){
	counter = 1;
	for(int i = 0; i < numnames; i++){
	  len[i] = 0;
	}
	numnames = 0;
      } else {
	counter = 0;
      }
      int isname = -1;
      for(counter; counter < length; counter++){
	//cout << "counter " << counter << endl;
	if(stuff[counter] == '/'){
	  if(isname == 1){
	    numnames++;
	    len[numnames] = 0;
	  } else {
	    len[numnames-1] = 0;
	    numnames--;
	  }
	} else {
	  if(stuff[counter] != '.'){
	    names[numnames][len[numnames]] = stuff[counter];
	    len[numnames]++;
	    isname = 1;
	  } else {
	    counter++;
	    isname = 0;
	  }
	}
      }
    }
  }
}