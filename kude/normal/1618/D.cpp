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
    int n, k;
    cin >> n >> k;
    VI a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    int ans = 0;
    rep(i, n - 2 * k) ans += a[i];
    int pre = -1;
    int mx = 0;
    int now = 0;
    for(int i = n - 2 * k; i < n; i++) {
      if (a[i] != pre) {
        pre = a[i];
        now = 1;
      } else {
        now++;
      }
      chmax(mx, now);
    }
    ans += max(0, mx - k);
    cout << ans << '\n';
  }
}