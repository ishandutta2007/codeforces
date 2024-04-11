#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define LIM 1100000000000000000LL

ll dp[300][300];
int len;
char res[300];

ll solve(int st, int depth){
  int i,j,k;
  ll ret = 0;

  if(dp[st][depth] >= 0) return dp[st][depth];
  
  if(st==len){
    if(depth==0) ret++;
    return dp[st][depth] = ret;
  }

  if(res[st]==0 || res[st]=='(') ret += solve(st+1, depth+1);
  if(depth && (res[st]==0 || res[st]==')')) ret += solve(st+1, depth-1);

  if(ret > LIM) ret = LIM;

  return dp[st][depth] = ret;
}

int main(){
  int i,j,l,m,n;
  int x, y;
  int p[300];
  ll k, tmp;

  while(scanf("%d%d%I64d",&x,&y,&k)==3){
    len = x+y-1; k--;
    rep(i,len) p[i] = 1000000000;
    rep(i,len) res[i] = 0;

    rep(i,x) rep(j,y){
      scanf("%d",&m);
      if(p[i+j] > m) p[i+j] = m;
    }

    for(;;){
      rep(i,len+2) rep(j,len+2) dp[i][j] = -1;
      
      m = 1000000000;
      rep(i,len) if(m > p[i]) m = p[i];
      if(m==1000000000) break;
      
      rep(i,len) if(m==p[i]) break;
      p[i] = 1000000000;
      res[i] = '(';
      tmp = solve(0,0);
      if(tmp <= k){
        k -= tmp;
        res[i] = ')';
      }
    }

    rep(i,x){
      rep(j,y) putchar(res[i+j]);
      puts("");
    }
  }

  return 0;
}