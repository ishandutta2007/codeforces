#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  int in[110000];
  int sum1[110000], sum2[110000];
  int res, mx, tmp;

  scanf("%d",&n);
  rep(i,n) scanf("%d",in+i+1);
  in[0]=in[n+1]=0; n+=2;

  sum1[0]=sum2[n-1]=0;
  REP(i,1,n) sum1[i]=sum1[i-1]+in[i];
  for(i=n-2;i>=0;i--) sum2[i]=sum2[i+1]+in[i];

  res = sum1[n-1]; mx=0;
  REP(i,1,n-1){
    if(mx > sum1[i]) mx = sum1[i];
    tmp = sum1[i] - mx - mx - sum2[i+1];
    if(tmp > res) res = tmp;
  }
  printf("%d\n",res);

  return 0;
}