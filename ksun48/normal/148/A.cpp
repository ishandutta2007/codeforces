#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
main(int argc, char **argv) {
  int a, b, c, d, e, f = 0, g;
  scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
  for(g = 1; g <= e; g++){
	  if(g % a == 0 || g % b == 0 || g % c == 0 || g % d == 0){
		  f++;
	  }
  }
  printf("%d\n", f);
}