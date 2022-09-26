#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int T; cin >> T;
   while (T--) {
      int N; string A, B; cin >> N >> A >> B;
      bool fail = false;
      for (int i = 0; i < N; ++i) if (A[i] > B[i]) fail = true;
      vector<int> par(20);
      iota(par.begin(), par.end(), 0);
      function<int(int)> getp = [&](int v) {
         if (par[v] != v) {
            par[v] = getp(par[v]);
         }
         return par[v];
      };
      for (int i = 0; i < N; ++i) {
         int v = getp(A[i] - 'a');
         int u = getp(B[i] - 'a');
         if (v != u) {
            par[u] = v;
         }
      }
      vector<bool> alive(20);
      for (int i = 0; i < N; ++i) alive[getp(A[i] - 'a')] = true;
      int ans = 0;
      for (int i = 0; i < 20; ++i) if (alive[getp(i)] && par[i] != i) {
         ans++;
      }
      if (fail) ans = -1;
      cout << ans << "\n";
   }
}