#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
/*#if !defined(YCM) && 0
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx,tune=native")
#include <stdio.h>
#endif*/
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

template<typename T>
void relax_min(T& cur, T val) {
    cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
    cur = max(cur, val);
}

void precalc() {}

//#define int li
//const int mod = 1000000007;

const li INF = (li)1e18;

vector<int> a;
//vector<vector<int>> dp;

li dp[22][100500];

int num_in_segment[100500];
li sum_in_segment = 0;

void add_value(int cur) {
  sum_in_segment += num_in_segment[cur];
  ++num_in_segment[cur];
}

void sub_value(int cur) {
  --num_in_segment[cur];
  sum_in_segment -= num_in_segment[cur];
}

int calc_dp(int k, int pos, int opt_l, int opt_r) {
  int ans = -1;
  for (int j = opt_r - 1; j >= opt_l; --j) {
    add_value(a[j]);
    li cur_cost = sum_in_segment + dp[k - 1][j];
    if (j < pos && dp[k][pos] > cur_cost) {
      dp[k][pos] = cur_cost;
      ans = j;
    }
  }
  for (int j = opt_l; j < opt_r; ++j) {
    sub_value(a[j]);
  }
  //cout << k << " " << pos << " " << dp[k][pos] << endl;
  return ans;
}

void calc(int l, int r, int opt_l, int opt_r, int k) {
  int m = (l + r) / 2;
  int new_opt_r = min(m, opt_r);
  if (opt_r > m) {
    for (int i = r - 1; i >= opt_r; --i) {
      sub_value(a[i]);
    }
  } else {
    for (int i = r - 1; i >= m; --i) {
      sub_value(a[i]);
    }
  }
  int left_border = new_opt_r;
  int opt_m = max(calc_dp(k, m, opt_l, new_opt_r), 0);
  while (left_border > opt_m + 1) {
    --left_border;
    add_value(a[left_border]);
  }
  if (l < m) {
    calc(l, m, opt_l, opt_m + 1, k);
  }

  for (int i = m; i < r; ++i) {
    add_value(a[i]);
  }
  while (left_border < opt_r) {
    sub_value(a[left_border]);
    ++left_border;
  }
  if (m + 1 < r) {
    calc(m + 1, r, opt_m, opt_r, k);
  }
}

void solve(bool read) {
  //read = false;
  int n, k;
  if (read) {
    cin >> n >> k;
  } else {
    n = 100000;
    k = 20;
  }
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    if (read) {
      cin >> a[i];
      --a[i];
    } else {
      a[i] = rand() % n;
    }
  }
  //dp.assign(k, vector<int>(n + 1, INF));
  for (int num = 0; num < k; ++num) {
    for (int pos = 0; pos < n; ++pos) {
      dp[num][pos] = INF;
    }
  }
  dp[0][0] = 0;
  for (int num = 1; num < k; ++num) {
    calc(0, n, 0, n, num);
  }

  sum_in_segment = 0;
  memset(num_in_segment, 0, sizeof(num_in_segment));
  li ans = INF;
  for (int i = n - 1; i >= 0; --i) {
    add_value(a[i]);
    ans = min(ans, dp[k - 1][i] + sum_in_segment);
  }

  cout << ans << endl;

}