#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
//int timer = 1;

int testNumber = 1;

bool todo = true;

int main() {
#ifdef AIM
    freopen("/home/alexandero/ClionProjects/ACM/input.txt", "r", stdin);
    //freopen("/home/alexandero/ClionProjects/ACM/output.txt", "w", stdout);
    //freopen("out.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;
    cout.sync_with_stdio(0);
    cin.tie(0);
    precalc();
    cout.precision(10);
    cout << fixed;
    //cin >> t;
    int testNum = 1;
    while (t--) {
        //cerr << testNum << endl;
        //cout << "Case #" << testNum++ << ": ";
        solve(true);
        ++testNumber;
        //++timer;
    }
#ifdef AIM1
    while (true) {
        solve(false);
    }
#endif

#ifdef AIM
    cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

template<typename T>
T binpow(T q, T w, T mod) {
    if (!w)
        return 1 % mod;
    if (w & 1)
        return q * 1LL * binpow(q, w - 1, mod) % mod;
    return binpow(q * 1LL * q % mod, w / 2, mod);
}

template<typename T>
T gcd(T q, T w) {
    while (w) {
        q %= w;
        swap(q, w);
    }
    return q;
}
template<typename T>
T lcm(T q, T w) {
    return q / gcd(q, w) * w;
}

void precalc() {

}

//#define int li
//const int mod = 1000000007;

const int INF = (int)1e9;

int dp[90][90][90][2];

void relax(int& cur, int val) {
  cur = min(cur, val);
}

void solve(bool read) {
  int n, k;
  cin >> n >> k;
  vector<vector<pair<int, int>>> g(n + 1);
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    g[a].push_back({b, c});
  }

  if (k == 1) {
    cout << 0 << endl;
    return;
  }

  if (k > n) {
    cout << "-1\n";
    return;
  }

  for (int i = 0; i <= n + 1; ++i) {
    for (int j = 0; j <= n + 1; ++j) {
      for (int r = 0; r <= max(n, k) + 1; ++r) {
        for (int p = 0; p < 2; ++p) {
          dp[i][j][r][p] = INF;
        }
      }
    }
  }
  for (int len = 1; len <= n; ++len) {
    for (int l = 0; l + len <= n + 1; ++l) {
      int r = l + len;
      dp[l][r][0][0] = dp[l][r][0][1] = 0;
      for (int used = 1; used < k; ++used) {
        if (l > 0)
        for (auto item : g[l]) {
          int nex = item.first;
          if (nex > l && nex < r) {
            relax(dp[l][r][used][0], dp[l][nex][used - 1][1] + item.second);
            relax(dp[l][r][used][0], dp[nex][r][used - 1][0] + item.second);
          }
        }
        if (r <= n)
        for (auto item : g[r]) {
          int nex = item.first;
          if (nex > l && nex < r) {
            relax(dp[l][r][used][1], dp[l][nex][used - 1][1] + item.second);
            relax(dp[l][r][used][1], dp[nex][r][used - 1][0] + item.second);
          }
        }
        //cout << l << ' ' << r << ' ' << used << ' ' << dp[l][r][used][0] << ' ' << dp[l][r][used][1] << endl;
      }
    }
  }

  int ans = INF;
  for (int l = 0; l <= n; ++l) {
    for (int r = l + 1; r <= n + 1; ++r) {
      ans = min(ans, dp[l][r][k - 1][0]);
      ans = min(ans, dp[l][r][k - 1][1]);
    }
  }

  if (ans > INF / 10) {
    cout << "-1\n";
    return;
  }

  cout << ans << endl;

}