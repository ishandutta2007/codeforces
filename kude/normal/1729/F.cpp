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
    string s;
    cin >> s;
    int n = s.size();
    int w, m;
    cin >> w >> m;
    VI acc(n + 1);
    rep(i, n) acc[i+1] = acc[i] + (s[i] - '0');
    int idx[9][2];
    constexpr int INF = 1001001001;
    rep(i, 9) rep(j, 2) idx[i][j] = INF;
    rrep(i, n - w + 1) {
      int r = (acc[i + w] - acc[i]) % 9;
      idx[r][1] = idx[r][0];
      idx[r][0] = i;
    }
    rep(_, m) {
      int l, r, k;
      cin >> l >> r >> k;
      l--;
      int v = (acc[r] - acc[l]) % 9;
      P ans{INF, INF};
      rep(r1, 9) if (idx[r1][0] != INF) rep(r2, 9) if (r1 != r2 && (r1 * v + r2) % 9 == k && idx[r2][0] != INF) {
        chmin(ans, {idx[r1][0], idx[r2][0]});
      }
      rep(r, 9) if ((r * v + r) % 9 == k && idx[r][1] != INF) {
        chmin(ans, {idx[r][0], idx[r][1]});
      }
      if (ans.first == INF) {
        ans = {-2, -2};
      }
      cout << ans.first + 1 << ' ' << ans.second + 1 << '\n';
    }
  }
}