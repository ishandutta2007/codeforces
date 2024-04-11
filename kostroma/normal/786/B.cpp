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

  /*while (true) {
      solve(false);
  }*/

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

#define int li

//const int mod = 1000000007;

int shift = 1;

vector<vector<pair<int, int>>> g;

void add_edge(int v, int tl, int tr, int from, int l, int r, bool rev, int wei) {
  if (tr <= l || r <= tl) {
    return;
  }
  if (l <= tl && tr <= r) {
    if (rev) {
      g[v + 2 * shift].push_back({from + shift + 2 * shift, wei});
    } else {
      g[from + shift].push_back({v, wei});
    }
    return;
  }
  int tm = (tl + tr) / 2;
  add_edge(2 * v, tl, tm, from, l, r, rev, wei);
  add_edge(2 * v + 1, tm, tr, from, l, r, rev, wei);
}

void solve(bool read) {
  int n, Q, start;
  cin >> n >> Q >> start;
  --start;
  while (shift < n) {
    shift *= 2;
  }
  g.resize(4 * shift);
  for (int it = 0; it < Q; ++it) {
    int type;
    cin >> type;
    if (type == 1) {
      int a, b, w;
      cin >> a >> b >> w;
      --a; --b;
      add_edge(1, 0, shift, a, b, b + 1, false, w);
    } else {
      int from, l, r, w;
      cin >> from >> l >> r >> w;
      --from;
      --l;
      add_edge(1, 0, shift, from, l, r, type == 3, w);
    }
  }
  for (int i = 0; i < n; ++i) {
    g[i + shift].push_back({i + shift + 2 * shift, 0});
    g[i + shift + 2 * shift].push_back({i + shift, 0});
  }
  for (int i = 1; i < shift; ++i) {
    g[i].push_back({2 * i, 0});
    g[i].push_back({2 * i + 1, 0});
    g[2 * i + 2 * shift].push_back({i + 2 * shift, 0});
    g[2 * i + 1 + 2 * shift].push_back({i + 2 * shift, 0});
  }

  vector<int> dist(g.size(), 1e18);
  dist[start + shift] = 0;
  set<pair<int, int>> have;
  have.insert({0, start + shift});
  while (!have.empty()) {
    auto item = *have.begin();
    have.erase(have.begin());
    //cout << item.second << " " << item.first << endl;
    for (auto e : g[item.second]) {
      int to = e.first;
      int cur_dist = item.first + e.second;
      if (dist[to] > cur_dist) {
        have.erase({dist[to], to});
        dist[to] = cur_dist;
        have.insert({dist[to], to});
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    int ans = dist[i + shift];
    if (ans > 1e17) {
      cout << "-1 ";
    } else {
      cout << ans << " ";
    }
  }

}