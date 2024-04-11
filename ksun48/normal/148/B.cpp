#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define EPSILON .00000001
main(int argc, char **argv) {
  float vp, vd, t, f, c;
  scanf("%f%f%f%f%f", &vp, &vd, &t, &f, &c);
  if(vp + EPSILON >= vd){
    printf("0\n"); exit(0);
  }
  float ktreins = t*vp;
  int bijou = 0;
  float time = (ktreins)/(vd-vp);
  ktreins += time*vp;
  while(ktreins + EPSILON < c){
    bijou ++;
    //printf("%f\n", ktreins);
    ktreins += f*vp;
    ktreins += time*vp;
    time = (ktreins)/(vd-vp);
    ktreins += time*vp;
  }
  //printf("%f\n", ktreins);
  printf("%d\n", bijou);
}