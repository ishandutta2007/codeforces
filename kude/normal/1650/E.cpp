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
    int n, d;
    cin >> n >> d;
    VI a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    constexpr int INF = 1001001001;
    int mn = INF, imn = -1;
    rep(i, n) if (a[i + 1] - a[i] < mn) {
      mn = a[i + 1] - a[i];
      imn = i;
    }
    int ans = -1;
    for(int j : {imn, imn + 1}) if (j) {
      VI b = a;
      b.erase(b.begin() + j);
      assert((int)b.size() == n);
      int mn = INF;
      rep(i, n - 1) chmin(mn, b[i + 1] - b[i]);
      int mx = min(mn, d - b[n - 1]);
      rep(i, n - 1) {
        int c = (b[i] + b[i + 1]) / 2;
        chmax(mx, min(mn, c - b[i]));
      }
      chmax(ans, mx);
    }
    cout << ans - 1 << '\n';
  }
}