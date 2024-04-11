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

template<class T, class Compare=less<T>>
pair<vector<array<int, 2>>, int> cartesian_tree(const vector<T>& a) {
  const int n = a.size();
  vector<array<int, 2>> g(n, {-1, -1});
  vector<int> st;
  constexpr Compare cmp;
  for (int i = 0; i < n; i++) {
    int last_popped = -1;
    // Left one wins on tie if Compare = less/greater
    while (!st.empty() && cmp(a[i], a[st.back()])) {
      last_popped = st.back(); st.pop_back();
    }
    g[i][0] = last_popped;
    if (!st.empty()) g[st.back()][1] = i;
    st.emplace_back(i);
  }
  return pair(move(g), st.empty() ? -1 : st[0]);
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    VI a(n);
    rep(i, n) cin >> a[i];
    VL s(n + 1);
    rep(i, n) s[i+1] = s[i] + a[i];
    auto [g, r] = cartesian_tree<int, greater<int>>(a);
    bool ok = true;
    constexpr long long INF = 1002003004005006007;
    auto dfs = [&](auto self, int u) -> tuple<ll, ll> {
      if (u == -1) return {INF, -INF};
      auto [lmn, lmx] = self(self, g[u][0]);
      auto [rmn, rmx] = self(self, g[u][1]);
      chmin(lmn, s[u]);
      chmax(rmx, s[u+1]);
      if (a[u] < rmx - lmn) ok = false;
      return {min(lmn, rmn), max(lmx, rmx)};
    };
    dfs(dfs, r);
    cout << (ok ? "YES\n" : "NO\n");
  }
}