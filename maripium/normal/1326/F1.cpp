#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int N;
bool A[14][14];
ll cntl[1 << 6][14];
ll cntr[1 << 6][14];
ll ans[1 << 13];
int perm[10];
int perm2[10];
int ppc[1 << 14];

void solve(int mask) {
   memset(cntl, 0, sizeof cntl);
   memset(cntr, 0, sizeof cntr);
   int lc = 0;
   for (int i = 0; i < N; ++i) {
      if (mask & (1 << i)) {
         perm[lc++] = i;
      }
   }
   do {
      int cur = 0;
      for (int i = 0; i < lc - 1; ++i) {
         cur = cur << 1 | (A[perm[i]][perm[i + 1]]);
      }
      cntl[cur][perm[lc - 1]]++;
   } while (next_permutation(perm, perm + lc));
   int rc = 0;
   for (int i = 0; i < N; ++i) {
      if (!(mask & (1 << i))) {
         perm2[rc++] = i;
      }
   }
   do {
      int cur = 0;
      for (int i = 0; i < rc - 1; ++i) {
         cur = cur << 1 | (A[perm2[i]][perm2[i + 1]]);
      }
      cntr[cur][perm2[0]]++;
   } while (next_permutation(perm2, perm2 + rc));
   for (int m1 = 0; m1 < 1 << (lc - 1); ++m1) {
      for (int l = 0; l < lc; ++l) {
         if (!cntl[m1][perm[l]]) continue;
      for (int m2 = 0; m2 < 1 << (rc - 1); ++m2) {
            for (int r = 0; r < rc; ++r) {
               int cur = (m1 << 1 | A[perm[l]][perm2[r]]) << (rc - 1) | m2;
               ans[cur] += ll(cntl[m1][perm[l]]) * cntr[m2][perm2[r]];
            }
         }
      }
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> N;
   for (int i = 0; i < N; ++i) {
      string S;
       cin >> S;
      for (int j = 0; j < N; ++j) {
         A[i][j] = S[j] == '1';
      }
   }
   for (int i = 1; i < 1 << N; ++i) {
      ppc[i] = ppc[i >> 1] + (i & 1);
   }
   for (int mask = 0; mask < (1 << N); ++mask) {
      if (__builtin_popcount(mask) == (N + 1) / 2) {
         solve(mask);
      }
   }
   for (int i = 0; i < 1 << (N - 1); ++i) {
      cout << ans[i] << " ";
   }
}