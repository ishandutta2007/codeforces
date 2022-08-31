#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define N 4000

int getPrime(int n,int p[]){int i,j,n2=n/2;rep(i,n2)p[i]=1;for(i=3;i*i<n;i+=2)if(p[i>>1])for(j=(i*i)>>1;j<n2;j+=i)p[j]=0;j=1;p[0]=2;REP(i,1,n2)if(p[i])p[j++]=i*2+1;return j;}

int ps,p[N];

int is_ok(int n){
  int i,j,k=0;

  rep(i,ps) if(n%p[i]==0){
    while(n%p[i]==0) n/=p[i];
    k++;
  }
  if(k==2 && n==1) return 1;
  return 0;
}

int main(){
  int i,j,k,l,m,n;
  int res=0;

  ps=getPrime(N,p);

  scanf("%d",&n);
  REP(i,5,n+1) res += is_ok(i);
  printf("%d\n",res);

  return 0;
}