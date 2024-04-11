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

template <typename T>
void make_unique(vector<T>& a) {
  sort(all(a));
  a.erase(unique(all(a)), a.end());
}

void precalc() {}

template<typename T>
void relax_min(T& cur, T val) {
  cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
  cur = max(cur, val);
}

#define int li
const int mod = 1000000007;

vector<char> used;

vector<int> st;
vector<int> cycle;
vector<vector<int>> g;
int have = 0;

void dfs(int v) {
  ++have;
  for (int to : g[v]) {
    if (used[to]) {
      continue;
    }
    used[to] = true;
    dfs(to);
  }
}

void solve(bool read) {
  int n;
  cin >> n;
  vector<int> edge(2 * n, -1);
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    edge[a] = b;
  }

  n *= 2;

  used.assign(n, false);
  g.resize(n);
  for (int i = 0; i < n; ++i) {
    if (edge[i] != -1) {
      g[edge[i]].push_back(i);
    }
  }
  li res = 1;
  for (int i = 0; i < n; ++i) {
    if (used[i] || edge[i] == -1) {
      continue;
    }
    vector<int> path;
    int cur = i;
    while (cur != -1 && !used[cur]) {
      used[cur] = true;
      path.push_back(cur);
      cur = edge[cur];
    }
    for (int x : path) {
      used[x] = false;
    }
    vector<int> cycle;
    bool is_cycle = cur != -1;
    if (cur != -1) {
      cycle.push_back(cur);
      while (path.back() != cur) {
        cycle.push_back(path.back());
        path.pop_back();
      }
    } else {
      cycle.push_back(path.back());
    }

    for (int x : cycle) {
      used[x] = true;
    }
    int ans = 1;
    have = 0;
    for (int x : cycle) {
      dfs(x);
    }
    if (cycle.size() > 1) {
      ans = ans * 2 % mod;
    } else if (!is_cycle) {
      ans = ans * have % mod;
    }
    res = res * ans % mod;
  }

  cout << res << endl;

}