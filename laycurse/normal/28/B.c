#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  int edge[120][120];
  int go[120];

  scanf("%d",&n);
  rep(i,n) scanf("%d",go+i), go[i]--;
  rep(i,n) rep(j,n) edge[i][j]=0; rep(i,n) edge[i][i]=1;
  rep(i,n){
    scanf("%d",&k);
    if(i-k >= 0) edge[i][i-k]=edge[i-k][i]=1;
    if(i+k <  n) edge[i][i+k]=edge[i+k][i]=1;
  }
  rep(k,n) rep(i,n) rep(j,n) edge[i][j] |= (edge[i][k]&edge[k][j]);

  rep(i,n) if(!edge[i][go[i]]) break;
  if(i==n) puts("YES"); else puts("NO");

  return 0;
}