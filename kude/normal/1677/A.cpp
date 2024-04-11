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

int cnt_f[5010][5010], cnt_b[5010][5010];
int p[5010];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    rep(i, n) cin >> p[i];
    rep(i, n) {
      int cnt = 0;
      int x = p[i];
      rep(j, n) {
        if (p[j] < x) cnt++;
        cnt_f[i][j+1] = cnt;
      }
      cnt = 0;
      cnt_b[i][n] = 0;
      rrep(j, n) {
        if (p[j] < x) cnt++;
        cnt_b[i][j] = cnt;
      }
    }
    ll ans = 0;
    rep(c, n) rep(b, c) {
      ans += cnt_f[c][b] * cnt_b[b][c+1];
    }
    cout << ans << '\n';
  }
}