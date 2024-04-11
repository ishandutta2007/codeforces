/*
ID: ksun482
LANG: C++
TASK: start
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
double EPSILON = .000001;
main(int argc, char **argv) {
  double n, R, r;
  scanf("%lf%lf%lf", &n, &R, &r);
  if(r > R){
    printf("NO\n");
    exit(0);
  }
  if(n == 1){
    if(r <= R){
      printf("YES\n");
      exit(0);
    } else {
      printf("NO\n");
      exit(0);
    }
  }
  double optside = r/sin(3.1415926535/n) + r;
  //printf("%lf\n", optside);
  if(optside <= R+ EPSILON){
    printf("YES\n");
  } else {
    printf("NO\n");
  }

  exit(0);
}

// g++ -g start.cpp; ./a.out start.in 1

// cat ../../start.cpp | sed 's/start/newtask/g' > tmp.cpp