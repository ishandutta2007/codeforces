#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAXN = 100100;
const ll INF = 1e18;

int N, M;
vector<pair<int, int>> adj[MAXN];
int nxt[MAXN];
set<ll> st[MAXN];
vector<ll> trains[MAXN];
vector<pair<ll, ll>> changes;

void dfs(int v, ll dist) {
   int big = 0;
   for (auto e : adj[v]) {
      int u, d;
      tie(u, d) = e;
      dfs(u, dist + d);
      if (u == nxt[v]) {
         st[u].emplace(-dist);
      }
      if (st[u].size() > st[big].size()) big = u;
   }
   if (big) st[v].swap(st[big]);
   vector<pair<ll, int>> vals;
   for (auto e : adj[v]) {
      int u, d; tie(u, d) = e;
      if (u == big) continue;
      for (ll z : st[u]) vals.emplace_back(z, u);
   }
   sort(vals.begin(), vals.end());
   for (int i = 0; i < int(vals.size()); ++i) {
      ll prv = -INF;
      if (i && vals[i - 1].second != vals[i].second) {
         prv = max(prv, vals[i - 1].first);
      }
      auto it = st[v].lower_bound(vals[i].first);
      if (it != st[v].begin()) {
         auto lt = prev(it);
         if (!i || vals[i - 1].first < *lt) prv = *lt;
      }
      if (prv > -INF) {
         changes.emplace_back(dist + prv + 1, dist + vals[i].first);
//          cerr << "ADD " << changes.back().first << " " << changes.back().second << "\n";
      }
      if (it != st[v].end()) {
         if (i + 1 == int(vals.size()) || vals[i + 1].first >= *it) {
            changes.emplace_back(dist + vals[i].first + 1, dist + (*it));
//            cerr << "ADD " << changes.back().first << " " << changes.back().second << "\n";
         }
      }
   }
   for (auto z : vals) st[v].emplace(z.first);
   for (ll z : trains[v]) st[v].emplace(ll(z));
   if (adj[v].size()) st[v].erase(-dist);
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   cin >> N >> M;
   for (int i = 0; i < N - 1; ++i) {
      int v, u, d;
      cin >> v >> u >> d;
      adj[v].emplace_back(u, d);
      nxt[v] = u;
   }
   for (int i = 0; i < M; ++i) {
      int s; ll t;
      cin >> s >> t;
      trains[s].emplace_back(t);
   }
   dfs(1, 0ll);
   ll ans = -1;
   sort(changes.begin(), changes.end());
   ll cur = 0;
   multiset<ll> rs;
   int ptr = 0;
   for (int i = 0; i < int(changes.size()); ++i) {
      if (rs.empty())  cur = changes[ptr].first;
      while (ptr < int(changes.size()) && changes[ptr].first == cur) rs.emplace(changes[ptr++].second);
      rs.erase(rs.begin());
      if (rs.size() && *rs.begin() == cur) {
         ans = cur;
         break;
      }
      cur++;
   }
   int cnt = 0;
   for (auto z : changes) cnt += (ans == -1 || z.second < ans);
   cout << ans << " " << cnt << "\n";
   return 0;
}