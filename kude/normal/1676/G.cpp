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
    VVI to(n);
    for(int i = 1; i < n; i++) {
      int pi;
      cin >> pi;
      pi--;
      to[pi].emplace_back(i);
    }
    string s;
    cin >> s;
    int ans = 0;
    auto dfs = [&](auto&& self, int u) -> P {
      int w = 0, b = 0;
      if (s[u] == 'W') w++;
      else b++;
      for(int v: to[u]) {
        auto [wv, bv] = self(self, v);
        w += wv;
        b += bv;
      }
      ans += w == b;
      return {w, b};
    };
    dfs(dfs, 0);
    cout << ans << '\n';
  }
}