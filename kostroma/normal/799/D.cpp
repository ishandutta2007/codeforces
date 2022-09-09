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

const int L = 36;

int dp[100500][L];

void relax(int& cur, int val) {
  cur = max(cur, val);
}

void solve(bool read) {
  vector<int> from(2), to(2);
  for (int i = 0; i < 2; ++i) {
    cin >> to[i];
  }
  for (int i = 0; i < 2; ++i) {
    cin >> from[i];
  }

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());
  if (a.size() > L) {
    a.resize(L);
  }
  const int INF = (int)1e9;
  int ans = INF;
  for (int it = 0; it < 2; ++it) {
    vector<int> need(2);
    for (int i = 0; i < 2; ++i) {
      need[i] = (to[i] - 1) / from[i] + 1;
    }
    for (int j = 0; j <= need[0]; ++j) {
      for (int used = 0; used < L; ++used) {
        dp[j][used] = 0;
      }
    }
    dp[1][0] = 1;
    for (int i = 0; i < a.size(); ++i) {
      for (int j = need[0]; j > 0; --j) {
        int nex = (int)min(1LL * j * a[i], need[0] * 1LL);
        for (int used = 0; used + 1 < L; ++used) {
          relax(dp[nex][used + 1], dp[j][used]);
        }
        for (int used = L - 2; used >= 0; --used) {
          nex = (int) min(1LL * dp[j][used] * a[i], need[1] * 1LL);
          relax(dp[j][used + 1], nex);
        }
      }
    }
    for (int used = 0; used < L; ++used) {
      if (dp[need[0]][used] >= need[1]) {
        ans = min(ans, used);
        break;
      }
    }
    swap(to[0], to[1]);
  }

  if (ans > INF / 2) {
    cout << "-1\n";
  } else {
    cout << ans << "\n";
  }


}