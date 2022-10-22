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
  int tt = 1;
  while(tt--) {
    int n;
    cin >> n;
    VL a(n);
    rep(i, n) cin >> a[i];
    ll ans = 1.1e18;
    for(int i = 0; i < n; i++) {
      ll cnt = 0;
      {
        ll now = 0;
        for(int j = i + 1; j < n; j++) {
          ll k = now / a[j] + 1;
          cnt += k;
          now = a[j] * k;
        }
      }
      {
        ll now = 0;
        for(int j = i - 1; j >= 0; j--) {
          ll k = now / a[j] + 1;
          cnt += k;
          now = a[j] * k;
        }
      }
      chmin(ans, cnt);
    }
    cout << ans << '\n';
  }
}