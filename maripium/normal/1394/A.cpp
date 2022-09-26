#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N, D, M; cin >> N >> D >> M;
   vector<int> big;
   vector<int> small;
   for (int i = 0; i < N; ++i) {
      int x; cin >> x;
      if (x > M) big.emplace_back(x);
      else small.emplace_back(x);
   }
   sort(big.rbegin(), big.rend());
   sort(small.rbegin(), small.rend());
   int B = big.size();
   int S = small.size();
   vector<int64_t> prefB(B + 1);
   vector<int64_t> prefS(S + 1);
   for (int i = 0; i < B; ++i) prefB[i+1] = prefB[i]+big[i];
   for (int i = 0; i < S; ++i) prefS[i+1] = prefS[i]+small[i];
   int64_t ans = 0;
   for (int nb = 0; nb <= B; ++nb) {
      if ((nb - 1) * (D + 1) >= N) break;
      int totB = (nb == 0 ? 0 : (nb - 1) * (D + 1) + 1);
      int ns = min(S, N - totB);
      ans = max(ans, prefB[nb] + prefS[ns]);
   }
   cout << ans << endl;
   return 0;
}