#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
   ios_base::sync_with_stdio(false);
   int T;
   T = 1;
   // cin >> T;
   while (T--) {
      int N;
      cin >> N;
      vector<ll> X(N), Y(N);
      for (int i = 0; i < N; ++i) {
         cin >> X[i] >> Y[i];
      }
      bool bad = true;
      while (bad) {
         bad = false;
         set<int> z;
         for (int i = 0; i < N; ++i) {
            int cur = 0;
            if (X[i] % 2) {
               cur += 2;
            }
            if (Y[i] % 2) {
                cur += 1;
            }
            z.emplace(cur);
         }
         if (z.size() == 1) {
            bad = true;
            for (int i = 0; i < N; ++i) {
               if (X[i] % 2) {
                  X[i]--;
               }
               if (Y[i] % 2) {
                  Y[i]--;
               }
               X[i] /= 2;
               Y[i] /= 2;
            }
         }
      }
      set<int> pars;
      for (int i = 0; i < N; ++i) {
         int x = (X[i] + Y[i]) % 2;
         if (x < 0) {
            x += 2;
         }
         pars.emplace(x);
      }
      auto f = [&](int id) {
         if (pars.size() == 1) {
            return (X[id] - X[0]) % 2 == 0 && (Y[id] - Y[0]) % 2 == 0;
         } else {
            return (X[id] + Y[id] + X[0] + Y[0]) % 2 == 0;
         }
      };
      vector<int> ans;
      for (int i = 0; i < N; ++i) {
         if (f(i)) ans.emplace_back(i);
      }
      cout << ans.size() << "\n";
      for (int v : ans) {
         cout << v + 1 << " ";
      }
      cout << "\n";
   }
}