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

void precalc() {

}

//#define int li
//const int mod = 1000000007;

using State = std::array<int, 10>;

State start_state() {
  State res;
  res.fill(0);
  return res;
}

template <typename T>
void make_unique(vector<T>& vec) {
  sort(all(vec));
  vec.erase(unique(all(vec)), vec.end());
}

const int shift = 1 << 16;

struct Node {
  int mx;
  int push_add;
  Node() {
    mx = 0;
    push_add = 0;
  }
};

Node tree[2 * shift];

void push(int v) {
  Node& cur = tree[v];
  for (int h = 0; h < 2; ++h) {
    Node& child = tree[2 * v + h];
    child.push_add += cur.push_add;
    child.mx += cur.push_add;
  }
  cur.push_add = 0;
}

Node merge(const Node& l, const Node& r) {
  Node res = Node();
  res.mx = max(l.mx, r.mx);
  return res;
}

Node rmq(int v, int tl, int tr, int l, int r) {
  if (tr <= l || r <= tl) {
    return Node();
  }
  if (l <= tl && tr <= r) {
    return tree[v];
  }
  push(v);
  int tm = (tl + tr) / 2;
  Node ans = merge(rmq(2 * v, tl, tm, l, r), rmq(2 * v + 1, tm, tr, l, r));
  return ans;
}

Node get_min(int l, int r) {
  return rmq(1, 0, shift, l, r);
}

void modify(int v, int tl, int tr, int l, int r, int val) {
  if (tr <= l || r <= tl) {
    return;
  }
  if (l <= tl && tr <= r) {
    tree[v].mx += val;
    tree[v].push_add += val;
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  modify(2 * v, tl, tm, l, r, val);
  modify(2 * v + 1, tm, tr, l, r, val);
  tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
}

void update(int l, int r, int val) {
  return modify(1, 0, shift, l, r, val);
}

void build(int v, int tl, int tr) {
  if (tl + 1 == tr) {
    tree[v].mx = 0;
    tree[v].push_add = 0;
    return;
  }
  int tm = (tl + tr) / 2;
  build(2 * v, tl, tm);
  build(2 * v + 1, tm, tr);
  tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
}

void build() {
  return build(1, 0, shift);
}

void solve(bool read) {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> last(n, -1);
  vector<int> prev(n, -1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
    if (last[a[i]] != -1) {
      prev[i] = last[a[i]];
    }
    last[a[i]] = i;
  }

  vector<int> dp(n);
  for (int it = 0; it < k; ++it) {
    build();
    for (int i = 0; i + 1 < n; ++i) {
      update(i + 1, i + 2, dp[i]);
    }
    for (int i = 0; i < n; ++i) {
      update(prev[i] + 1, i + 1, 1);
      dp[i] = get_min(0, i + 1).mx;
    }

    /*for (int i = 0; i < n; ++i) {
      cout << dp[i] << " ";
    }
    cout << endl;*/

  }

  cout << dp[n - 1] << endl;

}