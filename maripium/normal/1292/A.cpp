#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

int N, Q;
bool A[MAXN][2];
bool tr[MAXN << 2][2][2];

void recalc(int v) {
   for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
         tr[v][i][j] = false;
         for (int k = 0; k < 2; ++k) {
            tr[v][i][j] |= (tr[v << 1][i][k] && tr[v << 1 | 1][k][j]);
         }
      }
   }
}

void update(int v, int l, int r, int p) {
   if (l == r) {
      tr[v][0][0] = !A[l][0];
      tr[v][1][1] = !A[l][1];
      tr[v][0][1] = tr[v][1][0] = !(A[l][0] || A[l][1]);
      return;
   }
   int md = (l + r) >> 1;
   if (p <= md) update(v << 1, l, md, p);
   else update(v << 1 | 1, md + 1, r, p);
   recalc(v);
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> N >> Q;
   for (int i = 0; i < N; ++i) {
      update(1, 0, N - 1, i);
   }
   while (Q--) {
      int r, c;
      cin >> r >> c;
      --r, --c;
      A[c][r] ^= true;
      update(1, 0, N - 1, c);
      cout << (tr[1][0][1] ? "Yes" : "No") << "\n";
   }
}