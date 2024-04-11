#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N=3100, MOD=998244353;
int n,m,ans,dp[N][N];
char s[N],t[N];

void inc(int& a, int b) { a = (a + b) % MOD; }

int main() {
  scanf("%s%s",s,t);
  n = strlen(s);
  m = strlen(t);

  REP(i,n+1) {
    dp[i][i] = 1;
  }

  REP(I,n) {
    REP(j,n+1) {
      int i = j-I;
      if (i < 0) continue;

      if (j+1 <= n && (j >= m || t[j] == s[I])) {
        inc(dp[i][j+1], dp[i][j]);
      }
      if (i > 0 && (i-1 >= m || t[i-1] == s[I])) {
        inc(dp[i-1][j], dp[i][j]);
      }
    }
  }
  REP(j,n+1) if (j>=m) {
    inc(ans, dp[0][j]);
  }

  printf("%d\n",ans);
}