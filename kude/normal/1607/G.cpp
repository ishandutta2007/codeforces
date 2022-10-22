#include<bits/stdc++.h>
namespace {
using namespace std;
#define rep(i,n)for (int i = 0; i < int(n); ++i)
#define rrep(i,n)for (int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& ai, const T& bi) {ai = max(ai, bi);}
template<class T> void chmin(T& ai, const T& bi) {ai = min(ai, bi);}
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
    int n, m;
    cin >> n >> m;
    VI mx(n);
    VI a(n), b(n);
    vector<P> d(n);
    rep(i, n) {
      int ai, bi;
      cin >> ai >> bi;
      a[i] = ai, b[i] = bi;
      if (m <= ai) {
        d[i] = {ai - m, bi};
        mx[i] = min(m, bi);
      } else {
        d[i] = {0, bi - (m - ai)};
        mx[i] = min(ai, bi - (m - ai));
      }
    }
    ll sm = 0;
    for(auto [ai, bi]: d) sm += ai - bi;
    rep(i, n) {
      if (sm >= 0) break;
      int r = min<ll>(mx[i], -(sm / 2));
      sm += 2 * r;
      d[i].first += r;
      d[i].second -= r;
    }
    cout << abs(sm) << '\n';
    rep(i, n) {
      cout << a[i] - d[i].first << ' ' << b[i] - d[i].second << '\n';
    }
  }
}