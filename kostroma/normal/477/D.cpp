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

//#define int li
const int mod = 1000000007;

const int L = 20;
vector<vector<int>> sparse;
string s;
vector<int> rev;

int get_res(int l, int r) {
  int lg = 31 - __builtin_clz(r - l);
  //cout << l << " " << r << " " << lg << endl;
  return min(sparse[lg][l], sparse[lg][r - (1 << lg)]);
}

int get_lcp(int q, int w) {
  int pos_q = rev[q], pos_w = rev[w];
  if (pos_q < pos_w) {
    return get_res(pos_q, pos_w);
  } else {
    return get_res(pos_w, pos_q);
  }
}

bool cmp(int q, int w) {
  int lcp = get_lcp(q, w);
  if (q + lcp == s.length()) {
    return true;
  }
  if (w + lcp == s.length()) {
    return false;
  }
  return s[q + lcp] < s[w + lcp];
}

int n;

void build() {
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    p[i] = i;
  }
  sort(all(p), [&](int q, int w) {
    for (int len = 0; len + q < s.length() && len + w < s.length(); ++len) {
      if (s[q + len] != s[w + len]) {
        return s[q + len] < s[w + len];
      }
    }
    return q > w;
  });
  sparse.assign(L, vector<int>(n, 0));
  for (int i = 0; i + 1 < n; ++i) {
    int lcp = 0;
    while (lcp + p[i] < s.length() && lcp + p[i + 1] < s.length() && s[p[i] + lcp] == s[p[i + 1] + lcp]) {
      ++lcp;
    }
    sparse[0][i] = lcp;
  }
  for (int i = 1; i < L; ++i) {
    for (int j = 0; j < n; ++j) {
      sparse[i][j] = sparse[i - 1][j];
      int nex = j + (1 << (i - 1));
      if (nex < n) {
        relax_min(sparse[i][j], sparse[i - 1][nex]);
      }
    }
  }
  rev.resize(n);
  for (int i = 0; i < n; ++i) {
    rev[p[i]] = i;
  }
}

int add(int& cur, int val) {
  cur += val;
  if (cur >= mod) {
    cur -= mod;
  }
  if (cur < 0) {
    cur += mod;
  }
}

int dp_add[5010][5010];
int dp_min[5010][5010];

void solve_min() {
  const int INF = 1000000000;
  vector<int> best_res;
  for (int i = 0; i <= s.length(); ++i) {
    for (int j = 0; j <= s.length(); ++j) {
      dp_min[i][j] = INF;
    }
  }
  dp_add[1][0] = 1;
  dp_min[1][0] = 1;
  int res_sum = 0;
  for (int prev = 0; prev < s.length(); ++prev) {
    int pref = INF;
    int pref_add = 0;
    for (int last = prev + 1; last <= s.length(); ++last) {
      relax_min(pref, dp_min[last][prev]);
      add(pref_add, dp_add[last][prev]);
      if (pref > INF / 2) {
        continue;
      }
      //cout << last << " " << prev << " " << pref << endl;
      if (last == s.length()) {
        add(res_sum, pref_add);
        vector<int> cur_num;
        for (int j = (int)s.length() - 1; j >= prev; --j) {
          cur_num.push_back(s[j] - '0');
        }
        cur_num[0] += pref;
        for (int i = 0; i < cur_num.size(); ++i) {
          int nex = cur_num[i] / 2;
          cur_num[i] %= 2;
          if (nex) {
            if (i + 1 == cur_num.size()) {
              cur_num.push_back(nex);
            } else {
              cur_num[i + 1] += nex;
            }
          }
        }
        reverse(all(cur_num));

        if (best_res.empty() || best_res.size() > cur_num.size() || (best_res.size() == cur_num.size() && cur_num < best_res)) {
          best_res = cur_num;
        }
        continue;
      }
      if (s[last] == '0') {
        continue;
      }
      int nex = last + last - prev;
      if (nex > s.length()) {
        continue;
      }
      int lcp = get_lcp(prev, last);
      if (lcp < last - prev && cmp(last, prev)) {
        ++nex;
      }
      if (nex <= s.length()) {
        relax_min(dp_min[nex][last], pref + 1);
        add(dp_add[nex][last], pref_add);
      }
    }
  }

  cout << res_sum << endl;

  int min_good = 0;
  for (int x : best_res) {
    min_good = (min_good * 2 + x) % mod;
  }
  cout << min_good << endl;

}

void solve(bool read) {
  cin >> s;
  /*s = string(5000, '1');
  for (int i = 1; i < s.length(); ++i) {
    if (rand() % 3 == 0) {
      s[i] = '0';
    }
  }*/
  if (s == "0") {
    cout << "1\n1\n";
    return;
  }
  n = (int)s.length();
  build();

  solve_min();
}