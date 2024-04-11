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
    int rest = n;
    rep(i, n) {
      int x;
      cin >> x;
      rest -= __builtin_ctz(x);
    }
    int ans = 0;
    int k = 31 - __builtin_clz(n);
    int k2 = 1 << k;
    while(rest > 0 && k) {
      for(int i = 1; i * k2 <= n && rest > 0; i += 2) {
        ans++;
        rest -= k;
      }
      k--;
      k2 /= 2;
    }
    if (rest > 0) ans = -1;
    cout << ans << '\n';
  }
}