#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  int in[6];
  double p;
  char *out[2]={"Ron","Hermione"};

  while(scanf("%d%d%d%d%d%d",in,in+1,in+2,in+3,in+4,in+5)==6){
    for(i=5;i>=0;i--) if(in[(i+4)%6]==0) break;
    if(i>=0){ puts(out[i%2]); continue; }
    p = 1.0;
    rep(i,3) p *= in[i*2+1]/(double)in[i*2];
    if(p > 1.0 + 1e-10) puts(out[0]); else puts(out[1]);
  }

  return 0;
}