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

void precalc() {

}

template<typename T>
void relax_min(T& cur, T val) {
  cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
  cur = max(cur, val);
}

//#define int li
//const int mod = 1000000007;

const int L = 30;

void solve(bool read) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adds(L, vector<int>(n + 1));
  vector<vector<pair<int, int>>> not_all(L);
  for (int i = 0; i < m; ++i) {
    int l, r, q;
    cin >> l >> r >> q;
    --l;
    for (int bit = 0; bit < L; ++bit) {
      if (q & (1 << bit)) {
        ++adds[bit][l];
        --adds[bit][r];
      } else {
        not_all[bit].push_back({l, r});
      }
    }
  }

  vector<int> pref(L, 0);
  vector<int> res(n);
  for (int i = 0; i < n; ++i) {
    for (int bit = 0; bit < L; ++bit) {
      pref[bit] += adds[bit][i];
      if (pref[bit] > 0) {
        res[i] |= (1 << bit);
      }
    }
  }

  vector<vector<int>> pref_sum(n + 1, vector<int>(L, 0));
  for (int i = 0; i < n; ++i) {
    pref_sum[i + 1] = pref_sum[i];
    for (int bit = 0; bit < L; ++bit) {
      if (res[i] & (1 << bit)) {
        ++pref_sum[i + 1][bit];
      }
    }
  }

  for (int bit = 0; bit < L; ++bit) {
    for (auto seg : not_all[bit]) {
      int cnt = pref_sum[seg.second][bit] - pref_sum[seg.first][bit];
      if (cnt == seg.second - seg.first) {
        cout << "NO\n";
        return;
      }
    }
  }

  cout << "YES\n";
  for (int x : res) {
    cout << x << " ";
  }
  cout << endl;


}