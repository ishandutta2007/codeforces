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
  freopen("/home/alexandero/CLionProjects/ACM/input.txt", "r", stdin);
  //freopen("/home/alexandero/CLionProjects/ACM/output.txt", "w", stdout);
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
  cout.precision(20);
  cout << fixed;
  //cin >> t;
  while (t--) {
    solve(true);
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
void make_unique(vector<T>& vec) {
  sort(all(vec));
  vec.erase(unique(all(vec)), vec.end());
}

template<typename T>
void relax_min(T& cur, T val) {
  cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
  cur = max(cur, val);
}

void precalc() {

}

#define int li
const int mod = 1000000007;

vector<vector<int>> g;
int dp[111][111][111];
vector<int> cnt;

void add(int& cur, int val) {
  cur += val;
  cur %= mod;
}

void dfs(int v, int p) {
  cnt[v] = 1;
  vector<int> children;
  for (int to : g[v]) {
    if (to == p) {
      continue;
    }
    dfs(to, v);
    children.push_back(to);
  }

  vector<vector<int>> cur_dp(cnt[v] + 1, vector<int>(cnt[v] + 1, 0));
  cur_dp[0][1] = 1;
  for (int to : children) {
    vector<vector<int>> new_dp(cnt[v] + cnt[to] + 1, vector<int>(cnt[v] + cnt[to] + 1, 0));
    for (int comps = 0; comps < cur_dp.size(); ++comps) {
      for (int last_comp = 0; last_comp < cur_dp[comps].size(); ++last_comp) {
        if (cur_dp[comps][last_comp] == 0) continue;
        for (int new_comps = 0; new_comps <= cnt[to]; ++new_comps) {
          for (int new_last = 0; new_last <= cnt[to]; ++new_last) {
            if (dp[to][new_comps][new_last] == 0) continue;
            int add_val = cur_dp[comps][last_comp] * dp[to][new_comps][new_last] % mod;

            add(new_dp[comps + new_comps + 1][last_comp], add_val * new_last);
            add(new_dp[comps + new_comps][last_comp + new_last], add_val);
          }
        }
      }
    }
    cnt[v] += cnt[to];
    new_dp.swap(cur_dp);
  }
  for (int comps = 0; comps <= cnt[v]; ++comps) {
    for (int last = 0; last <= cnt[v]; ++last) {
      dp[v][comps][last] = cur_dp[comps][last];
      if (dp[v][comps][last]) {
        //cout << v + 1 << " " << comps << " " << last << " " << dp[v][comps][last] << endl;
      }
    }
  }
}

const int C = 210;
int c[C][C];

void solve(bool read) {
  for (int i = 0; i < C; ++i) {
    c[i][i] = c[i][0] = 1;
    for (int j = 1; j < i; ++j) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
  }
  int n;
  //read = false;
  if (read) {
    cin >> n;
  } else {
    n = 100;
  }
  g.resize(n);
  for (int i = 1; i < n; ++i) {
    int a, b;
    if (read) {
      cin >> a >> b;
      --a;
      --b;
    } else {
      b = i;
      a = (i - 1) / 2;
      a = i - 1;
    }
    g[a].push_back(b);
    g[b].push_back(a);
  }
  cnt.assign(n, 0);
  dfs(0, 0);
  vector<int> ans(n + 1, 0);
  vector<int> powers(n + 1, 1);
  for (int i = 1; i < powers.size(); ++i) {
    powers[i] = powers[i - 1] * n % mod;
  }
  ans[n - 1] = 1;
  for (int comps = 1; comps < n; ++comps) {
    for (int last = 0; last <= n; ++last) {
      int k = n - comps - 1;
      int add_val = last * dp[0][comps][last] % mod * powers[comps - 1] % mod;
      if (add_val) {
        //cout << k << " " << add_val << " " << comps << " " << last << endl;
      }
      add(ans[k], add_val);
    }
  }
  vector<int> res(n);
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      int add_val = c[j][i] * ans[j] % mod;
      if (i % 2 == j % 2) {
        res[i] += add_val;
      } else {
        res[i] -= add_val;
      }
      res[i] %= mod;
      if (res[i] < 0) {
        res[i] += mod;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << res[i] << " \n"[i + 1 == n];
  }

}