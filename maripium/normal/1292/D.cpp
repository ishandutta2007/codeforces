#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int MAXV = 5050;

bool np[MAXV];
vector<int> pr;

void precalc() {
   for (int i = 2; i < MAXV; ++i) {
      if (!np[i]) {
         pr.emplace_back(i);
         for (int j = i + i; j < MAXV; j += i) {
            np[j] = true;
         }
      }
   }
}

vector<int> fact(int x) {
   vector<int> ans;
   for (int p : pr) {
      int nx = x;
      int cur = 0;
      while (nx) cur += (nx /= p);
      ans.emplace_back(cur);
   }
   reverse(ans.begin(), ans.end());
   return ans;
}

vector<int> lca(const vector<int> &v, const vector<int> &u) {
   vector<int> ans(v.size());
   for (int i = 0; i < int(ans.size()); ++i) {
      ans[i] = min(v[i], u[i]);
      if (v[i] != u[i]) {
         break;
      }
   }
   return ans;
}

bool isAnc(const vector<int> &v, const vector<int> &u) {
   return lca(v, u) == v;
}

int getDist(const vector<int> &v, const vector<int> &u) {
   return accumulate(u.begin(), u.end(), 0) - accumulate(v.begin(), v.end(), 0);
}

int cnt[MAXV];
int cnt1[MAXV * 2];
int sz[MAXV * 2];
int dist[MAXV * 2];
vector<pair<int, int>> adj[MAXV * 2];

void dfs1(int v) {
   sz[v] = cnt1[v];
   for (auto e : adj[v]) {
      dfs1(e.first);
      sz[v] += sz[e.first];
   }
}

void dfs2(int v, int p, int dist, ll &ans) {
   ans += ll(cnt1[v]) * dist;
   for (auto e : adj[v]) {
      if (e.first != p) {
         dfs2(e.first, v, dist + e.second, ans);
      }
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   precalc();
   int N;
   cin >> N;
   for (int i = 0; i < N; ++i) {
      int z;
      cin >> z;
      z = max(z, 1);
      ++cnt[z];
   }
   vector<vector<int>> nodes;
   for (int i = 1; i < MAXV; ++i) {
      if (cnt[i]) {
         nodes.emplace_back(fact(i));
      }
   }
   sort(nodes.begin(), nodes.end());
   for (int i = int(nodes.size()) - 1; i > 0; --i) {
      nodes.emplace_back(lca(nodes[i], nodes[i - 1]));
   }
   sort(nodes.begin(), nodes.end());
   nodes.resize(unique(nodes.begin(), nodes.end()) - nodes.begin());
   vector<int> st;
   st.emplace_back(0);
   for (int i = 1; i < int(nodes.size()); ++i) {
      while (!isAnc(nodes[st.back()], nodes[i])) {
         st.pop_back();
      }
      adj[st.back()].emplace_back(i, getDist(nodes[st.back()], nodes[i]));
      st.emplace_back(i);
   }
   for (int i = 1; i < MAXV; ++i) {
      if (cnt[i]) {
         int v = lower_bound(nodes.begin(), nodes.end(), fact(i)) - nodes.begin();
         cnt1[v] += cnt[i];
      }
   }
   dfs1(0);
   int root = 0;
   while (true) {
      int found = -1;
      for (auto e : adj[root]) {
         if (2 * sz[e.first] > N) {
            found = e.first;
         }
      }
      if (~found) {
         root = found;
      } else {
         break;
      }
   }
   
   vector<tuple<int, int, int>> edges;
   ll ans = 0;
   for (int i = 0; i < int(nodes.size()); ++i) {
      for (auto e : adj[i]) {
         edges.emplace_back(e.first, i, e.second);
      }
   }
   for (auto e : edges) {
      adj[get<0>(e)].emplace_back(get<1>(e), get<2>(e));
   }
   dfs2(root, -1, 0, ans);
   cout << ans << "\n";
   return 0;
}