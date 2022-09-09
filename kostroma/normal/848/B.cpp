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

//#define int li
//const int mod = 1000000007;

struct Guy {
  int g;
  int x, t;
  int id;
  bool operator < (const Guy& ot) const {
    return x < ot.x;
  }
};

void solve(bool read) {
  int n, w, h;
  cin >> n >> w >> h;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    p[i] = i;
  }
  vector<Guy> all_guys;
  map<int, vector<Guy>> vert, hor;
  for (int i = 0; i < n; ++i) {
    int g, x, t;
    cin >> g >> x >> t;
    all_guys.push_back({g, x, t, i});
    if (g == 1) {
      vert[x - t].push_back({g, x, t, i});
    } else {
      hor[x - t].push_back({g, x, t, i});
    }
  }

  for (auto& ver : vert) {
    sort(all(ver.second));
    if (!hor.count(ver.first)) {
      continue;
    }
    auto& ho = hor[ver.first];
    sort(all(ho));
    reverse(all(ho));

    vector<int> order;
    for (auto up : ver.second) {
      order.push_back(up.id);
    }
    for (auto lef : ho) {
      order.push_back(lef.id);
    }
    vector<int> new_order;
    for (auto lef : ho) {
      new_order.push_back(lef.id);
    }
    for (auto up : ver.second) {
      new_order.push_back(up.id);
    }

    for (int i = 0; i < new_order.size(); ++i) {
      p[new_order[i]] = order[i];
    }
  }

  vector<pair<int, int>> ans(n);
  for (int i = 0; i < all_guys.size(); ++i) {
    int res_p = p[i];
    int res_x, res_y;
    if (all_guys[res_p].g == 1) {
      res_x = all_guys[res_p].x;
      res_y = h;
    } else {
      res_x = w;
      res_y = all_guys[res_p].x;
    }
    ans[i] = {res_x, res_y};
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i].first << " " << ans[i].second << "\n";
  }

}