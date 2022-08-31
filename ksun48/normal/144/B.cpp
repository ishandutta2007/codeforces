#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
main(int argc, char **argv) {
  int x1, y1, x2, y2, numr, numblankie = 0;
  scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &numr);
  int x[numr], y[numr], r[numr];
  for(int i = 0; i < numr; i++){
    scanf("%d%d%d", &x[i], &y[i], &r[i]);
  }
  if(x1>x2){
    int tmp = x1;
    x1 = x2;
    x2 = tmp;
  }
  if(y1>y2){
    int tmp = y1;
    y1 = y2;
    y2 = tmp;
  }
  for(int i = x1; i <= x2; i++){
    int blankie = 0;
    for(int j = 0; j < numr; j++){
      if(((i-x[j])*(i-x[j]) + (y1-y[j])*(y1-y[j])) <= r[j]*r[j]){
	blankie = 1;
	break;
      }
    }
    if(blankie == 0){
      numblankie++;
      //printf("%d, %d\n", i, y1);
    }
  } 
  for(int i = x1; i <= x2; i++){
    int blankie = 0;
    for(int j = 0; j < numr; j++){
      if(((i-x[j])*(i-x[j]) + (y2-y[j])*(y2-y[j])) <= r[j]*r[j]){
	blankie = 1;
	break;
      }
    }
    if(blankie == 0){
      numblankie++;
      //printf("%d, %d\n", i, y2);
    }
  }
  for(int i = y1+1; i < y2; i++){
    int blankie = 0;
    for(int j = 0; j < numr; j++){
      if(((i-y[j])*(i-y[j]) + (x1-x[j])*(x1-x[j])) <= r[j]*r[j]){
	blankie = 1;
	break;
      }
    }
    if(blankie == 0){
      numblankie++;
      //printf("%d, %d\n", x1, i);
    }
  } 
  for(int i = y1+1; i < y2; i++){
    int blankie = 0;
    for(int j = 0; j < numr; j++){
      if(((i-y[j])*(i-y[j]) + (x2-x[j])*(x2-x[j])) <= r[j]*r[j]){
	blankie = 1;
	break;
      }
    }
    if(blankie == 0){
      numblankie++;
      //printf("%d, %d\n", x1, i);
    }
  }
  printf("%d\n", numblankie);
}