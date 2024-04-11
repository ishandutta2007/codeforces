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

void solve(bool read) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  vector<int> rows, cols;
  int mn = 1000;
  for (int i = 0; i < m; ++i) {
    mn = min(mn, a[0][i]);
  }
  for (int i = 0; i < m; ++i) {
    int add = a[0][i] - mn;
    for (int r = 0; r < add; ++r) {
      cols.push_back(i);
    }
    for (int j = 0; j < n; ++j) {
      a[j][i] -= add;
    }
  }

  mn = 1000;
  for (int i = 0; i < n; ++i) {
    mn = min(mn, a[i][0]);
  }
  if (mn < 0) {
    cout << "-1\n";
    return;
  }
  for (int i = 0; i < n; ++i) {
    int add = a[i][0] - mn;
    for (int r = 0; r < add; ++r) {
      rows.push_back(i);
    }
    for (int j = 0; j < m; ++j) {
      a[i][j] -= add;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] != a[0][0]) {
        cout << "-1\n";
        return;
      }
    }
  }
  int cur_val = a[0][0];
  if (cur_val < 0) {
    cout << "-1\n";
    return;
  }
  if (n < m) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0;j  < cur_val; ++j) {
        rows.push_back(i);
      }
    }
  } else {
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < cur_val; ++j) {
        cols.push_back(i);
      }
    }
  }

  cout << rows.size() + cols.size() << endl;
  for (int x : rows) {
    cout << "row " << x + 1 << endl;
  }
  for (int x : cols) {
    cout << "col " << x + 1 << endl;
  }

}