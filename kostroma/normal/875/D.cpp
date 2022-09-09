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

//#define int li
//const int mod = 1000000007;

vector<int> dsu;

void init(int n) {
  dsu.resize(n);
  for (int i = 0; i < n; ++i) {
    dsu[i] = i;
  }
}

int find_set(int v) {
  if (dsu[v] == v) {
    return v;
  }
  return dsu[v] = find_set(dsu[v]);
}

void merge(int q, int w) {
  q = find_set(q);
  w = find_set(w);
  dsu[w] = q;
}

const int L = 30;

void solve(bool read) {
  //read = false;
  int n;
  if (read) {
    cin >> n;
  } else {
    n = 200000;
  }
  vector<int> a(n);
  vector<vector<int>> poses(L);
  vector<int> xs;
  for (int i = 0; i < n; ++i) {
    if (read) {
      cin >> a[i];
    } else {
      a[i] = rand();
    }
    xs.push_back(a[i]);
    for (int j = 0; j < L; ++j) {
      if (a[i] & (1 << j)) {
        poses[j].push_back(i);
      }
    }
  }

  make_unique(xs);
  vector<vector<int>> occur(xs.size());
  for (int i = 0; i < n; ++i) {
    int id = lower_bound(all(xs), a[i]) - xs.begin();
    occur[id].push_back(i);
  }

  vector<int> next_bit(L, 0);
  vector<pair<int, int>> items;
  li ans = 0;
  for (int l = 0; l < n; ++l) {
    items.clear();
    for (int j = 0; j < L; ++j) {
      if (next_bit[j] < poses[j].size() && poses[j][next_bit[j]] < l) {
        ++next_bit[j];
      }
      if (next_bit[j] < poses[j].size()) {
        items.emplace_back(poses[j][next_bit[j]], j);
      }
    }
    sort(all(items));
    items.push_back({n, -1});
    int cur_val = 0;
    int last_pos = l;
    for (auto item : items) {
      int next_pos = item.first;
      int border = next_pos;
      auto it = lower_bound(all(xs), cur_val);
      if (it != xs.end() && *it == cur_val) {
        int id = it - xs.begin();
        auto new_it = lower_bound(all(occur[id]), l);
        if (new_it != occur[id].end()) {
          border = min(border, *new_it);
        }
      }
      //cout << l << " " << last_pos << " " << border << endl;
      ans += border - last_pos;
      if (item.second >= 0) {
        cur_val |= (1 << item.second);
      }
      last_pos = next_pos;
    }
  }

  cout << ans << endl;

}