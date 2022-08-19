#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int DEBUG = 0;
int compare_dec (const void * a, const void * b) {
  return ( *(int*)b - *(int*)a );
}
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int a;
  scanf("%d", &a);
  int months[12];
  for(int i = 0; i < 12; i++){
    scanf("%d", &months[i]);
  }
  if(a == 0){
    printf("0\n");
    exit(0);
  }
  int height = 0;
  qsort(months, 12, sizeof(int), compare_dec);
  for(int i = 0; i < 12; i++){
    height += months[i];
    if(height >= a){
      printf("%d\n", i+1);
      exit(0);
    }
  }
  printf("-1\n");
  exit(0);
}