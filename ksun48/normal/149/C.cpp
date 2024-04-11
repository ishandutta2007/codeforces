#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int DEBUG = 0;
void print1d(int *vec, int M, const char *str=NULL) {
  if(str != NULL) printf("%s ", str);
  for(int i=0; i<M; i++) {
    if(i>0) printf(" ");
    printf("%d", vec[i]);
  }
  printf("\n");
}
struct NODE{
  int play;
  int num;
};
int compare_NODE_dec (const void * a, const void * b) {
  return ( (*(NODE*)b).play - (*(NODE*)a).play );
}
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int a;
  scanf("%d", &a);
  int half = int((a+1)/2);
  NODE boys[a];
  for(int i = 0; i < a; i++){
    scanf("%d", &boys[i].play);
    boys[i].num = i+1;
  }
  qsort(boys, a, sizeof(NODE), compare_NODE_dec);
  int t1[a];
  int n1 = 0, s1 = 0, n2 = 0, s2 = 0;
  int t2[a];
  for(int i = 0; i < a; i++){
    if(n1 >= half){
      t2[n2++] = boys[i].num;
      s2 += boys[i].play;
    } else if(n2 >= half){
      t1[n1++] = boys[i].num;
      s1 += boys[i].play;
    } else {
      if(s1 >= s2){
	t2[n2++] = boys[i].num;
	s2 += boys[i].play;
      } else {
	t1[n1++] = boys[i].num;
	s1 += boys[i].play;
      }
    }
  }
  printf("%d\n", n1);
  print1d(t1, n1);
  printf("%d\n", n2);
  print1d(t2, n2);
}