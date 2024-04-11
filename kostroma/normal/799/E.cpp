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


//const int mod = 1000000007;

#define int li

vector<int> make_prefs(const vector<int>& a) {
  vector<int> res(a.size() + 1, 0);
  for (int i = 0; i < a.size(); ++i) {
    res[i + 1] = res[i] + a[i];
  }
  return res;
}

void solve(bool read) {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> cost(n);
  for (int i = 0; i < n; ++i) {
    cin >> cost[i];
  }
  vector<vector<int>> whom(n);
  for (int i = 0; i < 2; ++i) {
    int sz;
    cin >> sz;
    while (sz--) {
      int cur;
      cin >> cur;
      --cur;
      whom[cur].push_back(i);
    }
  }

  vector<vector<int>> only(2);
  vector<int> common;
  vector<int> rest;
  for (int i = 0; i < n; ++i) {
    if (whom[i].empty()) {
      rest.push_back(cost[i]);
    } else if (whom[i].size() == 2) {
      common.push_back(cost[i]);
    } else {
      only[whom[i][0]].push_back(cost[i]);
    }
  }

  sort(common.begin(), common.end());
  vector<int> pref_common = make_prefs(common);
  sort(rest.begin(), rest.end());
  vector<int> pref_rest = make_prefs(rest);
  vector<vector<int>> pref_only(2);
  for (int i = 0; i < 2; ++i) {
    sort(all(only[i]));
    pref_only[i] = make_prefs(only[i]);
  }

  const int INF = (int)1e18;
  int res = INF;
  for (int take = 0; take <= common.size(); ++take) {
    if (take > m) {
      break;
    }
    int need_from = max(0LL, k - take);
    int cur_res = pref_common[take];
    bool f = true;
    for (int i = 0; i < 2; ++i) {
      if (only[i].size() < need_from) {
        f = false;
        break;
      }
      cur_res += pref_only[i][need_from];
    }
    if (!f) {
      continue;
    }
    int need_rest = m - take - 2 * need_from;
    if (need_rest < 0) {
      continue;
    }
    if (n - ((int)common.size() - take) < m) {
      continue;
    }
    int L = -1, R = (int)1e9 + 100;
    while (L + 1 < R) {
      int M = (L + R) / 2;
      int have = 0;
      for (int i = 0; i < 2; ++i) {
        int id = upper_bound(all(only[i]), M) - only[i].begin();
        if (id >= need_from) {
          have += id - need_from;
        }
      }
      int id = upper_bound(all(rest), M) - rest.begin();
      have += id;
      if (have >= need_rest) {
        R = M;
      } else {
        L = M;
      }
    }
    int have = 0;
    for (int i = 0; i < 2; ++i) {
      int id = upper_bound(all(only[i]), R) - only[i].begin();
      if (id >= need_from) {
        have += id - need_from;
        cur_res += pref_only[i][id] - pref_only[i][need_from];
      }
    }
    int id = upper_bound(all(rest), R) - rest.begin();
    cur_res += pref_rest[id];
    have += id;

    int to_sub = have - need_rest;
    cur_res -= to_sub * R;
    res = min(res, cur_res);
  }

  if (res > INF / 2) {
    cout << "-1\n";
    return;
  }
  cout << res << endl;

}