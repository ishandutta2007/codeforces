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
  cout.precision(10);
  cout << fixed;
  //cin >> t;
  while (t--) {
    solve(true);
  }
  cout.flush();

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

//#define int li

//const int mod = 1000000007;

void solve(bool read) {
  int n;
  vector<int> have(2);
  cin >> n >> have[0] >> have[1];
  vector<vector<pair<int, int>>> a(2);
  for (int i = 0; i < n; ++i) {
    int b, price;
    char type;
    cin >> b >> price >> type;
    a[type == 'D'].push_back({price, b});
  }

  int res = 0;
  int best_overall = 0;
  bool flag = true;
  for (int i = 0; i < 2; ++i) {
    sort(all(a[i]));
    int best_can = 0;
    vector<int> first_max(a[i].size());
    vector<int> second_max(a[i].size());
    for (int j = 0; j < a[i].size(); ++j) {
      first_max[j] = a[i][j].second;
      second_max[j] = 0;
    }
    for (int j = 1; j < a[i].size(); ++j) {
      if (first_max[j] > first_max[j - 1]) {
        second_max[j] = first_max[j - 1];
      } else {
        second_max[j] = max(second_max[j - 1], first_max[j]);
        first_max[j] = first_max[j - 1];
      }
    }
    int last_can = (int)a[i].size() - 1;
    for (int j = 0; j < a[i].size(); ++j) {
      int rem = have[i] - a[i][j].first;
      if (rem < 0) {
        continue;
      } else {
        best_can = max(best_can, a[i][j].second);
      }
      while (last_can >= 0 && a[i][last_can].first + a[i][j].first > have[i]) {
        --last_can;
      }
      if (last_can >= 0) {
        int id = last_can;
        if (last_can == j) {
          id = last_can - 1;
        }
        if (id >= 0 && id < j) {
          if (first_max[j] != first_max[id]) {
            res = max(res, first_max[j] + first_max[id]);
          } else {
            if (second_max[j] != 0) {
              res = max(res, second_max[j] + first_max[id]);
            }
          }
        }
      }
    }
    best_overall += best_can;
    if (best_can == 0) {
      flag = false;
    }
  }
  if (flag) {
    res = max(res, best_overall);
  }

  cout << res << endl;



}