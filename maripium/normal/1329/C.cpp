#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int T;
   cin >> T;
   while (T--) {
      int H, G;
      cin >> H >> G;
      int N = (1 << H) - 1;
      vector<int> A(2 * N + 1);
      for (int i = 0; i < N; ++i) cin >> A[i];
      function<bool(int, int)> can = [&](int v, int d) {
         int l = v * 2 + 1;
         int r = v * 2 + 2;
         assert(r < A.size());
         if (A[l] == 0 && A[r] == 0) return d > G;
         if (A[l] > A[r]) return can(l, d + 1);
         return can(r, d + 1);
      };
      function<void(int)> modify = [&](int v) {
         int l = v * 2 + 1;
         int r = v * 2 + 2;
         if (A[l] == 0 && A[r] == 0) {
            A[v] = 0;
            return;
         }
         if (A[l] > A[r]) {
            A[v] = A[l];
            modify(l);
         } else {
            A[v] = A[r];
            modify(r);
         }
      };
      vector<int> steps;
      function<void(int, int)> go = [&](int v, int d) {
         if (A[v] == 0) return;
         while (can(v, d)) {
            steps.emplace_back(v);
            modify(v);
         }
         go(v * 2 + 1, d + 1);
         go(v * 2 + 2, d + 1);
      };
      go(0, 1);
      long long sum = accumulate(A.begin(), A.end(), 0LL);
      cout << sum << "\n";
      for (int v : steps) cout << v + 1 << " "; cout << "\n";
   }
}