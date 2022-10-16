#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

constexpr int N = 3e3;
uint16_t a[N], lst[N], nxt[N], cnxt[19], dp[N][N];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i], --a[i];
    }
    memset(lst, 0, n * sizeof *lst);
    for (int i = 0; i < n; ++i) {
      ++lst[a[i]];
    }
    int w = -1, r = 0, purged = 0;
    while (r < n) {
      if (w >= 0 && a[w] == a[r]) {
        if (--lst[a[r++]] == 1) {
          --w;
          ++purged;
        }
      } else if (lst[a[r]] == 1) {
        ++r;
        ++purged;
      } else {
        a[++w] = a[r++];
      }
    }
    memset(lst, -1, n * sizeof *lst);
    n = w + 1;
    memset(nxt, 127, n * sizeof *nxt);
    for (int i = 0; i < n; ++i) {
      if (lst[a[i]] != (uint16_t)-1) {
        nxt[lst[a[i]]] = i;
      }
      lst[a[i]] = i;
    }
    for (int i = n - 1; i > -1; --i) {
      {
        auto* cnxte = cnxt;
        for (int z = nxt[i]; z < n; z = nxt[z]) {
          *cnxte++ = z;
        }
        cnxte = cnxt;
      }
      int cs = sizeof cnxt / sizeof *cnxt;
      for (int j = i + 1; j < n && cs >= 0; ++j) {
        if (a[j] == a[i]) {
          --cs;
        }
        int t = dp[i + 1][j] - 1;
        const auto* z = cnxt;
        enum R {_00 = 0, _01, _02, _03, _04, _05, _06, _07, _08, _09, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19};
        switch (static_cast<R>(cs)) {
          case _00: t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z; [[fallthrough]];
          case _01: t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z; [[fallthrough]];
          case _02: t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z; [[fallthrough]];
          case _03: t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z; [[fallthrough]];
          case _04: t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z; [[fallthrough]];
          case _05: t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z; [[fallthrough]];
          case _06: t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z; [[fallthrough]];
          case _07: t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z; [[fallthrough]];
          case _08: t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z; [[fallthrough]];
          case _09: t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z; [[fallthrough]];
          case _10: t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z; [[fallthrough]];
          case _11: t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z; [[fallthrough]];
          case _12: t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z; [[fallthrough]];
          case _13: t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z; [[fallthrough]];
          case _14: t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z; [[fallthrough]];
          case _15: t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z; [[fallthrough]];
          case _16: t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z; [[fallthrough]];
          case _17: t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z; [[fallthrough]];
          case _18: t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z; [[fallthrough]];
          case _19:;
        }
        dp[i][j] = t + 1;
      }
    }
    cout << (n? n - dp[0][n - 1]: 0) - 1 + purged << '\n';;
  }
}