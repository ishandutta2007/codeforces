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

const unsigned long long INF = 1002003004005006007;
template<class T>
std::vector<unsigned long long> dijkstra(std::vector<std::vector<std::pair<int,T>>>& to, int s=0) {
    struct QueElem {
        int v;
        unsigned long long c;
        bool operator<(const QueElem a) const {return c > a.c;}
        QueElem(int v, unsigned long long c): v(v), c(c) {}
    };
    std::priority_queue<QueElem> q;
    std::vector<unsigned long long> dist(to.size(), INF);
    dist[s] = 0;
    q.emplace(s, 0);
    while(!q.empty()) {
        QueElem qe = q.top(); q.pop();
        int u = qe.v;
        unsigned long long c = qe.c;
        if (c > dist[u]) continue;
        for(auto vc: to[u]) {
            int v = vc.first;
            unsigned long long nc = c + vc.second;
            if (nc < dist[v]) {
                dist[v] = nc;
                q.emplace(v, nc);
            }
        }
    }
    return dist;
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<int, ll>>> to(n + 1);
  rep(i, m) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    to[u].emplace_back(v, w);
    to[v].emplace_back(u, w);
  }
  to[n].resize(n);
  rep(i, n) to[n][i] = {i, INF};
  auto dist = dijkstra(to);
  rep(_, k) {
    auto nd = dist;
    auto dfs = [&](auto self, int L, int R, int l, int r) -> void {
      if (L == R) return;
      int C = (L + R) / 2;
      auto mn = INF;
      int imn = -1;
      for(int i = l; i < r; i++) {
        ll d = i - C;
        if (chmin(mn, dist[i] + d * d)) {
          imn = i;
        }
      }
      nd[C] = mn;
      self(self, L, C, l, imn + 1);
      self(self, C + 1, R, imn, r);
    };
    dfs(dfs, 0, n, 0, n);
    rep(i, n) to[n][i].second = nd[i];
    dist = dijkstra(to, n);
  }
  rep(i, n) cout << dist[i] << " \n"[i + 1 == n];
}