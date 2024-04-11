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
    VI b(n);
    rep(i, n) cin >> b[i];
    int mx = 0;
    rep(i, n) mx += max(a[i], b[i]);
    mx++;
    constexpr ll INF = 1002003004005006007;
    VL dp(mx, INF);
    dp[0] = 0;
    int sm = 0;
    ll ans = 0;
    rep(i, n) {
      ans += (n - 1) * (a[i] * a[i] + b[i] * b[i]);
      rrep(sa, mx) if (dp[sa] != INF) {
        int sb = sm - sa;
        rep(_, 2) {
          chmin(dp[sa + a[i]], dp[sa] + sa * a[i] + sb * b[i]);
          swap(a[i], b[i]);
        }
        dp[sa] = INF;
      }
      sm += a[i] + b[i];
    }
    ans += 2 * *min_element(all(dp));
    cout << ans << '\n';
  }
}