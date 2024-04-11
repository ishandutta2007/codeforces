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

int a[100000];
int e[100000], t[100000], p[100000];
VI d[100000];
int dp[100001][200];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> e[i] >> t[i] >> p[i], e[i]--;
    rep(i, n) d[i].clear();
    rep(i, m) d[e[i]].emplace_back(i);
    int time = 0;
    VI ans;
    bool ok = true;
    rep(i, n) {
      constexpr int INF = 1001001001;
      const int sz = d[i].size();
      rep(idx, sz + 1) rep(i, 200) dp[idx][i] = INF;
      dp[0][0] = 0;
      int idx = 0;
      for(int j: d[i]) {
        memcpy(dp[idx + 1], dp[idx], sizeof(dp[idx]));
        rrep(cur_p, 100) {
          int new_p = cur_p + p[j];
          chmin(dp[idx+1][new_p], dp[idx][cur_p] + t[j]);
        }
        idx++;
      }
      int now = min_element(dp[idx] + 100, dp[idx] + 200) - dp[idx];
      time += dp[idx][now];
      if (time > a[i]) {
        ok = false;
        break;
      }
      for(; idx > 0;) {
        idx--;
        int j = d[i][idx];
        if (int pre = now - p[j]; pre >= 0 && dp[idx][pre] + t[j] == dp[idx + 1][now]) {
          ans.emplace_back(j);
          now = pre;
        }
      }
    }
    if (!ok) {
      cout << -1 << '\n';
    } else {
      int sz = ans.size();
      cout << sz << '\n';
      rep(i, sz) cout << ans[i] + 1 << " \n"[i + 1 == sz];
    }
  }
}