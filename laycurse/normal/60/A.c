#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  int mn,mx;
  char a[100],b[100],c[100],d[100];

  while(scanf("%d%d",&n,&m)==2){
    mn = n+1;
    mx = 0;
    while(m--){
      scanf("%s%s%s%s%d",a,b,c,d,&k);
      if(c[0]=='r' && k>mx) mx=k;
      if(c[0]=='l' && k<mn) mn=k;
    }
    k = mn - mx - 1;
    if(k<=0) k=-1;
    printf("%d\n",k);
  }

  return 0;
}