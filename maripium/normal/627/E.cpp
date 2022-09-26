#include <bits/stdc++.h>

using namespace std;

const int MX = 3030;

vector<int> ys[MX];
int cnts[MX];
int prv[MX];
int nxt[MX];
int go[MX];

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int R, C, N, K;
   cin >> R >> C >> N >> K;
   for (int i = 0; i < N; ++i) {
      int r, c;
      cin >> r >> c;
      ys[r].emplace_back(c);
   }
   long long ans = 0;
   for (int xr = 1; xr <= R; ++xr) {
      for (int z = 0; z <= C + 1; ++z) {
         prv[z] = z - 1;
         nxt[z] = z + 1;
         cnts[z] = 0;
      }
      int tot = 0;
      for (int l = 1; l <= xr; ++l) {
         for (int y : ys[l]) ++cnts[y];
      }
      for (int z = 1; z <= C; ++z) {
         if (!cnts[z]) {
            prv[nxt[z]] = prv[z];
            nxt[prv[z]] = nxt[z];
         }
      }
      int sum = 0;
      int ptr = C + 1;
      go[C + 1] = C + 1;
      for (int z = prv[C + 1]; z > 0; z = prv[z]) {
         sum += cnts[z];
         while (sum >= K + cnts[ptr]) {
            sum -= cnts[ptr];
            ptr = prv[ptr];
         }
         go[z] = ptr;
      }
      int cur = 0;
      auto get = [&](int v) {
         return (v - prv[v]) * (C + 1 - go[v]);
      };
      auto kek = [&](int y) {
         for (int z = nxt[y]; z > 0 && go[z] >= y; z = prv[z]) {
            cur -= get(z);
         }
         if (--cnts[y] == 0) {
            prv[nxt[y]] = prv[y];
            nxt[prv[y]] = nxt[y];
         }
         int sum = 0;
         for (int z = nxt[y]; z <= go[nxt[y]]; z = nxt[z]) sum += cnts[z];
         int ptr = go[nxt[y]];
         for (int z = nxt[y]; z > 0 && go[z] >= y; z = prv[z]) {
            if (z != nxt[y]) sum += cnts[z];
            while (sum >= K + cnts[ptr]) {
               sum -= cnts[ptr];
               ptr = prv[ptr];
            }
            go[z] = ptr;
            cur += get(z);
         }
      };
      for (int z = nxt[0]; z <= C; z = nxt[z]) cur += get(z);
      for (int l = 1; l <= xr; ++l) {
         // cerr << l << " " << xr << ": ";
         // for (int z = nxt[0]; z < C + 1; z = nxt[z]) {
            // cerr << z << " " << go[z] << "\n";
         // }
         ans += cur;
         for (int y : ys[l]) kek(y);
      }
   }
   cout << ans << "\n";
   return 0;
}