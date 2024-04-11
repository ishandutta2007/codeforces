#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int T; cin >> T;
   while (T--) {
      int N, K; cin >> N >> K;
      vector<int> A(N); for (int &a : A) cin >> a;
      if (K == 1 && A.front() != A.back()) {
         cout << "-1\n";
         continue;
      }
      A.resize(unique(A.begin(), A.end()) - A.begin());
      N = A.size();
      bool f = true;
      int cur = 0;
      int cnt = 0;
      while (cur < N) {
         int add = K-1+f;
         cur += add;
         cnt++;
         f = false;
      }
      cout << cnt << '\n';
   }
}