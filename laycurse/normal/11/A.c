#include<stdio.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n,d,res=0;
  int in[2100];

  scanf("%d%d",&n,&d);
  rep(i,n) scanf("%d",in+i);
  REP(i,1,n) if(in[i-1]>=in[i]){
    k=in[i-1]-in[i];
    res += k/d+1;
    in[i] += (k/d+1)*d;
  }

  printf("%d\n",res);

  return 0;
}