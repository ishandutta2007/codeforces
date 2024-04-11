#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int x[200000];

int main(){
  int i, j, k, n;
  int a, b, m, r;

  scanf("%d%d%d%d",&a,&b,&m,&r);
  n = 0;

  rep(i,m) x[i] = -1;
  while(x[r] < 0){
    x[r] = n++;
    r = (a*r+b)%m;
  }

  printf("%d\n", n-x[r]);

  return 0;
}