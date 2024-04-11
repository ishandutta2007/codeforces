#include<bits/stdc++.h>
namespace {
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};
const int di2[] = {1, 1, -1, -1};
const int dj2[] = {1, -1, 1, -1};

constexpr int INF = 1001001001;
template <int k = 2, class T>  // cost in [0, k)
pair<vector<int>, vector<int>> kBFS(const vector<vector<pair<int, T>>>& g, int s = 0) {
  static_assert(k >= 1);
  const int n = g.size();
  vector<int> dist(n, INF);
  vector<int> pre(n, -1);
  vector<int> q[2 * k];
  dist[s] = 0;
  q[0].emplace_back(s);
  for (int dist_cur = 0, ptr = 0;;) {
    const auto qb = q + ptr;
    while (!qb[0].empty()) {
      int u = qb[0].back();
      qb[0].pop_back();
      if (dist[u] != dist_cur) continue;
      for (auto [v, c] : g[u]) {
        int nd = dist_cur + c;
        if (nd < dist[v]) {
          dist[v] = nd;
          pre[v] = u;
          qb[c].emplace_back(v);
        }
      }
    }
    do {
      dist_cur++;
      ptr++;
      if (ptr == 2 * k) return {move(pre), move(dist)};
    } while (q[ptr].empty());
    if (ptr > k) {
      for (int i = ptr; i < 2 * k; i++) {
        swap(q[i], q[i - ptr]);
      }
      ptr = 0;
    }
  }
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    auto idxchk = [&](int i, int j) { return 0 <= i && i < n && 0 <= j && j < m; };
    auto visitable = [&](int i, int j) {
      if (!idxchk(i, j)) return false;
      rep(k, 4) {
        int ni = i + di[k], nj = j + dj[k];
        if (!idxchk(ni, nj)) continue;
        if (s[ni][nj] == '#') return false;
      }
      return true;
    };
    vector<vector<pair<int, bool>>> to(n * m + 2);
    int src = n * m, dest = src + 1;
    rep(i, n) {
      if (visitable(i, 0)) to[src].emplace_back(i * m, s[i][0] == '.');
      if (visitable(i, m - 1)) to[i * m + m - 1].emplace_back(dest, 0);
    }
    rep(i, n) rep(j, m) {
      rep(k, 4) {
        int ni = i + di2[k], nj = j + dj2[k];
        if (!visitable(ni, nj)) continue;
        to[i * m + j].emplace_back(ni * m + nj, s[ni][nj] == '.');
      }
    }
    auto [pre, dist] = kBFS(to, src);
    if (dist[dest] == INF) {
      cout << "NO\n";
      continue;
    }
    vector<vector<pair<int, bool>>> to_inv(n * m + 2);
    rep(i, n * m + 2) for(auto [j, c]: to[i]) to_inv[j].emplace_back(i, c);
    int v = pre[dest];
    while(v != src) {
      int i = v / m, j = v % m;
      s[i][j] = '#';
      v = pre[v];
    }
    cout << "YES\n";
    rep(i, n) cout << s[i] << '\n';
  }
}