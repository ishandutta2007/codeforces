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
    int n, m;
    cin >> m >> n;
    VVI a(n, VI(m));
    rep(j, m) rep(i, n) cin >> a[i][j];
    if (n - 1 >= m) {
      int ans = 1001001001;
      rep(i, n) {
        int mx = 0;
        rep(j, m) chmax(mx, a[i][j]);
        chmin(ans, mx);
      }
      cout << ans << '\n';
      continue;
    }
    int l = 0, r = 1001001001;
    while(r - l > 1) {
      int c = (r + l) >> 1;
      bool ok = true;
      rep(i, n) {
        bool found = false;
        rep(j, m) if (a[i][j] >= c) {
          found = true;
          break;
        }
        if (!found) {
          ok = false;
          break;
        }
      }
      if (!ok) {
        r = c;
        continue;
      }
      ok = false;
      rep(j, m) {
        bool found = false;
        rep(i, n) if (a[i][j] >= c) {
          if (found) {
            ok = true;
            break;
          } else {
            found = true;
          }
        }
        if (ok) break;
      }
      if (ok) l = c;
      else r = c;
    }
    cout << l << '\n';
  }
}