#include<stdio.h>

int main(){
  int i,j,k,l,m,n;

  scanf("%d",&n);
  if(n<0) n=-n;

  for(i=0;;i++){
    n-=i;
    if(n<=0 && n%2==0) break;
  }

  printf("%d\n",i);

  return 0;
}