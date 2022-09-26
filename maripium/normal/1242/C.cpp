#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using Transfer = tuple<int, int, ll>;

int N;
ll delta[15];
vector<ll> arr[15];
map<ll, int> where;
ll sum;
vector<Transfer> dp[1 << 15];

int main() {
   ios_base::sync_with_stdio(false);
   cin >> N;
   for (int i = 0; i < N; ++i) {
      int sz;
      cin >> sz;
      arr[i].resize(sz);
      for (ll &v : arr[i]) {
         cin >> v;
         sum += v;
         delta[i] -= v;
         where[v] = i;
      }
   }
   if (sum % N) {
      cout << "No\n";
      return 0;
   }
   sum /= N;
   for (int i = 0; i < N; ++i) {
      delta[i] += sum;
   }
   for (int i = 0; i < N; ++i) {
      for (ll v : arr[i]) {
         int mask = 0;
         int cur = i;
         ll curPop = v;
         vector<Transfer> curDp;
         do {
            if (mask & (1 << cur)) {
               goto nxtV;
            }
            mask |= (1 << cur);
            ll nxtPop = curPop + delta[cur];
            if (!where.count(nxtPop)) {
               goto nxtV;
            }
            int nxt = where[nxtPop];
            curDp.emplace_back(nxt, cur, nxtPop);
            cur = nxt;
            curPop = nxtPop;
         } while (cur != i);
         if (curPop != v) goto nxtV;
         dp[mask] = curDp;
         nxtV:;
      }
   }

   for (int mask = 1; mask < (1 << N); ++mask) {
      if (dp[mask].size()) {
         continue;
      }

      for (int sub = mask & (mask - 1); sub > 0; sub = (sub - 1) & mask) {
         int nsub = mask ^ sub;
         if (dp[sub].size() && dp[nsub].size()) {
            for (int csub : {sub, nsub}) {
               for (auto v : dp[csub]) {
                  dp[mask].emplace_back(v);
               }
            }
            break;
         }
      }
   }

   if (dp[(1 << N ) - 1].empty()) {
      cout << "No\n";
      return 0;
   }

   cout << "Yes\n";

   vector<pair<ll, int>> ans(N);

   for (auto v : dp[(1 << N) - 1]) {
      int from, to;
      ll val;
      tie(from, to, val) = v;
      ans[from] = {val, to};
   }

   for (int i = 0; i < N; ++i) {
      cout << ans[i].first << " " << ans[i].second + 1 << "\n";
   }
}