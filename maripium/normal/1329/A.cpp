#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
   ios_base::sync_with_stdio(false);
   ll N, M;
   cin >> N >> M;
   vector<ll> A(M);
   for (int i = 0; i < M; ++i) cin >> A[i];
   ll sum = 0;
   for (ll &x : A) sum += x;
   if (sum < N) {
      cout << "-1\n";
      return 0;
   }
   ll cur = 0;
   vector<ll> P(M);
   for (int i = 0; i < M; ++i) {
      cur = max(cur, N - sum);
      if (cur > N - A[i]) {
         cout << "-1\n";
         return 0;
      }
      P[i] = cur;
      cur++;
      sum -= A[i];
   }
   for (ll x : P) cout << x + 1 << " ";
}