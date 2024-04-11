#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int getPrime(int n,int p[]){int i,j,n2=n/2;rep(i,n2)p[i]=1;for(i=3;i*i<n;i+=2)if(p[i>>1])for(j=(i*i)>>1;j<n2;j+=i)p[j]=0;j=1;p[0]=2;REP(i,1,n2)if(p[i])p[j++]=i*2+1;return j;}

int ps, p[1100];
int ok[1100];

int main(){
  int i,j,k,l,m,n;

  ps = getPrime(1100,p);

  rep(i,1100) ok[i]=0;
  REP(i,1,ps){
    if(p[i-1]+p[i]+1 >= 1100) break;
    ok[p[i-1]+p[i]+1]=1;
  }

  scanf("%d%d",&n,&k);
  rep(i,ps) if(p[i]<=n) if(ok[p[i]]) k--;

  if(k>0) puts("NO"); else puts("YES");

  return 0;
}