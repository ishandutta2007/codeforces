#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int in[1000][2], cost[1000][2], in_size[1000];
int res1, res2;

void dfs(int now,int bef){
  int i;
  rep(i,2) if(in[now][i]!=bef){
    if(cost[now][i]>0) res1 += cost[now][i];
    if(cost[now][i]<0) res2 -= cost[now][i];
    if(in[now][i]==0) return;
    dfs(in[now][i],now);
    return;
  }
}

int main(){
  int i,j,k,l,m,n;

  scanf("%d",&n);
  rep(i,n) in_size[i]=0;
  rep(l,n){
    scanf("%d%d%d",&i,&j,&k);
    i--; j--;
    in[i][in_size[i]]=j; cost[i][in_size[i]++]=k;
    in[j][in_size[j]]=i; cost[j][in_size[j]++]=-k;
    
  }

  res1=res2=0;
  dfs(0,-1);

  if(res1>res2) res1=res2;
  printf("%d\n",res1);

  return 0;
}