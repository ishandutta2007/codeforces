#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ull unsigned long long
#define D 12009

ull  pw[6666666], hs1[6666666], hs2[6666666];
char in[6666666];
int  dp[6666666];

int main(){
  int i,j,k,l,m,n;
  int a,b,len;
  long long res=0;

  pw[0]=1; REP(i,1,6666666) pw[i]=pw[i-1]*D;
  scanf("%s",in);
  for(i=0;;i++) if(in[i]<' ') break; n=i;

  hs1[0]=0; rep(i,n) hs1[i+1]=hs1[i]*D+in[i];
  hs2[0]=0; rep(i,n) hs2[i+1]=hs2[i]*D+in[n-1-i];

  dp[0]=0;
  REP(i,1,n+1){
    len = i/2;
    a=0; b=i-len;
    if( hs1[a+len]-hs1[a]*pw[len] != hs2[n-b]-hs2[n-b-len]*pw[len] ){dp[i]=0; continue;}
    dp[i] = dp[len]+1;
    res += dp[i];
  }

  printf("%I64lld\n",res);
  return 0;
}