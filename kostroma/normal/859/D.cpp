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

template <typename T>
void make_unique(vector<T>& a) {
  sort(all(a));
  a.erase(unique(all(a)), a.end());
}

void precalc() {}

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

void solve(bool read) {
  int n;
  cin >> n;
  int N = (1 << n);
  vector<vector<double>> a(N, vector<double>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      double cur;
      cin >> cur;
      cur /= 100.;
      a[i][j] = cur;
    }
  }
  vector<vector<double>> dp(N, vector<double>(N, 0.0)), prob(N, vector<double>(N, 0));
  for (int i = 0; i < N; ++i) {
    dp[i][i] = 0;
    prob[i][i] = 1;
  }
  for (int len = 2; len <= N; len *= 2) {
    vector<vector<double>> new_dp(N, vector<double>(N, -1e9));
    vector<vector<double>> new_prob(N, vector<double>(N, 0));
    for (int i = 0; i < N; i += len) {
      for (int first = i; first < i + len / 2; ++first) {
        double prob_win = 0;
        double second_max = 0;
        for (int second = i + len / 2; second < i + len; ++second) {
          prob_win += a[first][second] * prob[i + len / 2][second];
          relax_max(second_max, dp[i + len / 2][second]);
        }
        relax_max(new_dp[i][first], dp[i][first] + second_max + (len / 2) * prob_win * prob[i][first]);
      }
      for (int second = i + len / 2; second < i + len; ++second) {
        double prob_win = 0;
        double first_max = 0;
        for (int first = i; first < i + len / 2; ++first) {
          prob_win += a[second][first] * prob[i][first];
          relax_max(first_max, dp[i][first]);
        }
        relax_max(new_dp[i][second], dp[i + len / 2][second] + first_max + (len / 2) * prob_win * prob[i + len / 2][second]);
      }

      for (int first = i; first < i + len / 2; ++first) {
        for (int second = i + len / 2; second < i + len; ++second) {
          new_prob[i][first] += prob[i][first] * prob[i + len / 2][second] * a[first][second];
          new_prob[i][second] += prob[i][first] * prob[i + len / 2][second] * a[second][first];
        }
      }

      /*for (int cur = i; cur < i + len; ++cur) {
        cout << len << " " << i << " " << cur << " " << new_dp[i][cur] << " " << new_prob[i][cur] << endl;
      }*/

    }
    dp.swap(new_dp);
    new_prob.swap(prob);
  }

  double ans = 0;
  for (auto x : dp[0]) {
    relax_max(ans, x);
  }

  cout << ans << endl;

}