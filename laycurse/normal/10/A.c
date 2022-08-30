#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  int T1,T2,P1,P2,P3;
  int a[120], b[120], res=0;

  scanf("%d%d%d%d%d%d",&n,&P1,&P2,&P3,&T1,&T2);
  rep(i,n) scanf("%d%d",a+i,b+i);

  rep(i,n){
    res += (b[i]-a[i])*P1;
    if(i){
      k=a[i]-b[i-1];
      m=k; if(m>T1) m=T1;
      k-=m; res += P1*m;
      m=k; if(m>T2) m=T2;
      k-=m; res += P2*m;
      res += P3*k;
    }
  }

  printf("%d\n",res);

  return 0;
}