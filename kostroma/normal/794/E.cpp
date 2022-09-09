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

void precalc() {

}

//const int mod = 1000000007;

//#define int li

bool has_elem(vector<int>& cur, int val) {
  auto it = lower_bound(all(cur), val);
  return it != cur.end() && *it == val;
}

void relax(int& cur, int val) {
  cur = max(cur, val);
}

void solve(bool read) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> even(n + 1, 0), odd(n + 1, 0);
  for (int i = 0; i + 1 < n; ++i) {
    int mx = max(a[i], a[i + 1]);
    int max_elems = min((i + 1), (n - i - 1)) * 2;
    relax(even[max_elems], mx);
  }
  for (int i = 0; i + 2 < n; ++i) {
    int mx = max(min(a[i], a[i + 1]), min(a[i + 1], a[i + 2]));
    int max_elems = min((i + 1), (n - i - 2)) * 2 + 1;
    relax(odd[max_elems], mx);
  }
  for (int i = n; i > 1; --i) {
    relax(even[i - 2], even[i]);
    relax(odd[i - 2], odd[i]);
  }
  vector<int> res(n + 1);
  for (int i = 0; i < n; ++i) {
    res[1] = max(res[1], a[i]);
  }
  for (int i = 2; i <= n; ++i) {
    if (i % 2 == 0) {
      res[i] = even[i];
    } else {
      res[i] = odd[i];
    }
  }

  for (int k = 0; k < n; ++k) {
    cout << res[n - k] << " ";
  }
  cout << endl;

}