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

struct Dsu {
  vector<int> dsu;
  Dsu(int n) {
    dsu.resize(n);
    iota(dsu.begin(), dsu.end(), 0);
  }
  int find_set(int v) {
    if (dsu[v] == v) return v;
    return dsu[v] = find_set(dsu[v]);
  }
  bool merge(int q, int w) {
    q = find_set(q);
    w = find_set(w);
    dsu[w] = q;
    return q != w;
  }
};

void solve(bool read) {
  int n, m;
  //read = false;
  if (read) {
    cin >> n >> m;
  } else {
    n = rand() % 8 + 1;
    m = rand() % (1 << n) + 1;
    n = 22;
    m = (1 << n);
  }
  vector<int> a(m);
  set<int> have;
  for (int i = 0; i < m; ++i) {
    if (read) {
      cin >> a[i];
    } else {
      a[i] = i;
      continue;
      do {
        a[i] = rand() % (1 << n);
      } while (have.count(a[i]));
      have.insert(a[i]);
    }
  }
  vector<int> score(1 << n);
  vector<char> has(1 << n, false);
  vector<char> dp(1 << n, false);
  for (int x : a) {
    dp[x] = true;
    has[x] = true;
  }
  for (int mask = 0; mask < (1 << n); ++mask) {
    if (!dp[mask]) {
      continue;
    }
    for (int i = 0; i < n; ++i) {
      dp[mask | (1 << i)] = true;
    }
  }
  Dsu dsu(1 << n);
  int res = (1 << n);
  vector<char> can(1 << n, false);
  for (int mask = 0; mask < (1 << n); ++mask) {
    if (!dp[mask]) {
      continue;
    }
    //cout << "used " << mask << endl;
    if (has[(1 << n) - mask - 1]) {
      can[mask] = true;
      //cout << "mask: " << mask << endl;
      if (dsu.merge((1 << n) - mask - 1, mask)) {
        --res;
      }
    }
  }

  for (int mask = (1 << n) - 1; mask >= 0; --mask) {
    if (!can[mask]) {
      if (!has[mask]) {
        --res;
      }
      continue;
    }
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) {
        int new_mask = mask ^ (1 << i);
        if (dp[new_mask]) {
          can[new_mask] = true;
        }
      }
    }
  }
  for (int mask = 0; mask < (1 << n); ++mask) {
    for (int i = 0; i < n; ++i) {
      if (!(mask & (1 << i)) && can[mask] && can[mask | (1 << i)]) {
        //cout << "merging " << mask << " " << (mask | (1 << i)) << "\n";
        if (dsu.merge(mask, mask | (1 << i))) {
          --res;
        }
      }
    }
  }

  cout << res << "\n";

#if 0

  Dsu stupid(m);
  int stup = m;
  for (int i = 0; i < m; ++i) {
    for (int j = i + 1; j < m; ++j) {
      if (a[i] & a[j]) {

      } else {
        //cout << "merge " << a[i] << " " << a[j] << endl;
        if (stupid.merge(i, j)) {
          --stup;
        }
      }
    }
  }
  if (stup != res) {
    cout << "FOUND res: " << res << " stup: " << stup << endl;
    cout << n << " " << m << "\n";
    for (int x : a) {
      cout << x << " ";
    }
    cout << endl;
    exit(0);
  }
  assert(stup == res);
#endif

}