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
    VI b(n);
    rep(i, n) cin >> b[i];
    vector<tuple<int, int, int>> d; d.reserve(n);
    rep(i, n) {
      int l = (i+1) / (b[i]+1) + 1;
      int r = (b[i] ? (i+1) / b[i] : n);
      d.emplace_back(l, r, i);
    }
    sort(all(d), [](const tuple<int, int, int>& x, const tuple<int, int, int>& y) {
      return get<1>(x) < get<1>(y);
    });
    VI idx(n);
    iota(all(idx), 1);
    set<int> st(all(idx));
    VI ans(n);
    for(auto [l, r, i]: d) {
      auto it = st.lower_bound(l);
      ans[i] = *it;
      st.erase(it);
    }
    rep(i, n) cout << ans[i] << " \n"[i + 1 == n];
  }
}