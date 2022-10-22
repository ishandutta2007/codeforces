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
    VI k(n), h(n);
    rep(i, n) cin >> k[i];
    rep(i, n) cin >> h[i];
    vector<P> lr(n);
    rep(i, n) lr[i] = {k[i] - h[i] + 1, k[i] + 1};
    sort(all(lr));
    constexpr int INF = 1001001001;
    lr.emplace_back(INF, INF);
    int l_cur = -1, r_cur = -1;
    ll ans = 0;
    for(auto [l, r] : lr) {
      if (l < r_cur) {
        chmax(r_cur, r);
        continue;
      }
      ll len = r_cur - l_cur;
      ans += (1 + len) * len / 2;
      l_cur = l;
      r_cur = r;
    }
    cout << ans << '\n';
  }
}