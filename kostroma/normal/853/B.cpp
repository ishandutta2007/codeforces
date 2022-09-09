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
//const int mod = 1000000007;

struct Flight {
  int id;
  int cost;
};

const int C = 1005000;

const int INF = (int)1e18;

void solve(bool read) {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<Flight>> from(C), to(C);
  for (int i = 0; i < m; ++i) {
    int day, a, b, cost;
    cin >> day >> a >> b >> cost;
    if (a == 0) {
      to[day].push_back({b - 1, cost});
    } else {
      from[day].push_back({a - 1, cost});
    }
  }

  vector<int> pref_sums(C, INF), suf_sums(C, INF);
  vector<int> best_way(n, INF);
  int sum_best = 0;
  int cnt_good = 0;
  for (int i = 0; i < C; ++i) {
    for (auto fl : from[i]) {
      if (best_way[fl.id] > fl.cost) {
        if (best_way[fl.id] == INF) {
          ++cnt_good;
        } else {
          sum_best -= best_way[fl.id];
        }
        best_way[fl.id] = fl.cost;
        sum_best += best_way[fl.id];
      }
    }
    if (cnt_good == n) {
      pref_sums[i] = sum_best;
    }
  }

  best_way.assign(n, INF);
  sum_best = 0;
  cnt_good = 0;
  for (int i = C - 1; i >= 0; --i) {
    for (auto fl : to[i]) {
      if (best_way[fl.id] > fl.cost) {
        if (best_way[fl.id] == INF) {
          ++cnt_good;
        } else {
          sum_best -= best_way[fl.id];
        }
        best_way[fl.id] = fl.cost;
        sum_best += best_way[fl.id];
      }
    }
    if (cnt_good == n) {
      suf_sums[i] = sum_best;
    }
  }

  int ans = INF;
  for (int start = 0; start < C; ++start) {
    int finish = start + k + 1;
    if (finish >= C || suf_sums[finish] == INF || pref_sums[start] == INF) {
      continue;
    }
    relax_min(ans, pref_sums[start] + suf_sums[finish]);
  }

  if (ans == INF) {
    ans = -1;
  }

  cout << ans << endl;

}