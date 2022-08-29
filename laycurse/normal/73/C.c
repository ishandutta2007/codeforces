#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define YET -1982743198

int len;
char in[200];
int dp[110][110][26];
int edge[26][26];

int solve(int depth, int rest, int bef){
  int i,j,k,nr;
  int res=YET, tmp;

  if(dp[depth][rest][bef] != YET) return dp[depth][rest][bef];
  if(depth==len) return dp[depth][rest][bef] = 0;

  rep(i,26){
    nr = rest;
    if(in[depth]!=i) nr--;
    if(nr < 0) continue;

    tmp = solve(depth+1, nr, i) + edge[bef][i];
    if(res < tmp) res = tmp;
  }

  return dp[depth][rest][bef] = res;
}

int main(){
  int i,j,k,l,m,n;
  int res, tmp;
  char a[11],b[11];

  while(scanf("%s%d",in,&k)==2){
    for(i=0;;i++) if(in[i]<' ') break; len=i;
    rep(i,len) in[i] -= 'a';

    rep(i,26) rep(j,26) edge[i][j]=0;
    scanf("%d",&n);
    while(n--){
      scanf("%s%s%d",a,b,&j);
      edge[a[0]-'a'][b[0]-'a'] += j;
    }

    rep(i,len+1) rep(j,k+1) rep(l,26) dp[i][j][l] = YET;

    res = YET;
    rep(i,26){
      if(in[0]==i)  tmp = solve(1,k,i);
      else if(k)    tmp = solve(1,k-1,i);
      else          tmp = YET;
      if(res < tmp) res = tmp;
    }

    printf("%d\n",res);
  }


  return 0;
}