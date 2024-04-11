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

//#define int li

//const int mod = 1000000007;

void solve(bool read) {
  int m, n;
  cin >> m >> n;
  vector<vector<pair<int, int>>> profiles(n);
  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k;
    vector<int> a(k);
    for (int j = 0; j < k; ++j) {
      cin >> a[j];
      --a[j];
    }
    sort(all(a));
    vector<pair<int, int>> have;
    for (int j = 0; j < a.size(); ) {
      int r = j;
      while (r < a.size() && a[r] == a[j]) {
        ++r;
      }
      have.push_back({r - j, a[j]});
      j = r;
    }
    for (auto item : have) {
      profiles[item.second].push_back({i, item.first});
    }
  }
  sort(all(profiles));
  li res = 1;
  li mod = 1000000007;
  for (int i = 0; i < profiles.size(); ) {
    int j = i;
    while (j < profiles.size() && profiles[i] == profiles[j]) {
      ++j;
    }
    for (int r = 1; r <= j - i; ++r) {
      res = res * r % mod;
    }
    i = j;
  }

  cout << res << endl;

}