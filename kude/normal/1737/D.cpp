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

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> es(m);
    vector<vector<P>> to(n);
    constexpr int INF = 1001001001;
    VVI dist(n, VI(n, INF));
    rep(i, n) dist[i][i] = 0;
    for(auto& [u, v, w]: es) {
      cin >> u >> v >> w;
      u--, v--;
      dist[u][v] = dist[v][u] = 1;
    }
    rep(k, n) rep(i, n) rep(j, n) chmin(dist[i][j], dist[i][k] + dist[k][j]);
    VI dist2(n);
    rep(i, n) dist2[i] = dist[i][0] + dist[i][n-1];
    VI dist3(n, INF);
    rep(i, n) {
      rep(j, n) chmin(dist3[i], dist[i][j] + dist2[j]);
    }
    constexpr long long LINF = 1002003004005006007;
    ll ans = LINF;
    for(auto [u, v, w]: es) {
      rep(_, 2) {
        chmin(ans, ll(w) * min(dist[u][0] + dist[v][n-1] + 1, 2 + dist3[u]));
        swap(u, v);
      }
    }
    cout << ans << '\n';
  }
}