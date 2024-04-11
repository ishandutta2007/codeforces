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
    VVI to(n);
    rep(i, m) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      to[u].emplace_back(v);
      to[v].emplace_back(u);
    }
    int f;
    cin >> f;
    VI h(f);
    rep(i, f) cin >> h[i], h[i]--;
    int k;
    cin >> k;
    VI p(k);
    rep(i, k) cin >> p[i], p[i]--;
  
    using ull = unsigned long long;
    vector<ull> dp(n);
    dp[0] |= 1;

    vector<int> dist(n, -1);
    queue<int> q;
    dist[0] = 0;
    q.push(0);
    while(!q.empty()) {
      int u = q.front(); q.pop();
      int bit = 0;
      rep(i, k) if (h[p[i]] == u) {
        bit |= 1 << i;
      }
      rep(k, 64) if (dp[u] >> k & 1) {
        dp[u] |= 1ULL << (k | bit);
      }
      int nd = dist[u] + 1;
      for(int v: to[u]) {
        if (dist[v] == -1 || dist[v] == nd) {
          dp[v] |= dp[u];
        }
        if (dist[v] == -1) {
          dist[v] = nd;
          q.push(v);
        }
      }
    }
    for(int i: p) h[i] = -1;
    ull now = 1;
    for(int v: h) if (v != -1) {
      ll nxt = 0;
      rep(i, 64) if (now >> i & 1) rep(j, 64) if (dp[v] >> j & 1) {
        nxt |= 1ULL << (i | j);
      }
      now = nxt;
    }
    int ans = 0;
    rep(i, 64) if (now >> i & 1) chmax(ans, __builtin_popcount(i));
    cout << k - ans << '\n';
  }
}