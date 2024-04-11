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

#define int li
//const int mod = 1000000007;

vector<int> sum(vector<int> a, vector<int> b, int sign) {
  vector<int> res(a.size());
  for (int i = 0; i < a.size(); ++i) {
    res[i] = a[i] + sign * b[i];
  }
  return res;
}

map<int, int> dp;

int rec(int n, int dist) {
  if (n < 2 * dist - 1) {
    return 0;
  }
  if (dp.count(n)) {
    return dp[n];
  }
  int lef = (n - 1) / 2, rig = n / 2;
  return dp[n] = 1 + rec(lef, dist) + rec(rig, dist);
}

int rec_exactly(int n, int dist) {
  if (n < 2 * dist - 1) {
    return 0;
  }
  if (dp.count(n)) {
    return dp[n];
  }
  int lef = (n - 1) / 2, rig = n / 2;
  int have_current = (lef == dist - 1);
  return dp[n] = have_current + rec_exactly(lef, dist) + rec_exactly(rig, dist);
}

int ANS = -1;

void find_ans(int n, int dist, int num, int add) {
  int lef = (n - 1) / 2, rig = n / 2;
  int have_current = (lef == dist - 1);
  if (dp[lef] >= num) {
    return find_ans(lef, dist, num, add);
  }
  num -= dp[lef];
  if (have_current) {
    --num;
  }
  if (num == 0) {
    ANS = add + lef;
    return;
  }
  return find_ans(rig, dist, num, add + lef + 1);
}

int n;
int get_segs(int dist) {
  dp.clear();
  return rec(n, dist);
}

void solve(bool read) {
  int k;
  if (read) {
    cin >> n >> k;
  } else {
    n = rand() % 30 + 1;
    k = rand() % n + 1;
    cout << n << " " << k << endl;
  }

  if (k == 1) {
    cout << 1 << endl;
    return;
  }
  if (k == 2) {
    cout << n << endl;
    return;
  }
  n -= 2;
  k -= 2;

  int N = n, K = k;

  //cout << "run " << n << " " << k << endl;

  int L = 0, R = n + 1;
  while (L + 1 < R) {
    int M = (L + R) / 2;
    int cur_val = get_segs(M);
    //cout << M << " " << cur_val << endl;
    if (cur_val < k) {
      R = M;
    } else {
      L = M;
    }
  }

  int dist = L;
  k -= get_segs(R);

  dp.clear();
  rec_exactly(n, dist);

  ANS = -1;
  find_ans(n, dist, k, 0);
  assert(ANS != -1);

  cout << ANS + 2 << endl;

  if (!read) {
    vector<int> a(n, 0);
    for (int i = 0; i < K; ++i) {
      int min_dist = 0;
      int mn = -1;
      for (int j = 0; j < n; ++j) {
        int cur_dist = min(j + 1, n - j);
        for (int r = 0; r < n; ++r) {
          if (a[r]) {
            relax_min(cur_dist, abs(r - j));
          }
        }
        if (min_dist < cur_dist) {
          min_dist = cur_dist;
          mn = j;
        }
      }
      a[mn] = 1;
      if (i + 1 == K) {
        if (mn != ANS) {
          cout << "error: " << n << " " << K << " " << ANS << " " << mn << endl;
          exit(0);
        }
      }
    }
  }


}