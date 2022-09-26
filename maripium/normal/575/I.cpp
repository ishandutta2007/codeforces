#include <bits/stdc++.h>

using namespace std;

struct FT {
   int tr[5010][10010];
   void reset() { memset(tr, 0, sizeof tr); }
   void add(int x, int y, int val) {
      for (int v = x; v < 5010; v += v & -v) {
         for (int u = y; u < 10010; u += u & -u) {
            tr[v][u] += val;
         }
      }
   }
   int get(int x, int y) {
      int ans = 0;
      for (int v = x; v > 0; v -= v & -v) {
         for (int u = y; u > 0; u -= u & -u) {
            ans += tr[v][u];
         }
      }
      return ans;
   }
} ft[2];

int main() {
   ios_base::sync_with_stdio(false);
   int N, Q;
   cin >> N >> Q;
   vector<array<int, 5>> qs(Q);
   for (int q = 0; q < Q; ++q) {
      qs[q].fill(-1);
      cin >> qs[q][0];
      if (qs[q][0] == 1) {
         cin >> qs[q][1] >> qs[q][2] >> qs[q][3] >> qs[q][4];
         --qs[q][1];
      } else {
         cin >> qs[q][1] >> qs[q][2];
      }
   }
   vector<int> ans(Q);
   for (int dir = 0; dir < 4; ++dir) {
      ft[0].reset(), ft[1].reset();
      for (int q = 0; q < Q; ++q) {
         if (qs[q][0] == 1) {
            int __dir = qs[q][1], x = qs[q][2], y = qs[q][3], len = qs[q][4];
            if (dir == __dir) {
               if (dir & 1) y = N + 1 - y;
               if (dir & 2) x = N + 1 - x;
               ft[0].add(x, y, +1);
               ft[0].add(x, y + len + 1, -1);
               ft[1].add(y, x + y + len + 1, -1);
               ft[1].add(y + len + 1, x + y + len + 1, +1);
            }
         } else {
            int x = qs[q][1], y = qs[q][2];
            if (dir & 1) y = N + 1 - y;
            if (dir & 2) x = N + 1 - x;
            ans[q] += ft[0].get(x, y) + ft[1].get(y, x + y);
         }
      }
   }
   for (int q = 0; q < Q; ++q) if (qs[q][0] == 2) cout << ans[q] << "\n";
}