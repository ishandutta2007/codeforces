#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int DEBUG = 0;
int Max(int a, int b) {
  return (a > b ? a : b);
}
void print1d(int *vec, int M, const char *str=NULL) {
  if(str != NULL) printf("%s ", str);
  for(int i=0; i<M; i++) {
    if(i>0) printf(" ");
    printf("%d", vec[i]);
  }
  printf("\n");
}
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int rows, smash;
  scanf("%d%d", &rows, &smash);
  int vases[rows][101];
  int numvases[rows];
  for(int i = 0; i < rows; i++){
    scanf("%d", &numvases[i]);
    for(int j = 0; j < numvases[i]; j++){
      scanf("%d", &vases[i][j]);      
    } 
  }
  int mb[rows][101];
  for(int i = 0; i < rows; i++){
    for(int j = 0; j <= 100; j++){
      mb[i][j] = 0;
    }
  }
  for(int i = 0; i < rows; i++){
    int lsum[numvases[i]+1], rsum[numvases[i]+1];
    lsum[0] = 0; rsum[0] = 0;
    for(int j = 1; j <= numvases[i]; j++){
      lsum[j] = lsum[j-1] + vases[i][j-1];
      rsum[j] = rsum[j-1] + vases[i][numvases[i]-j];
    }
    for(int j = 0; j <= numvases[i]; j++){
      for(int k = 0; k <= j; k++){
	mb[i][j] = Max(mb[i][j], lsum[k] + rsum[j-k]);
      }
    }
    if(DEBUG) {
      printf("mb[%d]: ", i); print1d(mb[i], smash+1);
    }
  }
  int dp[2][smash+1]; // max value damaged using rows up to i and j smashes
  for(int i = 0; i < 2; i++){
    for(int j = 0; j <= smash; j++){
      dp[i][j] = 0;
    }
  }
  for(int i = 0; i <= smash; i++){
    dp[0][i] = 0;
  }
  for(int i = 0; i < 101; i++){
    dp[0][i] = mb[0][i];
  }
  for(int i = 1; i < rows; i++){
    for(int j = 0; j <= smash; j++){
      dp[i % 2][j] = 0;
      for(int k = Max(0, j-numvases[i]); k <= j; k++){
	dp[i % 2][j] = Max(dp[i % 2][j], dp[(i-1) % 2][k] + mb[i][j-k]);
      }
    } 
    if(DEBUG) {
      printf("dp[%d]: ", i); print1d(dp[i], smash+1);
    }
  }
  printf("%d\n", dp[(rows-1) % 2][smash]);
}

// g++ 148E.cpp; cat 148E.in1 | ./a.out 1