#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

#define ZERO(v) memset((v), 0, sizeof (v))

const int MOD = 1000000007;
const int MAX = 10000;

inline void modadd(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

int main() {
  cin.sync_with_stdio(0);

  int n;
  cin >> n;

  static int dp[2][2*MAX+1];
  int *prev = dp[0], *now = dp[1];
  int csum = 0;

  int ans = 0;
  ZERO(dp);
  for (int i=0; i<n; ++i) {
    memset(now, 0, sizeof dp[0]);

    int val;
    cin >> val;

    now[MAX + val] = now[MAX - val] = 1;
    for (int x=-csum; x<=csum; ++x) {
      modadd(now[MAX + x + val], prev[MAX + x]);
      modadd(now[MAX + x - val], prev[MAX + x]);
    }

    modadd(ans, now[MAX + 0]);
    csum += val;
    swap(prev, now);
  }

  cout << ans << '\n';
  return 0;
}