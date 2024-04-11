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

int cnt[2000];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  constexpr int INF = 1001001001;
  rep(i, 2000) cnt[i] = INF;
  cnt[1] = 0;
  for (int i = 1; i < 1000; i++) {
    for (int x = 1; x <= i; x++) {
      chmin(cnt[i + i / x], cnt[i] + 1);
    }
  }
  // cout << * max_element(dp + 1, dp + 1001) << endl;
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k;
    cin >> n >> k;
    k = min(k, 12 * n);
    VI b(n), c(n);
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];
    VI dp(k + 1);
    rep(i, n) {
      int w = cnt[b[i]], v = c[i];
      for (int i = k - w; i >= 0; i--) {
        chmax(dp[i + w], dp[i] + v);
      }
    }
    cout << dp[k] << '\n';
  }
}