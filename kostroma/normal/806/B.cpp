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
        //cerr << testNum << endl;
        //cout << "Case #" << testNum++ << ": ";
        solve(true);
        ++testNumber;
        //++timer;
    }
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

//#define int li
//const int mod = 1000000007;

const int INF = (int)1e9;

void relax(int& cur, int val) {
  cur = min(cur, val);
}

void solve(bool read) {
  int n;
  cin >> n;
  vector<int> solved(5, 0);
  vector<vector<int>> points(2, vector<int>(5, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 5; ++j) {
      int cur;
      cin >> cur;
      if (cur != -1) {
        ++solved[j];
      }
      if (i < 2) {
        points[i][j] = cur;
      }
    }
  }

  int res = INF;
  for (int cur_n = n; cur_n <= n * 64; ++cur_n) {
    int diff = 0;
    for (int task = 0; task < 5; ++task) {
      int cur_val = 500;
      int cur_diff = 0;
      for (int step = 2; step <= 64; step *= 2) {
        if (solved[task] * step > cur_n || step == 64) {
          if (points[0][task] != -1) {
            cur_diff += cur_val * (250 - points[0][task]) / 250;
          }
          if (points[1][task] != -1) {
            cur_diff -= cur_val * (250 - points[1][task]) / 250;
          }
          break;
        }
        cur_val += 500;
      }
      int best_diff = cur_diff;
      if (points[0][task] != -1) {
        cur_val = 500;
        cur_diff = 0;
        for (int step = 2; step <= 64; step *= 2) {
          if ((solved[task] + cur_n - n) * step > cur_n || step == 64) {
            if (points[0][task] != -1) {
              cur_diff += cur_val * (250 - points[0][task]) / 250;
            }
            if (points[1][task] != -1) {
              cur_diff -= cur_val * (250 - points[1][task]) / 250;
            }
            break;
          }
          cur_val += 500;
        }
        best_diff = max(best_diff, cur_diff);
      }

      diff += best_diff;
    }

    if (diff > 0) {
      res = cur_n - n;
      break;
    }
  }

  if (res > INF / 2) {
    cout << "-1\n";
  } else {
    cout << res << "\n";
  }


}