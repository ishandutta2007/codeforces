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
    //cout << "Case #" << testNum++ << ": ";
    //cerr << testNum << endl;
    solve(true);
    //cerr << testNum - 1 << endl;
  }
  cout.flush();
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

template<typename T>
void relax_min(T& cur, T val) {
  cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
  cur = max(cur, val);
}

//#define int li
//const int mod = 1000000007;

vector<int> sum(vector<int> a, vector<int> b, int sign) {
  vector<int> res(a.size());
  for (int i = 0; i < a.size(); ++i) {
    res[i] = a[i] + sign * b[i];
  }
  return res;
}

vector<int> max_price, min_price;
vector<vector<int>> g;
vector<int> cnt;

const int C = 5010;
li dp[2][C][C];
const li INF = (li)2e9;

enum {
  USUAL = 0,
  ACT = 1
};

void dfs(int v) {
  dp[USUAL][v][0] = dp[ACT][v][0] = 0;
  dp[USUAL][v][1] = max_price[v];
  dp[ACT][v][1] = min_price[v];
  cnt[v] = 1;
  for (int to : g[v]) {
    dfs(to);
    for (int sz = cnt[v]; sz >= 0; --sz) {
      for (int new_sz = 1; new_sz <= cnt[to]; ++new_sz) {
        relax_min(dp[USUAL][v][sz + new_sz], dp[USUAL][v][sz] + dp[USUAL][to][new_sz]);
        if (sz) {
          relax_min(dp[ACT][v][sz + new_sz], dp[ACT][v][sz] + dp[USUAL][to][new_sz]);
          relax_min(dp[ACT][v][sz + new_sz], dp[ACT][v][sz] + dp[ACT][to][new_sz]);
        }
      }
    }
    cnt[v] += cnt[to];
  }
  /*if (v + 1 == 1) {
    cout << v + 1 << endl;
    for (int sz = 0; sz <= 3; ++sz) {
      cout << dp[ACT][v][sz] << " ";
    }
    cout << endl;
  }*/
}

void solve(bool read) {
  int n, b;
  cin >> n >> b;
  max_price.resize(n);
  min_price.resize(n);
  cnt.resize(n);
  g.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> max_price[i] >> min_price[i];
    min_price[i] = max_price[i] - min_price[i];
    if (i) {
      int p;
      cin >> p;
      --p;
      g[p].push_back(i);
    }
  }
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < C; ++j) {
      for (int k = 0; k < C; ++k) {
        dp[i][j][k] = INF;
      }
    }
  }
  dfs(0);

  for (int sz = cnt[0]; sz >= 0; --sz) {
    if (dp[USUAL][0][sz] <= b || dp[ACT][0][sz] <= b) {
      cout << sz << endl;
      return;
    }
  }
  assert(false);

  /*int n;
  for (n = 1; n <= 20; ++n) {
    vector <vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
      a[i] = vector<int>(n, 0);
      a[i][i] = 1;
    }
    int sign = 1;
    for (int it = 1; it < n; ++it) {
      vector <vector<int>> b;
      for (int i = 0; i + 1 < a.size(); ++i) {
        b.push_back(sum(a[i], a[i + 1], sign));
        sign = -sign;
      }
      b.swap(a);
    }
    assert(a.size() == 1);
    cout << "n: " << n << endl;
    for (int i = 0; i < n; ++i) {
      cout << a[0][i] << " ";
    }
    cout << endl;
  }*/

}