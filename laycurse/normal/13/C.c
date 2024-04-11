#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define INF 100000000000000000LL

void llSort(ll d[],int s){int i,j;ll k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;i=-1;j=s;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;}llSort(d,i);llSort(d+j+1,s-j-1);}

int main(){
  int i,j,k,l,m,n,ok;
  ll in[6000], dp[6000], num[6000], add;
  ll res=INF;

  scanf("%d",&n);
  rep(i,n){ scanf("%d",&k); in[i]=num[i]=k; }

  llSort(num,n);
  dp[0]=0; rep(i,n) dp[i+1]=INF;

  rep(k,n){
    rep(i,n){
      if(in[i]>=num[k]) add=in[i]-num[k]; else add=num[k]-in[i];
      if(dp[i+1]>dp[i]+add) dp[i+1]=dp[i]+add;
    }
/*    printf("%d : %lld\n",k,num[k]);
    rep(i,n+1) printf("%d %lld\n",i,dp[i]);*/
  }

  printf("%I64lld\n",dp[n]);
  
  return 0;
}