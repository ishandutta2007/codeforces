// https://codeforces.com/contest/1322/submission/72646344

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500500;
const int LG = 19;
const int INF = 2e9;

int N;
int A[MAXN];

struct RMQ {
   int rmq[LG][MAXN];
   void modify(int p, int z) {
      rmq[0][p] = z;
   }
   void build() {
      for (int i = 1; i < LG; ++i) {
         for (int j = 0; j + (1 << i) <= N; ++j) {
            rmq[i][j] = max(rmq[i - 1][j], rmq[i - 1][j + (1 << i - 1)]);
         }
      }
   }
   int q(int l, int r) {
      int lg = __lg(r - l + 1);
      return max(rmq[lg][l], rmq[lg][r - (1 << lg) + 1]);
   }
} mn[2], mx[2];

int ans = 0;

int main() {
   ios_base::sync_with_stdio(false);
   cin >> N;
   for (int i = 0; i < N; ++i) cin >> A[i];
   for (int z = 0; z < 2; ++z) {
      for (int i = 0; i < N; ++i) mx[z].modify(i, ((i & 1) == z) ? A[i] : -INF);
      mx[z].build();
      for (int i = 0; i < N; ++i) mn[z].modify(i, ((i & 1) == z) ? -A[i] : -INF);
      mn[z].build();
   }
   for (int i = 0; i < N; ++i) {
      int z = i & 1;
      int low = 0, high = min(i, N - i - 1);
      while (low < high) {
         int mid = (low + high + 1) >> 1;
         if (mx[z].q(i - mid, i + mid) < -mn[z ^ 1].q(i - mid, i + mid) ||
             -mn[z].q(i - mid, i + mid) > mx[z ^ 1].q(i - mid, i + mid)) low = mid;
         else high = mid - 1;
      }
      ans = max(ans, low);
      if (low & 1) {
         if (mx[z].q(i - low, i + low) < -mn[z ^ 1].q(i - low, i + low)) {
            A[i] = -mn[z ^ 1].q(i - low, i + low);
         } else {
            A[i] = mx[z ^ 1].q(i - low, i + low);
         }
      } else {
         if (mx[z].q(i - low, i + low) < -mn[z ^ 1].q(i - low, i + low)) {
            A[i] = mx[z].q(i - low, i + low);
         } else {
            A[i] = -mn[z].q(i - low, i + low);
         }
      }
   }
   cout << ans << "\n";
   for (int i = 0; i < N; ++i) cout << A[i] << " "; cout << "\n";
}