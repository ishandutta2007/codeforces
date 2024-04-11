#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  int num[10000];

  rep(i,10000) num[i] = 0;

  scanf("%d",&n);
  while(n--){
    scanf("%d%d",&i,&j);
    num[i*100+j]++;
  }

  m = 0;
  rep(i,10000) if(m < num[i]) m = num[i];
  printf("%d\n",m);

  return 0;
}