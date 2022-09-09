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

const int mod = 1000000007;

const int MAX_VAL = 20;
const int max_mask = (1 << MAX_VAL);
int dp[78][max_mask];

void add(int& cur, int add) {
  cur += add;
  if (cur >= mod) {
    cur -= mod;
  }
}

void solve(bool read) {
  int n;
  string s;
  cin >> n >> s;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = s[i] - '0';
  }
  for (int i = 0; i <= n; ++i) {
    dp[i][0] = 1;
  }
  for (int i = 0; i < n; ++i) {
    for (int mask = 0; mask < max_mask; ++mask) {
      if (dp[i][mask] == 0) {
        continue;
      }
      int num = 0;
      for (int j = i; j < n; ++j) {
        num = num * 2 + a[j];
        //cerr << j - i << ' ' << num << ' ' << a[j] << endl;
        if (num == 0) {
          continue;
        }
        if (num > MAX_VAL) {
            break;
        }
        int new_mask = (mask | (1 << (num - 1)));
        add(dp[j + 1][new_mask], dp[i][mask]);
      }
    }
  }

  int res = 0;
  for (int i = 0; i <= n; ++i) {
    for (int k = 1; k <= n + 1 && k <= MAX_VAL; ++k) {
      int mask = (1 << k) - 1;
      add(res, dp[i][mask]);
    }
  }
  cout << res << "\n";

}