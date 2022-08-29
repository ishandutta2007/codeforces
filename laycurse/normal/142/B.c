#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  int res;

  while(scanf("%d%d",&n,&m)==2){
    if(n > m) k = n, n = m, m = k;
    if(n==1){ printf("%d\n",m); continue; }
    if(n==2){
      k = (m/4) * 2;
      m %= 4;
      if(m > 2) m = 2;
      printf("%d\n",2*(k+m));
      continue;
    }

    res = (n*m+1)/2;
    printf("%d\n",res);
  }

  return 0;
}