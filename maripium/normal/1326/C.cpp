#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int MOD = 998244353;
const int MAXN = 200200;

int N, K;
int P[MAXN];

int main() {
   ios_base::sync_with_stdio(false);
   cin >> N >> K;
   for (int i = 1; i <= N; ++i) {
      cin >> P[i];
   }
   ll sum = 0;
   vector<int> ps;
   for (int i = 1; i <= N; ++i) {
      if (P[i] > N - K) {
         sum += P[i];
         ps.emplace_back(i);
      }
   }
   int ways = 1;
   for (int i = 0; i + 1 < K; ++i) {
      ways = ll(ways) * (ps[i + 1] - ps[i]) % MOD;
   }
   cout << sum << " " << ways << "\n";
   return 0;
}