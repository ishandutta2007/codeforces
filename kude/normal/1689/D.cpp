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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    constexpr int INF = 1001001001;
    int mx1 = -INF, mx2 = -INF, mn1 = INF, mn2 = INF;
    rep(i, n) rep(j, m) if (s[i][j] == 'B') {
      chmax(mx1, i - j);
      chmin(mn1, i - j);
      chmax(mx2, i + j);
      chmin(mn2, i + j);
    }
    int ans = INF;
    int ans_i = -1, ans_j = -1;
    rep(i, n) rep(j, m) {
      int x = i - j, y = i + j;
      if (chmin(ans, max({abs(x - mx1), abs(x - mn1), abs(y - mx2), abs(y - mn2)}))) {
        ans_i = i, ans_j = j;
      }
    }
    cout << ans_i + 1 << ' ' << ans_j + 1 << '\n';
  }
}