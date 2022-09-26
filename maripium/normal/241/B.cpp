#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;

int add(int x, int y) { return ((x += y) >= MOD) ? x - MOD : x; }
int mult(int x, int y) { return ll(x) * y % MOD; }

int main() {
   ios_base::sync_with_stdio(false);
   int N; ll M;
   cin >> N >> M; M *= 2;
   vector<int> A(N);
   for (int i = 0; i < N; ++i) cin >> A[i];
   sort(A.begin(), A.end());
   vector<array<int, 30>> pref(N + 1);
   auto bit = [&](int x, int b) { return x >> b & 1; };
   pref[0] = {};
   for (int i = 0; i < N; ++i) {
      pref[i + 1] = pref[i];
      for (int j = 0; j < 30; ++j) {
         pref[i + 1][j] += bit(A[i], j);
      }
   };
   int ans = 0;
   auto calc = [&](int i, int l, int r) {
      for (int b = 0; b < 30; ++b) {
         if (A[i] >> b & 1) {
            ans = add(ans, mult(r - l + 1 - pref[r + 1][b] + pref[l][b], 1 << b));
         } else {
            ans = add(ans, mult(pref[r + 1][b] - pref[l][b], 1 << b));
         }
      }
   };
   vector<int> from(N), to(N);
   for (int i = 0; i < N; ++i) {
      from[i] = 0;
      to[i] = N - 1;
   }
   int mask = 0;
   int val = 0;
   for (int b = 29; b >= 0; --b) {
      mask |= (1 << b);
      vector<int> nxt(N, -1);
      vector<int> prv(N, -1);
      int l = 0;
      while (l < N) {
         int r = l;
         while (r + 1 < N && (A[r + 1] & mask) == (A[l] & mask)) {
            r++;
         }
         nxt[l] = r;
         prv[r] = l;
         l = r + 1;
      }
      ll cnt = 0;
      for (int i = 0; i < N; ++i) {
         if (from[i] == to[i] + 1) continue;
         if (bit(A[i], b)) {
            if (!bit(A[from[i]], b)) cnt += nxt[from[i]] - from[i] + 1;
         } else {
            if (bit(A[to[i]], b)) cnt += to[i] - prv[to[i]] + 1;
         }
      }
      assert(cnt % 2 == 0);
      bool zero = false;
      if (M >= cnt) {
         zero = true;
         M -= cnt;
         for (int i = 0; i < N; ++i) {
            if (from[i] == to[i] + 1) continue;
            if (bit(A[i], b) && !bit(A[from[i]], b)) calc(i, from[i], nxt[from[i]]);
            if (!bit(A[i], b) && bit(A[to[i]], b)) calc(i, prv[to[i]], to[i]);
         }
      } else val |= (1 << b);
      for (int i = 0; i < N; ++i) {
         if (from[i] == to[i] + 1) continue;
         if (bit(A[i], b) == zero) {
            if (bit(A[to[i]], b)) {
               from[i] = prv[to[i]];
            } else {
               from[i] = to[i] + 1;
            }
         } else {
            if (!bit(A[from[i]], b)) {
               to[i] = nxt[from[i]];
            } else {
               to[i] = from[i] - 1;
            }
         }
      }
   }
   ans = add(ans, mult(M % MOD, val));
   ans = mult(ans, (MOD + 1) / 2);
   cout << ans << "\n";
   return 0;
}