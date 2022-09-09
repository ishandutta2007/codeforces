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
  cin >> n;
  vector<int> price(n);
  for (int i = 0; i < n; ++i) {
    cin >> price[i];
  }
  vector<vector<int>> cols(3);
  for (int j = 0; j < 2; ++j) {
    for (int i = 0; i < n; ++i) {
      int cur;
      cin >> cur;
      --cur;
      cols[cur].push_back(i);
    }
  }
  vector<int> uk(3, 0);
  vector<char> used(n, false);
  for (int i = 0; i < 3; ++i) {
    sort(all(cols[i]), [&](int q, int w) {
      return price[q] < price[w];
    });
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int cur;
    cin >> cur;
    --cur;
    while (uk[cur] < cols[cur].size() && used[cols[cur][uk[cur]]]) {
      ++uk[cur];
    }
    if (uk[cur] < cols[cur].size()) {
      cout << price[cols[cur][uk[cur]]] << " ";
      used[cols[cur][uk[cur]]] = true;
    } else {
      cout << "-1 ";
    }
  }
  cout << endl;

}