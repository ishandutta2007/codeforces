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

#define int li
//const int mod = 1000000007;

void solve(bool read) {
  int n, C;
  cin >> n >> C;
  vector<int> one(n), two(n);
  for (int i = 0; i < 2 * n - 1; ++i) {
    int cur;
    cin >> cur;
    if (i % 2 == 0) {
      one[i / 2] = cur;
    } else {
      two[i / 2] = cur;
    }
  }

  vector<int> suf_sum(n + 1), pref_sum(n + 1);
  for (int i = n - 1; i >= 0; --i) {
    suf_sum[i] = one[i] + two[i] + suf_sum[i + 1];
  }
  for (int i = 0; i < n; ++i) {
    pref_sum[i + 1] = pref_sum[i] + one[i];
    if (i) {
      pref_sum[i + 1] += two[i - 1];
    }
  }

  int ans = 0;
  int add_to_all = 0;
  set<pair<int, pair<int, int>>> qs;
  for (int i = 0; i < n; ++i) {
    qs.insert({suf_sum[i] + add_to_all, {C + add_to_all, i}});
    //cout << "insert " << i << " " << suf_sum[i] << " " << C << endl;
    while (!qs.empty()) {
      auto item = *(--qs.end());
      int cur_max = item.first - add_to_all;
      int need_val = cur_max - suf_sum[i + 1] - two[i];
      //cout << i << " need: " << need_val << " " << cur_max << " " << item.second.second << " " << item.second.first << " " << add_to_all << endl;
      if (item.second.first - add_to_all <= 0) {
        qs.erase(--qs.end());
        continue;
      }
      relax_min(need_val, item.second.first - add_to_all);
      relax_max(need_val, 0LL);
      if (need_val <= 0) {
        break;
      }
      qs.erase(--qs.end());
      ans += need_val;
      add_to_all += need_val;
      if (item.second.first > add_to_all) {
        qs.insert({item.first, item.second});
        //cout << "return " << i << " " << item.second.first << " " << item.second.second << endl;
      }
      //cout << i << " got: " << need_val << "\n";
    }
  }

  cout << ans << endl;

}