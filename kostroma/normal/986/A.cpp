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
#ifndef AIM
  cout.sync_with_stdio(0);
  cin.tie(0);
#endif
  cout.precision(20);
  cout << fixed;
  //cin >> t;
  precalc();
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

//#define int li
//const li mod = 1000000007;

//using ull = unsigned long long;

void solve(bool read) {
  int n, m, k, s;
  //read = false;
  if (read) {
    cin >> n >> m >> k >> s;
  } else {
    n = m = 100000;
    k = s = 100;
  }
  vector<vector<int>> lists(k);
  for (int i = 0; i < n; ++i) {
    int cur;
    if (read) {
      cin >> cur;
      --cur;
    } else {
      cur = rand() % k;
    }
    lists[cur].push_back(i);
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    if (read) {
      cin >> a >> b;
      --a;
      --b;
    } else {
      a = rand() % n;
      b = rand() % n;
    }
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<vector<int>> best(n);
  vector<int> dist(n, -1);
  for (int i = 0; i < k; ++i) {
    queue<int> q;
    dist.assign(n, -1);
    for (int x : lists[i]) {
      q.push(x);
      dist[x] = 0;
    }
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int to : g[v]) {
        if (dist[to] == -1) {
          dist[to] = dist[v] + 1;
          q.push(to);
        }
      }
    }
    for (int j = 0; j < n; ++j) {
      best[j].push_back(dist[j]);
    }
  }
  for (int i = 0; i < n; ++i) {
    nth_element(best[i].begin(), best[i].begin() + s, best[i].end());
    //sort(all(best[i]));
    li res = 0;
    for (int j = 0; j < s; ++j) {
      res += best[i][j];
    }
    cout << res << " \n"[i + 1 == n];
  }

}