#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
/*#if !defined(YCM) && 0
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx,tune=native")
#include <stdio.h>
#endif*/
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

template <typename T>
void make_unique(vector<T>& a) {
    sort(all(a));
    a.erase(unique(all(a)), a.end());
}

template<typename T>
void relax_min(T& cur, T val) {
    cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
    cur = max(cur, val);
}

void precalc() {}

//#define int li
//const int mod = 1000000007;

const int INF = (int)1e9;

vector<vector<int>> comps;

vector<vector<int>> g;

void dfs(int v, int p) {
  comps.back().push_back(v);
  for (int to : g[v]) {
    if (to == p) {
      continue;
    }
    dfs(to, v);
  }
}

void solve(bool read) {
  int n;
  //read = false;
  if (read) {
    cin >> n;
  } else {
    n = 50;
  }
  g.clear();
  comps.clear();
  g.resize(n);
  vector<vector<int>> matrix(n, vector<int>(n, INF));
  for (int i = 0; i < n; ++i) {
    matrix[i][i] = 0;
  }
  for (int i = 1; i < n; ++i) {
    int a,b, cost;
    if (read) {
      cin >> a >> b >> cost;
      --a;
      --b;
    } else {
      a = i;
      b = i - 1;
      cost = rand() % 50 + 1;
    }
    g[a].push_back(b);
    g[b].push_back(a);
    matrix[a][b] = matrix[b][a] = cost;
  }
  int root;
  if (read) {
    cin >> root;
    --root;
  } else {
    root = rand() % n;
  }
  int m;
  if (read) {
    cin >> m;
  } else {
    m = 50;
  }
  vector<int> x(m);
  for (int i = 0; i < m; ++i) {
    if (read) {
      cin >> x[i];
      --x[i];
    } else {
      do {
        x[i] = rand() % n;
      } while (x[i] == root);
    }
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
      }
    }
  }

  vector<vector<int>> dp(m + 1, vector<int>(n, 0));
  for (int have = 1; have <= m; ++have) {

    for (int i = 0; i < n; ++i) {
      if (g[i].size() > 1) {
        continue;
      }

      for (int j = 0; j < n; ++j) {
        if (g[j].size() == 1) {
          dp[have][i] = max(dp[have][i], matrix[i][j]);
        }
      }

      int L = dp[have][i], R = (int)INF;
      while (L + 1 < R) {
        int M = (L + R) / 2;
        int can = 0;
        for (int j = 0; j < n; ++j) {
          if (g[j].size() == 1 && i != j) {
            for (int use = 0; use < have; ++use) {
              if (dp[use][j] + matrix[i][j] >= M) {
                can += have - use;
                break;
              }
            }
          }
        }
        if (can >= have) {
          L = M;
        } else {
          R = M;
        }
      }
      dp[have][i] = L;
      //cout << have << " " << i << " " << dp[have][i] << endl;
    }
  }

  for (int to : g[root]) {
    comps.push_back(vector<int>());
    dfs(to, root);
  }

  vector<int> bad(comps.size());
  for (int g : x) {
    for (int i = 0; i < comps.size(); ++i) {
      for (int num : comps[i]) {
        if (num == g) {
          ++bad[i];
          break;
        }
      }
    }
  }

  int L = 0, R = INF;
  while (L + 1 < R) {
    int M = (L + R) / 2;
    bool good = true;
    for (int i = 0; i < comps.size(); ++i) {
      int can = 0;
      for (int j : comps[i]) {
        if (g[j].size() == 1) {
          for (int rest = m - bad[i]; rest < m; ++rest) {
            if (dp[rest][j] + matrix[root][j] >= M) {
              can += m - rest;
              break;
            }
          }
        }
      }
      if (can < bad[i]) {
        good = false;
        break;
      }
    }
    if (good) {
      L = M;
    } else {
      R = M;
    }
  }

  cout << L << endl;

}