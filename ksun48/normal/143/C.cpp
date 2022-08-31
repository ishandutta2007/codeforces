#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define LL long long // 64-bit long long int, use %I64d for scan and printf
LL Min(LL a, LL b) {
  return (a < b ? a : b);
}
LL Max(LL a, LL b) {
  return (a > b ? a : b);
}
main(int argc, char **argv) {
  LL n;
  LL minhay = 0x3FFFFFFFFFFF;
  LL maxhay = -1;
  scanf("%I64d", &n);
  for(LL i = 1; i*i*i <= n; i++){
    if(n % i == 0){
      for(LL j = 1; j*j <= n/i; j++){
	if(n % (i*j) == 0){
	  LL k = n/i/j;
	  //printf("%d %d %d\n", i, j, k);
	  minhay = Min(minhay, (i+1)*(j+2)*(k+2));
	  minhay = Min(minhay, (i+1)*(k+2)*(j+2));
	  minhay = Min(minhay, (j+1)*(i+2)*(k+2));
	  minhay = Min(minhay, (j+1)*(k+2)*(i+2));
	  minhay = Min(minhay, (k+1)*(i+2)*(j+2));
	  minhay = Min(minhay, (k+1)*(j+2)*(i+2));
	  maxhay = Max(maxhay, (i+1)*(j+2)*(k+2));
	  maxhay = Max(maxhay, (i+1)*(k+2)*(j+2));
	  maxhay = Max(maxhay, (j+1)*(i+2)*(k+2));
	  maxhay = Max(maxhay, (j+1)*(k+2)*(i+2));
	  maxhay = Max(maxhay, (k+1)*(i+2)*(j+2));
	  maxhay = Max(maxhay, (k+1)*(j+2)*(i+2));
	}
      }     
    }
  }
  printf("%I64d %I64d\n", minhay-n, maxhay-n);
  exit(0);
}