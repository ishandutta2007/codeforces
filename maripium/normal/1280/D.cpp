#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int MAXN = 3030;
const pair<int, ll> WORSE = {0, -1e18};

int N, M;
vector<int> adj[MAXN];
ll B[MAXN], W[MAXN];
int sz[MAXN];
pair<int, ll> dp[MAXN][MAXN];
pair<int, ll> ndp[MAXN];

pair<int, ll> operator + (const pair<int, ll> &l, const pair<int, ll> &r) {
   return make_pair(l.first + r.first, l.second + r.second);
}

void Dfs(int v, int p) {
   sz[v] = 1;
   dp[v][0] = {0, W[v] - B[v]};
   for (int u : adj[v]) {
      if (u != p) {
         Dfs(u, v);
         for (int i = 0; i <= sz[v]; ++i) {
            for (int j = 0; j <= sz[u]; ++j) {
               ndp[i + j] = max(ndp[i + j], dp[v][i] + dp[u][j]);
            }
         }
         sz[v] += sz[u];
         for (int i = 0; i <= sz[v]; ++i) {
            dp[v][i] = ndp[i];
            ndp[i] = WORSE;
         }
       }
   }
   if (v > 0) {
      for (int i = sz[v] - 1; i >= 0; --i) {
         dp[v][i + 1] = max(dp[v][i + 1], make_pair(dp[v][i].first + (dp[v][i].second > 0), 0LL));
      }
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   int T;
   cin >> T;
   for (int i = 0; i < MAXN; ++i) {
      for (int j = 0; j < MAXN; ++j) {
         dp[i][j] = WORSE;
      }
      ndp[i] = WORSE;
   }
   while (T--) {
      int N, M;
      cin >> N >> M;
      for (int i = 0; i < N; ++i) {
         cin >> B[i];
      }
      for (int i = 0; i < N; ++i) {
         cin >> W[i];
      }
      for (int i = 0; i < N - 1; ++i) {
         int v, u;
         cin >> v >> u;
         --v, --u;
         adj[v].emplace_back(u);
         adj[u].emplace_back(v);
      }
      Dfs(0, -1);
      auto val = dp[0][M - 1];
      cout << val.first + (val.second > 0) << "\n";
      for (int i = 0; i < N; ++i) {
         adj[i] = {};
      }
      for (int i = 0; i < N; ++i) {
         for (int j = 0; j <= MAXN; ++j) {
            dp[i][j] = WORSE;
         }
      }
   }
}