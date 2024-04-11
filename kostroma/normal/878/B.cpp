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
  cout.precision(20);
  cout << fixed;
  //cin >> t;
  while (t--) {
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

template <typename T>
void make_unique(vector<T>& vec) {
  sort(all(vec));
  vec.erase(unique(all(vec)), vec.end());
}

template<typename T>
void relax_min(T& cur, T val) {
  cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
  cur = max(cur, val);
}

void precalc() {

}

#define int li
//const int mod = 1000000007;

int k;

struct Piece {
  vector<int> pref, suf;
  int len;
};

vector<pair<int, int>> get_parts(const vector<int>& a) {
  vector<pair<int, int>> res;
  for (int i = 0; i < a.size(); ) {
    int j = i;
    while (j < a.size() && a[i] == a[j]) {
      ++j;
    }
    res.push_back({a[i], j - i});
    i = j;
  }
  return res;
};

int MAGIC;

Piece merge(const Piece& q, const Piece& w) {
  if (q.len == 0) {
    return w;
  }
  if (w.len == 0) {
    return q;
  }
  auto vec = q.suf;
  reverse(all(vec));
  auto q_parts = get_parts(vec);
  auto w_parts = get_parts(w.pref);
  int decrease_q = 0, decrease_w = 0;
  for (int i = 0; i < q_parts.size() && i < w_parts.size(); ++i) {
    if (q_parts[i].first == w_parts[i].first && q_parts[i].second + w_parts[i].second >= k) {
      if (q_parts[i].second + w_parts[i].second == k) {
        decrease_q += q_parts[i].second;
        decrease_w += w_parts[i].second;
        continue;
      } else {
        int take_q = min(q_parts[i].second, k);
        decrease_q += take_q;
        decrease_w += k - take_q;
        break;
      }
    } else {
      break;
    }
  }
  Piece res = {q.pref, w.suf, q.len + w.len - decrease_q - decrease_w};
  int new_q_len = q.len - decrease_q;
  if (res.pref.size() > new_q_len) {
    res.pref.resize(new_q_len);
  }
  int new_w_len = w.len - decrease_w;
  if (res.suf.size() > new_w_len) {
    vec.clear();
    for (int i = (int)res.suf.size() - new_w_len; i < res.suf.size(); ++i) {
      vec.push_back(res.suf[i]);
    }
    vec.swap(res.suf);
  }
  if (res.pref.size() == new_q_len && res.suf.size() == new_w_len) {
    for (int x : res.suf) {
      res.pref.push_back(x);
    }
    res.suf = res.pref;
  }

  if (res.pref.size() > MAGIC) {
    res.pref.resize(MAGIC);
  }
  if (res.suf.size() > MAGIC) {
reverse(all(res.suf));
    res.suf.resize(MAGIC);
reverse(all(res.suf));
  }
  return res;
}

Piece get_power(Piece cur, int step) {
  if (step == 1) {
    return cur;
  }
  if (step % 2) {
    Piece new_piece = get_power(cur, step - 1);
    return merge(new_piece, cur);
  }
  auto new_piece = get_power(cur, step / 2);
  return merge(new_piece, new_piece);
}

struct Segment {
  int l;
  int len;
  int val;
  bool operator < (const Segment& ot) const {
    return l < ot.l;
  }
};

void solve(bool read) {
  //read = false;
  int n, m;
  if (read) {
    cin >> n >> k >> m;
  } else {
    n = 100000;
    k = 4;
    m = 1000000000;
  }
  vector<int> a(n);
  set<int> have;
  for (int i = 0; i < n; ++i) {
    if (read) {
      cin >> a[i];
    } else {
      a[i] = rand() % 2;
    }
    have.insert(a[i]);
  }
  if (have.size() == 1) {
    int res = n * m % k;
    cout << res << endl;
    return;
  }
  vector<pair<int, int>> st;
  for (int i = 0; i < n; ++i) {
    if (st.empty() || st.back().first != a[i]) {
      st.push_back({a[i], 1});
    } else {
      ++st.back().second;
    }
    if (st.back().second == k) {
      st.pop_back();
    }
  }
  vector<int> b;
  while (!st.empty()) {
    pair<int, int> cur = st.back();
    st.pop_back();
    for (int i = 0; i < cur.second; ++i) {
      b.push_back(cur.first);
    }
  }
  reverse(all(b));
  a = b;
  n = (int)a.size();
  MAGIC = 3 * n;

  Piece start = {a, a, n};

  Piece res = get_power(start, m);

  cout << res.len << endl;

}