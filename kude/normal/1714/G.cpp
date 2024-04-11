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
    vector<vector<tuple<int, int, int>>> to(n);
    for(int i = 1; i < n; i++) {
      int p, a, b;
      cin >> p >> a >> b;
      p--;
      to[p].emplace_back(i, a, b);
    }
    VI ans(n);
    VL st{0};
    auto dfs = [&](auto self, int u, ll sa) -> void {
      ans[u] = upper_bound(all(st), sa) - st.begin() - 1;
      for(auto [v, a, b]: to[u]) {
        st.emplace_back(st.back() + b);
        self(self, v, sa + a);
        st.pop_back();
      }
    };
    dfs(dfs, 0, 0);
    for(int i = 1; i < n; i++) cout << ans[i] << " \n"[i + 1 == n];
  }
}