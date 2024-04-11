#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
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
  char str[12];
  scanf("%s", str);
  int colon;
  int len = strlen(str);
  for(int i = 0; i < len; i++){
    if(str[i] == ':'){
      colon = i;
    }
  }
  int started = 0;
  int a[5], b[5];
  int k = 0;
  int maxa = 0;
  for(int i = 0; i < colon; i++){  
    if(started){
      if(str[i] >= '0' && str[i] <= '9'){
	a[k] = str[i] - '0';
	maxa = Max(maxa, a[k]);
	k++;
      } else {
	a[k] = str[i] - 'A' + 10;
	maxa = Max(maxa, a[k]);
	k++;
      }
    } else if(str[i] != '0'){
      if(str[i] > '0' && str[i] <= '9'){
	a[k] = str[i] - '0';
	maxa = Max(maxa, a[k]);
	k++;
	started = 1;
      } else {
	a[k] = str[i] - 'A' + 10;
	maxa = Max(maxa, a[k]);
	k++;
	started = 1;
      }
    }
  }
  int maxb = 0;
  int m = colon + 1;
  started = 0;
  for(int i = colon + 1; i < len; i++){
    if(started){
      if(str[i] >= '0' && str[i] <= '9'){
	b[m-colon-1] = str[i] - '0';
	maxb = Max(maxb, b[m - colon - 1]);
	m++;
      } else {
	b[m-colon-1] = str[i] - 'A' + 10;
	maxb = Max(maxb, b[m - colon - 1]);
	m++;
      }
    } else {
      if(str[i] != '0'){
	if(str[i] > '0' && str[i] <= '9'){
	  b[m-colon-1] = str[i] - '0';
	  maxb = Max(maxb, b[m - colon - 1]);
	  m++;
	  started = 1;
	} else {
	  b[m-colon-1] = str[i] - 'A' + 10;
	  maxb = Max(maxb, b[m - colon - 1]);
	  m++;
	  started = 1;
	}
      }
    }
  }
  m -= (colon + 1);
  //printf("%d %d\n", k, m);
  if(k <= 1 && m <= 1){
    if(k == 1){
      if(a[0] >= 24){
	printf("0\n");
	exit(0);
      }
    }
    printf("-1\n");
    exit(0);
  }
  //print1d(a, k);
  //print1d(b, m);
  int ex = 0;
  for(int i = Max(2, Max(maxa, maxb) + 1); i < 60; i++){
    for(int wwwww = 0; wwwww < 1; wwwww++){
      int timea = 0;
      for(int j = 0; j < k; j++){
	timea *= i;
	timea += a[j];
      }
      if(timea >= 24){
	break;
      }
      int timeb = 0;
      for(int j = 0; j < m; j++){
	timeb *= i;
	timeb += b[j];
      }
      if(timeb >= 60){
	break;
      }
      printf("%d\n", i);
      ex = 1;
      break;
    }
  }
  if(ex == 0){
    printf("0\n");
  }
  exit(0);
}