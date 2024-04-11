#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N, M; cin >> N >> M;
   const int X = 1e6;
   vector<int> H(X+2, -1);
   vector<int> A(N), B(N);
   for (int i = 0; i < N; ++i) cin >> A[i] >> B[i];
   for (int i = 0; i < M; ++i) {
      int c, d; cin >> c >> d;
      H[c] = max(H[c], d);
   }
   for (int i = X; i >= 0; --i) H[i] = max(H[i], H[i+1]);
   vector<pair<int, int>> kek;
   for (int i = X+1; i >= 0; --i) {
      if (i == 0 || H[i] < H[i-1]) {
         kek.emplace_back(H[i], i);
      }
   }
   reverse(kek.begin(), kek.end());
   M = kek.size();
   vector<vector<pair<int, int>>> changes(X+2);
   for (int i = 0; i < N; ++i) {
      int cur = -1;
      int fj = -1;
      for (int j = 0; j < M; ++j) {
         if (kek[j].second > A[i]) {
            cur = max(0, kek[j-1].first + 1 - B[i]);
            fj = j;
            break;
         }
      }
      if (fj == -1) continue;
      changes[0].emplace_back(cur, i);
      for (int j = fj; j < M; ++j) {
         int right = kek[j].second - A[i];
         int up = max(0, kek[j].first +1 - B[i]);
         changes[right].emplace_back(up, i);
      }
   }
   vector<int> val(N, -1);
   multiset<int> ms;
   int ans = X+X;
   for (int r = 0; r <= X+1; ++r) {
      for (auto q : changes[r]) {
         int v, i; tie(v, i) = q;
         if (val[i] != -1) ms.erase(ms.find(val[i]));
         val[i] = v;
         ms.emplace(val[i]);
      }
      int mx = (ms.empty() ? 0 : *ms.rbegin());
      ans = min(ans, r + mx);
   }
   cout << ans << '\n';
   return 0;
}