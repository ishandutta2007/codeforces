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
int **alloc2d(int M, int N) {
  int **a = new int * [M];
  for(int i=0; i<M; i++) a[i] = new int [N];
  return a;
}
void print2d(int **a, int M, int N, const char *str=NULL) {
  if(str != NULL) printf("%s\n", str);
  for(int i=0; i<M; i++) {
    for(int j=0; j<N; j++) {
      printf (" %2d", a[i][j]);
    }
    printf("\n");
  }
}
char **alloc2d_char(int M, int N) {
  char **a = new char * [M];
  for(int i=0; i<M; i++) a[i] = new char [N];
  return a;
}
void print2d_char(char **a, int M, int N, const char *str=NULL) {
  if(str != NULL) printf("%s\n", str);
  for(int i=0; i<M; i++) {
    for(int j=0; j<N; j++) {
      printf ("%c", a[i][j]);
    }
    printf("\n");
  }
}
int numfilled;
void fill(int **filled, char **sq, int w, int l, int i, int j){
  filled[i][j] = 1;
  numfilled ++;
  for(int a = -1; a <= 1; a++){
    for(int b = -1; b <= 1; b++){
      int newi = i + a;
      int newj = j + b;
      if(newi != -1 && newj != -1 && newi != w & newj != l){	
	if((a != 0 || b != 0) && (a == 0 || b == 0)){
	  if(sq[newi][newj] == '#' && filled[newi][newj] == -1){
	    fill(filled, sq, w, l, newi, newj);
	  }
	}
      }
    }
  }
}

int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n, m;
  cin >> n >> m;
  char **sq = alloc2d_char(n+1, m+1);
  for(int i = 0; i < n; i++){
    scanf("%s", sq[i]);
  }
  int num = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(sq[i][j] == '#'){
	num++;
      }
    }
  }
  if(num == 0 || num == 1 || num == 2){
    cout << -1 << endl;
    exit(0);
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(sq[i][j] == '#'){
	sq[i][j] = '.';
	int k11 = 0;
	for(int i1 = 0; i1 < n; i1++){
	  for(int j1 = 0; j1 < m; j1++){
	    if(sq[i1][j1] == '#' && (i1 != i || j1 != j) && k11 == 0){
	      //print2d_char(sq, n, m);
	      int **filled = alloc2d(n+1, m+1);
	      for(int i11 = 0; i11 < n; i11++){
		for(int j11 = 0; j11 < m; j11++){
		  if(sq[i11][j11] == '#'){
		    filled[i11][j11] = -1;
		  } else {
		    filled[i11][j11] = 0;
		  }
		}
	      }
	      numfilled = 0;
	      fill(filled, sq, n, m, i1, j1);
	      //print2d(filled, n, m);
	      //cout << i1 << " " << j1 << " " << i << " " << j << " " << numfilled << endl;
	      k11 = 1;
	      if(numfilled != num-1){
		cout << 1 << endl;
		exit(0);
	      }
	    }
	  }
	}
	sq[i][j] = '#';
      }
    }
  }
  cout << 2 << endl;
  exit(0);
}