#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int T; cin >> T;
   while (T--) {
      int N; cin >> N;
      string S; cin >> S;
      for (char &c : S) {
         if (c == 'L') c = 0;
         else c = 1;
      }
      int start = 0;
      // left 0
      // right 1
      int ans = INF;
      for (int f = 0; f < 2; ++f) {
         for (int s = 0; s < 2; ++s) {
            int dp[2][2] = {{INF, INF}, {INF, INF}};
            dp[f][s] = (f != S[0]) + (s != S[1]);
            for (int i = 2; i < N; ++i) {
               int ndp[2][2] = {{INF, INF}, {INF, INF}};
               for (int prv = 0; prv < 2; ++prv) {
                  for (int cur = 0; cur < 2; ++cur) {
                     if (dp[prv][cur] == INF) continue;
                     for (int nxt = 0; nxt < 2; ++nxt) {
                        int attack = (prv == 1) + (nxt == 0);
                        if (attack == 1) {
                           if (prv == 1 && cur == 1) continue;
                           if (nxt == 0 && cur == 0) continue;
                        }
                        ndp[cur][nxt] = min(ndp[cur][nxt], dp[prv][cur] + (S[i] != nxt));
                     }
                  }
               }
            for (int z = 0; z < 2; ++z) for (int z2 = 0; z2 < 2; ++z2) dp[z][z2] = ndp[z][z2];
            }
            for (int prv = 0; prv < 2; ++prv) {
               for (int cur = 0; cur < 2; ++cur) {
                  {
                     int attack = (cur == 1) + (s == 0);
                     if (attack == 1) {
                        if (cur == 1 && f == 1) continue;
                        if (s == 0 && f == 0) continue;
                     }
                  }
                  {
                     int attack = (prv == 0) + (f == 1);
                     if (attack == 1) {
                        if (prv == 0 && cur == 0) continue;
                        if (f == 1 && cur == 1) continue;
                     }
                  }
                  ans = min(ans, dp[prv][cur]);
               }
            }
         }
      }
      cout << ans << '\n';
   }
}