#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int dp[4100][4100];
char a[4100], b[4100]; int as, bs;
int cost[4];
int nextA[4100][26], nextB[4100][26];

int solve(int A,int B){
  int i,j,k;
  int res = 1000000000, tmp;

  if(dp[A][B] >= 0) return dp[A][B];
  if(A==0 && B==0) return dp[A][B] = 0;
  if(A==0 || B==0) return dp[A][B] = cost[1] * A + cost[0] * B;
  if(a[A-1] == b[B-1]) return dp[A][B] = solve(A-1,B-1);

  tmp = cost[1] + solve(A-1,B);
  if(res > tmp) res = tmp;

  tmp = cost[0] + solve(A,B-1);
  if(res > tmp) res = tmp;

  tmp = cost[2] + solve(A-1,B-1);
  if(res > tmp) res = tmp;

  if(A>=2 && B>=2){
    j = nextA[A-1][b[B-1]-'a'];
    k = nextB[B-1][a[A-1]-'a'];
    if(j>=0 && k>=0){
      tmp = (A-j-2)*cost[1] + (B-k-2)*cost[0] + cost[3];
      tmp += solve(j,k);
      if(res > tmp) res = tmp;
    }
  }

  return dp[A][B] = res;
}

int main(){
  int i,j,k,l,m,n;

  while(scanf("%d%d%d%d%s%s",cost,cost+1,cost+2,cost+3,a,b)==6){
    for(i=0;;i++) if(a[i]<' ') break; as = i;
    for(i=0;;i++) if(b[i]<' ') break; bs = i;

    rep(i,26) nextA[0][i] = -1;
    rep(k,as){
      nextA[k][a[k]-'a'] = k;
      rep(i,26) nextA[k+1][i] = nextA[k][i];
    }

    rep(i,26) nextB[0][i] = -1;
    rep(k,bs){
      nextB[k][b[k]-'a'] = k;
      rep(i,26) nextB[k+1][i] = nextB[k][i];
    }

    rep(i,as+1) rep(j,bs+1) dp[i][j] = -1;
    k = solve(as,bs);
    printf("%d\n",k);
  }

  return 0;
}