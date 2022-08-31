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
  scanf("%d", &n);
  char players[1500][100];
  int len[1500];
  int scores[1500];
  int numplayers = 0;
  int rounds[n];
  int rs[n];
  for(int i = 0; i < n; i++){
    scores[i] = 0;
  }
  char pwn[100];
  for(int i = 0; i < n; i++){
    cin >> pwn >> rs[i];
    int length = strlen(pwn);
    int exists = 0;
    for(int j = 0; j < numplayers; j++){
      int c = 1;      
      if(length == len[j]){
	for(int k = 0; k < length; k++){
	  if(pwn[k] != players[j][k]){
	    c = 0;
	    break;
	  }
	}
      } else {
	c = 0;
      }
      if(c == 1){
	rounds[i] = j;
	scores[j] += rs[i];
	exists = 1;
	break;
      }
    }
    if(exists == 0){
      len[numplayers] = length;
      //cout << i << endl << length << endl;
      for(int k = 0; k < length; k++){
	players[numplayers][k] = pwn[k];
      }
      scores[numplayers] = rs[i];
      rounds[i] = numplayers;
      numplayers++;
    }
  }
  int max = -100000;
  for(int i = 0; i < numplayers; i++){
    if(scores[i] > max){
      max = scores[i];
    }
    //cout << len[i] << endl;
  }
  //cout << max << endl;
  int finalscores[numplayers];
  for(int i = 0; i < numplayers; i++){
    finalscores[i] = 0;
  }
  int ismax[numplayers];
  for(int i = 0; i < numplayers; i++){
    if(scores[i] == max){
      ismax[i] = 1;
    } else {
      ismax[i] = 0;
    }
  }
  for(int i = 0; i < n; i++){
    finalscores[rounds[i]] += rs[i];
    if(finalscores[rounds[i]] >= max){
      if(ismax[rounds[i]]){
	cout << players[rounds[i]] << endl;
	exit(0);
      }
    }
  }
}