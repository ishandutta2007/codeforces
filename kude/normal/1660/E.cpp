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
    vector<string> a(n);
    rep(i, n) cin >> a[i];
    int tot = 0;
    rep(i, n) rep(j, n) tot += a[i][j] - '0';
    int c = tot + n;
    int ans = c;
    rep(r, n) {
      int gain = 0;
      for(int i = 0, j = r; i < n; i++, j = (j + 1) % n) {
        gain += a[i][j] - '0';
      }
      chmin(ans, c - 2 * gain);
    }
    cout << ans << '\n';
  }
}