#include<bits/stdc++.h>
namespace {
using namespace std;
#define rep(i,n)for (int i = 0; i < int(n); ++i)
#define rrep(i,n)for (int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
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
    int n;
    cin >> n;    
    vector<vector<P>> to(n);
    VI deg(n);
    rep(i, n - 1) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      to[u].emplace_back(v, i);
      to[v].emplace_back(u, i);
      deg[u]++, deg[v]++;
    }
    if (*max_element(all(deg)) > 2) {
      cout << -1 << '\n';
      continue;
    }
    VI ans(n - 1);
    vector<char> visited(n);
    int u = min_element(all(deg)) - deg.begin();
    visited[u] = true;
    int nxt_prime = 2;
    while(true) {
      bool updated = false;
      for(auto [v, i] : to[u]) if (!visited[v]) {
        visited[v] = true;
        ans[i] = nxt_prime;
        nxt_prime ^= 2 ^ 3;
        u = v;
        updated = true;
        break;
      }
      if (!updated) break;
    }
    rep(i, n - 1) cout << ans[i] << " \n"[i + 1 == n - 1];
  }
}