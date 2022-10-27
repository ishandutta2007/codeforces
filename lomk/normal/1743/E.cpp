/*input
5 10
4 9
16 1




10 1
5000 100000
25 9

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x, y) ((x >> y) & 1)
#define loop(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define rloop(i, l, r) for (int i = (int)l; i >= (int)r; --i)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() { cout << endl; }
template <typename T, typename... Ts>
void print(const T &value, const Ts &...values) {
  cout << value << ' ', print(values...);
}
#endif
const int N = 5005;
const int INF = numeric_limits<int>::max() / 3;

int p1, t1, p2, t2, h, s;
int dp[N];

int cal(int cur) {
  if (cur < 0)
    return 0;
  if (cur == 0)
    return 0;

  int &ret = dp[cur];
  if (ret != -1)
    return ret;
  ret = INF;

  auto calDamage1 = [&](int j) {
    int k = (j * t1) / t2;
    if (k >= 1) {
      return (j - 1) * max(p1 - s, 0LL) + (k - 1) * max(p2 - s, 0LL) +
             max(p1 + p2 - s, 0LL);
    }

    else {
      return j * max(p1 - s, 0LL);
    }
  };

  loop(j, 1, cur) { ret = min(ret, cal(cur - calDamage1(j)) + j * t1); }

  auto calDamage2 = [&](int j) {
    int k = (j * t2) / t1;
    if (k >= 1) {
      return (j - 1) * max(p2 - s, 0LL) + (k - 1) * max(p1 - s, 0LL) +
             max(p1 + p2 - s, 0LL);
    } else {
      return j * max(p2 - s, 0LL);
    }
  };

  loop(j, 1, cur) { ret = min(ret, cal(cur - calDamage2(j)) + j * t2); }

  return ret;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> p1 >> t1 >> p2 >> t2;
  cin >> h >> s;
  memset(dp, -1, sizeof(dp));

  // loop(i,1,25) cout << i << sp << cal(i) << endl;
  cout << cal(h) << endl;
}