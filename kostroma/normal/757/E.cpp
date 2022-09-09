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
  //cout.sync_with_stdio(0);
  //cin.tie(0);
  precalc();
  cout.precision(10);
  cout << fixed;
  cin >> t;
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

#define int li

const int L = 22;
const int C = 1000500;
int dp[C][L];

const int mod = 1000000007;

int least_prime[C];

void precalc() {
  for (int i = 2; i < C; ++i) {
    if (!least_prime[i]) {
      least_prime[i] = i;
      for (int j = i * i; j < C; j += i) {
        least_prime[j] = i;
      }
    }
  }

  dp[0][0] = 1;
  for (int i = 1; i < L; ++i) {
    dp[0][i] = 2 % mod;
  }
  for (int deg = 1; deg < C; ++deg) {
    for (int i = 0; i < L; ++i) {
      for (int j = 0; j <= i; ++j) {
        dp[deg][i] += dp[deg - 1][j] + dp[deg - 1][i - j];
        if (dp[deg][i] > 2 * mod) {
          dp[deg][i] -= 2 * mod;
        }
      }
      dp[deg][i] /= 2;
      dp[deg][i] %= mod;
    }
  }
}

//int revfact[100];

/*int getC(int n, int k) {
  int res = revfact[k];
  for (int i = 0; i < k; ++i) {
    res = res * (n - i) % mod;
  }
  return res;
}

int step;

int get_res(int pos, int cur_val) {
  if (pos == fact.size()) {
    return cur_val;
  }
  int res = get_res(pos + 1, cur_val) * getC(fact[pos] + step - 1, fact[pos]);
  for (int i = 1; i <= fact[pos]; ++i) {
    res += get_res(pos + 1, cur_val * 2 % mod * getC(fact[pos] - i + step - 1, fact[pos] - i));
    res %= mod;
  }
  return res;
}*/

void solve(bool read) {
  /*revfact[0] = 1;
  for (int i = 1; i < 100; ++i) {
    revfact[i] = revfact[i - 1] * binpow(i, mod - 2, mod) % mod;
  }*/

  int r, n;
  //cin >> r >> n;
  scanf("%lld%lld", &r, &n);
  if (n == 1) {
    cout << 1 << "\n";
    return;
  }

  int res = 1;
  while (n > 1) {
    int cur = least_prime[n];
    int cnt = 0;
    while (n % cur == 0) {
      n /= cur;
      ++cnt;
    }
    res = res * dp[r][cnt] % mod;
  }

  printf("%d\n", (int)res);

}