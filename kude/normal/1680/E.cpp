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
    string s[2];
    rep(i, 2) cin >> s[i];
    int jmn = -1, jmx = -1;
    rep(j, n) rep(i, 2) if (s[i][j] == '*') {
      if (jmn == -1) jmn = j;
      jmx = j;
    }
    using A = array<int, 4>;
    A dp{};
    constexpr int INF = 1001001001;
    for(int j = jmn; j <= jmx; j++) {
      A ndp;
      rep(b, 4) ndp[b] = INF;
      rep(b, 4) rep(nb, 4) if (b & nb) {
        chmin(ndp[nb], dp[b] + __builtin_popcount(nb));
      }
      rep(i, 2) if (s[i][j] == '*') {
        rep(b, 4) if (!(b >> i & 1)) ndp[b] = INF;
      }
      dp = ndp;
    }
    cout << *min_element(all(dp)) - 1 << '\n';
  }
}