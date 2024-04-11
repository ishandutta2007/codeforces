#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int is_ok(int a,int b){
  int loop,res=0;

  rep(loop,4){
    if(a%10 != b%10) res++;
    a/=10; b/=10;
  }
  if(res>1) return 0; return 1;
}

int main(){
  int i,j,k,l,m,n;
  int in[1200];

  while(scanf("%d",&n)==1){
    rep(i,n) scanf("%d",in+i);

    REP(i,1000,2012) if( is_ok(in[0],i) ) break;
    in[0] = i;

    REP(k,1,n){
      REP(i,in[k-1],2012) if( is_ok(in[k],i) ) break;
      if(i==2012) break;
      in[k] = i;
    }

    if(k<n){ puts("No solution"); continue; }
    rep(i,n) printf("%d\n",in[i]);
  }

  return 0;
}