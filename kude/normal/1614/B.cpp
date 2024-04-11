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
    VI a(n);
    rep(i, n) cin >> a[i];
    VI ans(n + 1);
    VI ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) {
      return a[i] > a[j];
    });
    ll tot = 0;
    rep(idx, n) {
      int i = ord[idx];
      int dist = idx / 2 + 1;
      tot += dist * (ll)a[i];
      if (idx % 2 == 0) {
        ans[i + 1] = dist;
      } else {
        ans[i + 1] = -dist;
      }
    }
    cout << tot * 2 << '\n';
    rep(i, n + 1) cout << ans[i] << " \n"[i == n];
  }
}