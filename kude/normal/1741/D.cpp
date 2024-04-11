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
    int m;
    cin >> m;
    VI p(m);
    rep(i, m) cin >> p[i];
    auto dfs = [&](auto self, int l, int r) -> tuple<int, int, int> {
      if (r - l == 1) return {0, p[l], p[l]};
      int mid = (l + r) / 2;
      auto [cl, lmn, lmx] = self(self, l, mid);
      auto [cr, rmn, rmx] = self(self, mid, r);
      if (cl == -1 || cr == -1 || (lmn < rmx && rmn < lmx)) return {-1, -1, -1};
      int c = cl + cr;
      if (rmx < lmn) c++;
      return {c, min(lmn, rmn), max(lmx, rmx)};
    };
    auto [res, mn, mx] = dfs(dfs, 0, m);
    cout << res << '\n';
  }
}