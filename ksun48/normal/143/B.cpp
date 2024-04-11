#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
main(int argc, char **argv) {
  char money[100];
  scanf("%s", money);
  int counter = 0, numdec = -1;
  if(money[0] == '-'){
    printf("(");
    counter = 1;
  }
  int len = strlen(money);
  int num = 0;
  for(int i = counter; i < len; i++){
    if(money[i] >= '0' && money[i] <= '9'){
      num++;
    } else {
      break;
    }
  }
  //printf("%d\n", num);
  printf("$");
  for(int i = counter; i < len; i++){
    if(numdec == -1){
      if(money[i] >= '0' && money[i] <= '9'){
	printf("%c", money[i]);
      }
      if((i - counter + 1) % 3 == num % 3 && (i - counter + 1) != num){
	printf(",");
      }
      if(money[i] == '.'){
	numdec = 0;
	printf(".");
      }
    } else if (numdec == 2){
      break;
    } else {
      printf("%c", money[i]);
      numdec++;
    }
  }
  if(numdec == -1){
    printf(".00");
  } else if (numdec == 0){
    printf("00");
  } else if (numdec == 1){
    printf("0");
  }
  if(money[0] == '-'){
    printf(")");
  }
  printf("\n");
  exit(0);
}