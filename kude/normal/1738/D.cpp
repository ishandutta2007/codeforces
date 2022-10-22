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
    int n;
    cin >> n;
    VVI to(n + 2);
    for(int i = 1; i <= n; i++) {
      int p;
      cin >> p;
      to[p].emplace_back(i);
    }
    int u;
    bool large;
    if (to[0].size()) {
      u = 0;
      large = false;
    } else {
      u = n + 1;
      large = true;
    }
    VI ans;
    int k = 0;
    while(true) {
      int u_nxt = -1;
      for(int v: to[u]) {
        if (large) chmax(k, v);
        if (to[v].size()) u_nxt = v;
      }
      if (u_nxt == -1) {
        ans.insert(ans.end(), all(to[u]));
        break;
      }
      for(int v: to[u]) if (v != u_nxt) {
        ans.emplace_back(v);
      }
      ans.emplace_back(u_nxt);
      u = u_nxt;
      large = !large;
    }
    cout << k << '\n';
    rep(i, n) cout << ans[i] << " \n"[i + 1 == n];
  }
}