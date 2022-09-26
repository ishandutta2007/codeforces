#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3030;
const int MOD = 998244353;

int N, M;
char S[MAXN], T[MAXN];
int dp[MAXN][MAXN];
int link[MAXN];
int nxt[MAXN][26];

void add(int &x, int y) {
   x += y;
   if (x >= MOD) x -= MOD;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> (S + 1) >> (T + 1);
   int N = strlen(S + 1);
   int M = strlen(T + 1);
   for (int i = 1; i < M; ++i) {
      if (T[i] == S[1]) dp[1][i] = 2;
   }
   for (int i = 2; i <= N; ++i) {
      for (int j = 1; j <= M; ++j) {
         int j2 = min(j + i - 2, M);
         if (S[i] == T[j - 1]) {
            add(dp[i][j - 1], dp[i - 1][j]);
         }
         if (j2 == M || S[i] == T[j2 + 1]) {
            add(dp[i][j], dp[i - 1][j]);
         }
      }
   }
   int ans = 0;
   for (int i = M; i <= N; ++i) add(ans, dp[i][1]);
   memset(dp, 0, sizeof dp);
   for (int i = 1; i <= N + 1; ++i) dp[i][0] = 1;
   for (int i = N; i > 1; --i) {
      for (int j = 0; j <= M; ++j) {
        // if (i >= 1) {
            add(dp[i][j], dp[i + 1][j]);
            if (j == M || T[j + 1] == S[i]) add(dp[i][min(j + 1, M)], dp[i + 1][j]);
         // }
      }
   }
   /*
   cerr << dp[4][0] << "\n";
   cerr << dp[4][1] << "\n";
   cerr << dp[3][0] << "\n";
   cerr << dp[3][1] << "\n";
   cerr << dp[3][2] << "\n";
   cerr << dp[2][0] << "\n";
   cerr << dp[2][1] << "\n";
   cerr << dp[2][2] << "\n";
   */
   int cur = dp[2][M];
   if (S[1] == T[M]) add(cur, dp[2][M - 1]);
   add(cur, cur);
   add(ans, cur);
   cout << ans << "\n";
   return 0;
}