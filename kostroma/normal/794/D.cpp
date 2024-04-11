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

void precalc() {

}

//const int mod = 1000000007;

//#define int li

bool has_elem(vector<int>& cur, int val) {
  auto it = lower_bound(all(cur), val);
  return it != cur.end() && *it == val;
}

void solve(bool read) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 0; i < n; ++i) {
    sort(all(g[i]));
  }

  int cur_start = 0;
  for (int i = 0; i < n; ++i) {
    if (g[i].size() > 1) {
      cur_start = i;
    }
  }
  vector<int> clique;
  clique.push_back(cur_start);
  for (int v : g[cur_start]) {
    bool f = true;
    for (int x : clique) {
      if (!has_elem(g[v], x)) {
        f = false;
        break;
      }
    }
    if (f) {
      clique.push_back(v);
    }
  }
  sort(all(clique));
  if (clique.size() == n) {
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
      cout << "1 ";
    }
    cout << endl;
    return;
  }

  if (clique.size() == g[cur_start].size() + 1) {
    for (int v : clique) {
      if (g[v].size() >= clique.size()) {
        cur_start = v;
        break;
      }
    }
    clique.clear();
    clique.push_back(cur_start);
    for (int v : g[cur_start]) {
      bool f = true;
      for (int x : clique) {
        if (!has_elem(g[v], x)) {
          f = false;
          break;
        }
      }
      if (f) {
        clique.push_back(v);
      }
    }
    sort(all(clique));
  }

  vector<int> rest;
  for (int v : g[cur_start]) {
    if (has_elem(clique, v)) {
      continue;
    }
    rest.push_back(v);
  }
  vector<int> zeroes;
  for (int v : rest) {
    for (int to : g[v]) {
      if (has_elem(clique, to)) {
        zeroes.push_back(to);
      }
    }
  }
  sort(all(zeroes));
  zeroes.erase(unique(all(zeroes)), zeroes.end());
  vector<int> ones;
  for (int v : clique) {
    if (!has_elem(zeroes, v)) {
      ones.push_back(v);
    }
  }

  vector<vector<int>> starts = {ones, rest};
  const int INF = (int)1e9;
  vector<int> res(n, INF);
  for (int x : zeroes) {
    res[x] = 0;
  }
  for (int x : ones) {
    res[x] = 1;
  }
  for (int x : rest) {
    res[x] = -1;
  }

  /*for (int i = 0; i < n; ++i) {
    cout << res[i] << " ";
  }
  cout << endl;*/

  int sign = 1;
  for (int it = 0; it < 2; ++it, sign *= -1) {
    queue<int> q;
    for (int x : starts[it]) {
      q.push(x);
    }
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int to : g[v]) {
        if (res[to] == INF) {
          res[to] = res[v] + sign;
          q.push(to);
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    assert(res[i] != INF);
  }

  for (int i = 0; i < n; ++i) {
    for (int to : g[i]) {
      if (abs(res[to] - res[i]) > 1) {
        cout << "NO" << endl;
        return;
      }
    }
  }

  li overall_edges = 0;
  map<int, int> num;
  for (int i = 0; i < n; ++i) {
    assert(res[i] != INF);
    ++num[res[i]];
  }
  for (auto item : num) {
    overall_edges += item.second * 1LL * (item.second - 1) / 2;
    int nex = item.first + 1;
    auto it = num.find(nex);
    if (it != num.end()) {
      overall_edges += item.second * 1LL * it->second;
    }
  }

  if (overall_edges != m) {
    cout << "NO" << endl;
    return;
  }


  int mn = INF;
  for (int i = 0; i < n; ++i) {
    mn = min(mn, res[i]);
  }
  for (int i = 0; i < n; ++i) {
    res[i] = res[i] - mn + 1;
  }

  cout << "YES" << endl;
  for (int x : res) {
    cout << x << " ";
  }
  cout << endl;

}