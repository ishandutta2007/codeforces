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
    ll ans = 0;
    int n;
    cin >> n;
    VL a(n);
    rep(i, n) cin >> a[i];
    rep(b, 2) {
      ll g = 0;
      for(int i = b; i < n; i += 2) g = gcd(g, a[i]);
      bool ok = true;
      for(int i = 1 ^ b; i < n; i += 2) {
        if (a[i] % g == 0) {
          ok = false;
          break;
        }
      }
      if (ok) {
        ans = g;
        break;
      }
    }
    cout << ans << '\n';
  }
}