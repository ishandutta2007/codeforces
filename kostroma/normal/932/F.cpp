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
//const li mod = 1000000007;

const int INF = (int)1e6;

struct Line {
  int k;
  li b;
  bool operator < (const Line& ot) const {
    if (k != ot.k) {
      return k > ot.k;
    }
    return b < ot.b;
  }
  li eval(li x) {
    return k * 1LL * x + b;
  }
};

double get_intersect(Line& q, Line& w) {
  return (q.b - w.b) / 1.0 / (w.k - q.k);
}

vector<vector<int>> g;
vector<int> a, b;
vector<li> dp;

struct Hull {
  vector<Line> lines;
  vector<double> borders;
  int Size = 0;
  void append(Line cur) {
    lines.push_back(cur);
  }
  void set_size(int val) {
    Size = val;
  }
  void build() {
    sort(all(lines));
    borders.clear();
    vector<Line> new_lines;
    for (auto& line : lines) {
      if (!new_lines.empty() && new_lines.back().k == line.k) {
        continue;
      }
      while (new_lines.size() > 1 && get_intersect(new_lines[new_lines.size() - 2], new_lines.back()) > get_intersect(new_lines.back(), line)) {
        new_lines.pop_back();
        borders.pop_back();
      }
      if (new_lines.empty()) {
        borders.push_back(-INF);
      } else {
        borders.push_back(get_intersect(new_lines.back(), line));
      }
      new_lines.push_back(line);
    }
    new_lines.swap(lines);
  }
  int size() {
    return Size;
  }
  li get_min(li x) {
    int id = (int)(lower_bound(all(borders), (double)x) - borders.begin());
    li res = (li)1e18;
    for (int i = max(id - 1, 0); i < min(id + 2, (int)lines.size()); ++i) {
      res = min(res, lines[i].eval(x));
    }
    return res;
  }
};

struct Lupa {
  vector<Hull> hulls;
  int Size = 0;
  void append_line(Line cur) {
    hulls.push_back(Hull());
    hulls.back().append(cur);
    hulls.back().set_size(1);
    while (hulls.size() >= 2 && hulls.back().size() == hulls[hulls.size() - 2].size()) {
      for (auto& item : hulls.back().lines) {
        hulls[hulls.size() - 2].append(item);
      }
      hulls.pop_back();
      hulls.back().set_size(hulls.back().size() * 2);
    }
    hulls.back().build();
    ++Size;
  }
  li get_min(li x) {
    li res = (li)1e18;
    for (auto& vec : hulls) {
      res = min(res, vec.get_min(x));
    }
    return res;
  }
  int size() {
    return Size;
  }
  void merge_with(Lupa& ot) {
    for (auto& vec : ot.hulls) {
      for (auto& item : vec.lines) {
        append_line(item);
      }
      vec.lines.clear();
    }
  }
  void make_swap(Lupa& ot) {
    swap(ot.Size, Size);
    ot.hulls.swap(hulls);
  }
};

Lupa dfs(int v, int p) {
  vector<int> children;
  for (int to : g[v]) {
    if (to == p) continue;
    children.push_back(to);
  }
  if (children.empty()) {
    Lupa res;
    res.append_line({b[v], 0LL});
    dp[v] = 0;
    return res;
  }
  Lupa res = {};
  res.Size = 0;
  for (int to : children) {
    auto new_treap = dfs(to, v);
    if (new_treap.size() > res.size()) {
      res.make_swap(new_treap);
    }
    res.merge_with(new_treap);
  }
  dp[v] = res.get_min(a[v]);
  res.append_line({b[v], dp[v]});
  return res;
}

void solve(bool read) {
  int n;
  //read = false;
  if (read) {
    cin >> n;
  } else {
    n = 10000;
  }
  a.resize(n);
  b.resize(n);
  for (int i = 0; i < n; ++i) {
    if (read) {
      cin >> a[i];
    } else {
      a[i] = rand() % 200000 - 100000;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (read) {
      cin >> b[i];
    } else {
      b[i] = rand() % 200000 - 100000;
    }
  }
  g.resize(n);
  for (int i = 1; i < n; ++i) {
    int q, w;
    if (read) {
      cin >> q >> w;
      --q;
      --w;
    } else {
      q = (i - 1);
      w = i;
    }
    g[q].push_back(w);
    g[w].push_back(q);
  }
  dp.resize(n);
  dfs(0, 0);
  for (int i = 0; i < n; ++i) {
    cout << dp[i] << " \n"[i + 1 == n];
  }

}