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
    int n, k;
    cin >> n >> k;
    VI a(n);
    rep(i, n) cin >> a[i];
    vector<char> ok(n - 1);
    rep(i, n - 1) ok[i] = a[i] < 2 * a[i + 1];
    n--;
    int now = 0;
    rep(i, k - 1) now += ok[i];
    int ans = 0;
    rep(i, n - k + 1) {
      now += ok[i + k - 1];
      if (now == k) ans++;
      now -= ok[i];
    }
    cout << ans << '\n';
  }
}