#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

using namespace __gnu_pbds;
tree<P, null_type, less<P>, rb_tree_tag, tree_order_statistics_node_update> s;
int a[1000010];
VI to[1000010];
struct EV {
  int i, l, k;
};
vector<EV> qs[1000010];
int ans[1000010];
int cnt[1000010];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, q;
    cin >> n >> q;
    rep(i, n) to[i].clear();
    rep(i, n) qs[i].clear();
    rep(i, n) cin >> a[i];
    for(int i = 1; i < n; i++) {
      int pi;
      cin >> pi;
      pi--;
      to[pi].push_back(i);
    }
    rep(i, q) {
      int v, l, k;
      cin >> v >> l >> k;
      qs[v - 1].push_back({i, l, k});
    }
    auto dfs = [&](auto&& self, int u) -> void {
      int x = a[u];
      if (cnt[x]) s.erase({cnt[x], x});
      cnt[x]++;
      s.insert({cnt[x], x});
      for(auto [i, l, k] : qs[u]) {
        int pos = s.order_of_key({l, -1}) + k - 1;
        if (pos >= s.size()) {
          ans[i] = -1;
        } else {
          ans[i] = s.find_by_order(pos)->second;
        }
      }
      for(int v: to[u]) self(self, v);
      s.erase({cnt[x], x});
      cnt[x]--;
      if (cnt[x]) s.insert({cnt[x], x});
    };
    dfs(dfs, 0);
    rep(i, q) cout << ans[i] << " \n"[i + 1 == q];
  }
}