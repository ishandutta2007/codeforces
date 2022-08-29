#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  int edge[120][120], deg[120];
  int tm;

  scanf("%d%d",&n,&m);
  rep(i,n) rep(j,n) edge[i][j] = 0;
  while(m--){
    scanf("%d%d",&i,&j);
    edge[i-1][j-1] = edge[j-1][i-1] = 1;
  }

  for(tm=0;;tm++){
    int ok = 0;
    
    rep(i,n){
      deg[i] = 0;
      rep(j,n) if(edge[i][j]) deg[i]++;
    }
    
    rep(i,n) if(deg[i]==1){
      ok = 1;
      rep(j,n) if(edge[i][j]) edge[i][j] = edge[j][i] = 0;
    }

    if(!ok) break;
  }

  printf("%d\n",tm);

  return 0;
}