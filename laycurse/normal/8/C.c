#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define INF 1000000000

int dist(int x,int y){return x*x+y*y;}

int n;
int dp[16777216], cost[25][25];

int solve(int mask){
  int i,j,k,res=INF,tmp;

  if(dp[mask]>=0) return dp[mask];

  rep(i,n) if(mask&(1<<i)) break;
  if(i==n) return dp[mask]=0;

  tmp = solve(mask^(1<<i)) + cost[i][i];
  if(tmp < res) res = tmp;

  REP(j,i+1,n) if(mask&(1<<j)){
    tmp = solve(mask^(1<<i)^(1<<j)) + cost[i][j];
    if(tmp < res) res = tmp;
  }

  return dp[mask]=res;
}

void prnt(int mask){
  int i,j,k,res=solve(mask),tmp;

  rep(i,n) if(mask&(1<<i)) break;
  if(i==n) return;

  tmp = solve(mask^(1<<i)) + cost[i][i];
  if(tmp == res){
    printf(" %d 0",i+1);
    prnt(mask^(1<<i));
    return;
  }

  REP(j,i+1,n) if(mask&(1<<j)){
    tmp = solve(mask^(1<<i)^(1<<j)) + cost[i][j];
    if(tmp == res){
      printf(" %d %d 0",i+1,j+1);
      prnt(mask^(1<<i)^(1<<j));
      return;
    }
  }
  puts("FAILED");
}

int main(){
  int i,j,k,l,m;
  int sx,sy,x[33],y[33];

  scanf("%d%d%d",&sx,&sy,&n);
  rep(i,n) scanf("%d%d",x+i,y+i);

  rep(i,n) cost[i][i]=dist(x[i]-sx,y[i]-sy)*2;
  rep(i,n) REP(j,i+1,n) cost[i][j] = dist(x[i]-sx,y[i]-sy) + dist(x[j]-sx,y[j]-sy) + dist(x[i]-x[j],y[i]-y[j]);

  rep(i,1<<n) dp[i]=-1;
  k=solve((1<<n)-1);
  printf("%d\n0",k);
  prnt((1<<n)-1); puts("");
  
  return 0;
}