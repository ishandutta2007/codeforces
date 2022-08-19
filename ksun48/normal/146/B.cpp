#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int exp(int a){
  int t = 1;
  for(int i = 0; i < a; i++){
    t *= 10;
  }
  return t;
}
int mask(int b){
  int tmp = b;
  int ans = 0;
  int numcurr = 0;
  for(int i = 0; i < 10; i++){
    if(tmp >= 0){
      if(tmp % 10 == 4 || tmp % 10 == 7){
	ans += exp(numcurr)*(tmp % 10);
	numcurr++;
      }
      tmp = (tmp - tmp % 10)/10;
    } else {
      break;
    }
  }
  return ans;
}
main(int argc, char **argv) {
  int a;
  int b;
  scanf("%d%d", &b, &a);
  for(int i = b+1; i < 39428334; i++){
    int masks = mask(i);
    if(masks == a){
      printf("%d\n", i);
      exit(0);
    }
  }
exit(0);
}