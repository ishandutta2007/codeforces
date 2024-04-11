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
  int n;
  cin >> n;
  VVI to(n);
  rep(i, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    to[u].emplace_back(v);
    to[v].emplace_back(u);
  }
  if (n == 2) {
    cout << "2 2\n1 1\n";
    return 0;
  }
  struct S {
    int cnt = 0, w = 0;
    bool operator<(const S& rhs) const {
      return cnt < rhs.cnt || (cnt == rhs.cnt && w > rhs.w);
    }
    bool operator>(const S& rhs) const {
      return cnt > rhs.cnt || (cnt == rhs.cnt && w < rhs.w);
    }
    S& operator+=(const S& rhs) {
      cnt += rhs.cnt;
      w += rhs.w;
      return *this;
    }
  };
  vector<pair<S, S>> dp(n);
  auto dfs1 = [&](auto&& self, int u, int p=-1) -> void {
    dp[u].second.cnt++;
    dp[u].second.w += to[u].size();
    for(int v: to[u]) if (v != p) {
      self(self, v, u);
      dp[u].first += max(dp[v].first, dp[v].second);
      dp[u].second += dp[v].first;
    }
  };
  dfs1(dfs1, 0, -1);
  int k;
  int c;
  if (dp[0].first > dp[0].second) {
    k = 0;
    c = dp[0].first.cnt;
  } else {
    k = 1;
    c = dp[0].second.cnt;
  }
  VI ans(n);
  auto dfs2 = [&](auto&& self, int u, int p, int k) -> void {
    if (k == 0) {
      ans[u] = 1;
    } else {
      ans[u] = to[u].size();
    }
    for(int v: to[u]) if (v != p) {
      if (k == 1) {
        self(self, v, u, 0);
      } else {
        if (dp[v].first > dp[v].second) {
          self(self, v, u, 0);
        } else {
          self(self, v, u, 1);
        }
      }
    }
  };
  dfs2(dfs2, 0, -1, k);
  cout << c << ' ' << accumulate(all(ans), 0LL) << '\n';
  rep(i, n) cout << ans[i] << " \n"[i + 1 == n];
}