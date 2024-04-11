
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int DEBUG = 0;

int max(int a, int b) {
  return a > b ? a : b;
}
int min(int a, int b) {
  return a < b ? a : b;
}

int *alloc1d(int M) {
  int *a = new int [M];
  return a;
}

void print1d(int *vec, int M, const char *str=NULL) {
  if(str != NULL) printf("%s ", str);
  for(int i=0; i<M; i++) {
    if(i>0) printf(" ");
    printf("%d", vec[i]);
  }
  printf("\n");
}

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

void copy_vec(int *to, int *from, int s, int e) {
  for(int i=s; i<=e; i++) to[i] = from[i];
}

void print_vec(int *vec, int s, int e) {
  for(int i=s; i<=e; i++) {
    if(i>s) printf(" ");
    printf("%d", vec[i]);
  }
  printf("\n");
}


main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n;
  scanf("%d", &n); 
  int prefs[n][n];
  int chefprefs[n];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      scanf("%d", &prefs[i][j]);
      prefs[i][j]--;
    }
  }
  for(int i = 0; i < n; i++){
    scanf("%d", &chefprefs[i]);
    chefprefs[i]--;
  }
  int best[n], sbest[n];
  int isfav[n];
  int **is2nd = alloc2d(n, n);

  for(int i = 0; i < n; i++){
    best[i] = -1;
    sbest[i] = -1;
    isfav[i] = 0;
    for(int j = 0; j < n; j++){
      is2nd[i][j] = 0;
    }
  }
  for(int i = 0; i < n; i++){
    int count = 0;
    for(int j = 0; j < n; j++){
      if(chefprefs[j] < i+1){
	if(count == 0){
	  count = 1;
	  best[i] = chefprefs[j];
	  isfav[chefprefs[j]] = 1;
	} else {
	  sbest[i] = chefprefs[j];
	  is2nd[best[i]][sbest[i]] = 1;
	  break;
	}
      }
    }
  }
  if(DEBUG) {
    print1d(best,  n, "best: ");
    print1d(sbest, n, "sbest:");
    print1d(isfav, n, "isfav:");
    print2d(is2nd, n, n, "is2nd:");
  }

  //print_vec(isfav, 0, n-1);
  for(int i = 0; i < n; i++){
    int fav = 4882427;
    for(int j = 0; j < n; j++){
      //printf("j%d\n", j);
      if(i != prefs[i][j]){
	if(isfav[prefs[i][j]] == 1){
	  //printf("%d %d %d\n", i, j, prefs[i][j]);
	  fav = min(fav, j);
	}
      }
    }
    //printf("111 fav %d\n", fav);
    for(int j = 0; j < n; j++){
      if(is2nd[i][prefs[i][j]] == 1){
	//printf("3412432143 %d %d \n", i, j);
	for(int k = 0; k < n; k++){
	  if(i != prefs[i][k]){
	    if(prefs[i][k] == j){
	    //printf("%d\n", k);
 	      fav = min(fav, j);
	      break;
	    }
	  }
	}
      }
    }
    //printf("fav%d\n", fav);
    printf("%d\n", prefs[i][fav]+1);
  }
  exit(0);
}

// g++ newyearcards.cpp; cat newyearcards.in | ./a.out 1