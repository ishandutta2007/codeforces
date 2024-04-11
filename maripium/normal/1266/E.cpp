#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int MAXN = 200200;

int N, Q;
int A[MAXN];
map<pair<int, int>, int> buff;
int buffTo[MAXN];

int main() {
   ios_base::sync_with_stdio(false);
   cin >> N;
   ll sum = 0;
   for (int i = 1; i <= N; ++i) {
      cin >> A[i];
      sum += A[i];
   }
   cin >> Q;
   ll ans = 0;
   for (int i = 1; i <= Q; ++i) {
      int s, t, u;
      cin >> s >> t >> u;
      if (buff.count({s, t})) {
         int u2 = buff[{s, t}];
         if (u2) {
            ans -= min(buffTo[u2], A[u2]);
            --buffTo[u2];
            ans += min(buffTo[u2], A[u2]);
         }
      }
      buff[{s, t}] = u;
      if (u) {
         ans -= min(buffTo[u], A[u]);
         ++buffTo[u];
         ans += min(buffTo[u], A[u]);
      }
      cout << sum - ans << "\n";
   }
}