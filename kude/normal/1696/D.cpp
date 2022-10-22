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
    VI a(n);
    rep(i, n) cin >> a[i], a[i]--;
    constexpr int INF = 1001001001;
    VI st_inc{0}, st_dec{0};
    VI dp(n);
    dp[0] = 0;
    for(int i = 1; i < n; i++) {
      if (a[i-1] > a[i]) {
        while(st_inc.size() && a[st_inc.back()] > a[i]) st_inc.pop_back();
        int l = st_inc.empty() ? 0 : st_inc.back() + 1;
        dp[i] = dp[*lower_bound(all(st_dec), l)] + 1;
      } else {
        while(st_dec.size() && a[st_dec.back()] < a[i]) st_dec.pop_back();
        int l = st_dec.empty() ? 0 : st_dec.back() + 1;
        dp[i] = dp[*lower_bound(all(st_inc), l)] + 1;
      }
      st_inc.emplace_back(i);
      st_dec.emplace_back(i);
    }
    cout << dp[n-1] << '\n';
  }
}