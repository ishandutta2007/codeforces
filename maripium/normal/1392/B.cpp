#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int T; cin >> T;
   while (T--) {
      int N; int64_t K; cin >> N >> K;
      vector<int64_t> A(N);
      for (int64_t &x : A) cin >> x;
      int64_t mx = *max_element(A.begin(), A.end());
      --K;
      for (int64_t &x : A) x = mx - x;
      if (K & 1) {
         mx = *max_element(A.begin(), A.end());
         for (int64_t &x : A) x = mx - x;
      }
      for (int64_t &x : A) cout << x << ' '; cout << '\n';
   }
}