#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
#define fir first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define ull unsigned long long
#define cl(a, b) memset(a, b, sizeof(a))
#define quickio(a) ios::sync_with_stdio(a)
#define datatest() freopen("data.in", "r", stdin)
#define pii pair<int, int>
#define pdd pair<double, double>
#define makeans() freopen("data.out", "w", stdout)
using namespace std;
const int maxn = 1e2 + 10;
const int maxm = 1e6 + 10;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int maxblock = sqrt(maxn) + 10;
const double eps = 1e-7;
const ll INF = 1e16;
int n;
int a[maxn];
set<int> s;
vector<pair<int, int>> seg;
int dp[maxn][maxn][maxn];
int check(int pos, int flag) {
  if (pos < 1 || pos > n) return 0;
  return (a[pos] % 2) != flag;
}
int main() {
  quickio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    s.insert(i);
  }
  for (int i = 1; i <= n; i++) s.erase(a[i]);
  int odd = 0, even = 0;
  for (auto it : s) {
    if (it % 2)
      odd++;
    else
      even++;
  }
  int seg_num = 0;
  int pre = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] != 0) {
      if (seg_num) {
        seg.pb(mp(pre, i - 1));
        seg_num = 0;
      }
    } else {
      if (!seg_num) {
        pre = i;
      }
      seg_num++;
    }
  }
  if (seg_num) {
    seg.pb(mp(pre, n));
  }
  if (seg.size() == 0) {
    int ans = 0;
    for (int i = 2; i <= n; i++) {
      ans += ((a[i] % 2) != (a[i - 1] % 2));
    }
    cout << ans << endl;
    return 0;
  }
  if (seg.size() == 1 && seg[0].fir == 1 && seg[0].se == n) {
    if (n != 1)
      std::cout << 1 << std::endl;
    else
      cout << 0 << endl;
    return 0;
  }
  cl(dp, inf);
  int cnt = seg.size();
  dp[0][odd][even] = 0;
  for (int i = 1; i <= seg.size(); i++) {
    for (int j = 0; j <= odd; j++) {
      for (int k = 0; k <= even; k++) {
        for (int len = 0; len <= seg[i - 1].se - seg[i - 1].fir + 1; len++) {
          int tot = seg[i - 1].se - seg[i - 1].fir + 1;
          if (len > j) continue;
          if (tot - len > k) continue;
          if (len == 0)
            dp[i][j - len][k - (tot - len)] =
                min(dp[i][j - len][k - (tot - len)],
                    dp[i - 1][j][k] + check(seg[i - 1].fir - 1, 0) +
                        check(seg[i - 1].se + 1, 0));
          else if (len == tot) {
            dp[i][j - len][k - (tot - len)] =
                min(dp[i][j - len][k - (tot - len)],
                    dp[i - 1][j][k] + check(seg[i - 1].fir - 1, 1) +
                        check(seg[i - 1].se + 1, 1));
          } else {
            dp[i][j - len][k - (tot - len)] =
                min(dp[i][j - len][k - (tot - len)],
                    dp[i - 1][j][k] + check(seg[i - 1].fir - 1, 1) +
                        check(seg[i - 1].se + 1, 0) + 1);
          }
        }
        for (int len = 0; len <= seg[i - 1].se - seg[i - 1].fir + 1; len++) {
          int tot = seg[i - 1].se - seg[i - 1].fir + 1;
          if (len > k) continue;
          if (tot - len > j) continue;
          if (len == 0)
            dp[i][j - (tot - len)][k - (len)] =
                min(dp[i][j - (tot - len)][k - (len)],
                    dp[i - 1][j][k] + check(seg[i - 1].fir - 1, 1) +
                        check(seg[i - 1].se + 1, 1));
          else if (len == tot) {
            dp[i][j - (tot - len)][k - (len)] =
                min(dp[i][j - (tot - len)][k - (len)],
                    dp[i - 1][j][k] + check(seg[i - 1].fir - 1, 0) +
                        check(seg[i - 1].se + 1, 0));
          } else {
            dp[i][j - (tot - len)][k - (len)] =
                min(dp[i][j - (tot - len)][k - (len)],
                    dp[i - 1][j][k] + check(seg[i - 1].fir - 1, 0) +
                        check(seg[i - 1].se + 1, 1) + 1);
          }
        }
      }
    }
  }
  int Min = inf;
  for (int i = 0; i <= odd; i++) {
    for (int j = 0; j <= even; j++) {
      Min = min(Min, dp[seg.size()][i][j]);
    }
  }
  for (int i = 2; i <= n; i++) {
    if (a[i] && a[i - 1]) {
      Min += ((a[i] % 2) != (a[i - 1] % 2));
    }
  }
  cout << Min << "\n";
  return 0;
}