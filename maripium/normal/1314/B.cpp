#include <bits/stdc++.h>

using namespace std;

void mxm(int &a, int b) { a = max(a, b); }

int main() {
   ios_base::sync_with_stdio(false);
   int N, K;
   cin >> N >> K;
   vector<bool> was(1 << N);
   while (K--) {
      int v;
      cin >> v;
      was[--v] = true;
   }
   const int INF = 1e9;
   using State = array<array<int, 2>, 2>;
   function<State(int, int)> Dfs = [&](int l, int r) {
      State ans;
      ans[0][0] = ans[0][1] = ans[1][0] = ans[1][1] = -INF;
      if (r - l == 1) {
         mxm(ans[was[l]][was[r]], int(was[l] | was[r]));
         mxm(ans[was[r]][was[l]], int(was[l] | was[r]));
         return ans;
      } else {
         int mid = (l + r) >> 1;
         State ansL = Dfs(l, mid);
         State ansR = Dfs(mid + 1, r);
         for (int upl = 0; upl < 2; ++upl) {
            for (int upr = 0; upr < 2; ++upr) {
               for (int lol = 0; lol < 2; ++lol) {
                  for (int lor = 0; lor < 2; ++lor) {
                     if (ansL[upl][lol] == INF || ansR[upr][lor] == INF) continue;
                     int curVal = ansL[upl][lol] + ansR[upr][lor] + (upl | upr) + (lol | lor);
                     for (int upWin : {upl, upr}) {
                        int upLose = upl + upr - upWin;
                        for (int loWin : {lol, lor}) {
                           int curVal2 = curVal + (upLose | loWin);
                           for (int v : {upLose, loWin}) {
                              mxm(ans[upWin][v], curVal2);
                           }
                        }
                     }
                  }
               }
            }
         }
         return ans;
      }
   };
   auto ans = Dfs(0, (1 << N) - 1);
   int best = 0;
   for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
         best = max(best, ans[i][j] + (i || j));
      }
   }
   cout << best;
}