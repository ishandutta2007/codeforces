#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <bitset>
#include <deque>
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
#include <sstream>
#include <unordered_map>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve();
void precalc();
clock_t start;
//int timer = 1;

int testNumber = 1;

bool todo = true;

int main() {
#ifdef AIM
  freopen("/home/alexandero/ClionProjects/ACM/input.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#else
  //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen(FILENAME".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
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
    solve();
    ++testNumber;
    //++timer;
  }

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

template <typename T>
using Matrix = vector<vector<T>>;

#define int li

//const int mod = 1000000007;

struct Arr {
  pair<int, int> cur;
  Arr(): cur(0, 0) {}
  int& operator [] (size_t id) {
    if (id == 0) {
      return cur.first;
    }
    if (id == 1) {
      return cur.second;
    }
    assert(false);
  }
};

int merge_ans(Arr q, Arr w) {
  if (q[0] == -1 || w[0] == -1) {
    return 0;
  }
  Arr res;
  if (q[1] > 0) {
    res = q;
    if (w[0] == 0) {
      res[1] += w[1];
    }
    return res[0] + res[1];
  }
  res = w;
  res[0] += q[0];
  return res[0] + res[1];
}

Arr merge_right(Arr q, Arr w, int right_size) {
  if (w[0] == -1) {
    return w;
  }
  if (w[0] + w[1] != right_size) {
    return w;
  }
  if (q[0] == -1) {
    return w;
  }
  Arr res = w;
  if (q[1] == 0) {
    res[0] += q[0];
    return res;
  }
  if (w[0] == 0) {
    res[0] += q[0];
    res[1] += q[1];
    return res;
  }
  return res;
}

Arr merge_left(Arr q, Arr w, int left_size) {
  if (q[0] == -1) {
    return q;
  }
  if (q[0] + q[1] != left_size) {
    return q;
  }
  if (w[0] == -1) {
    return q;
  }
  Arr res = q;
  if (q[1] == 0) {
    res = w;
    res[0] += q[0];
    return res;
  }
  if (w[0] == 0) {
    res[1] += w[1];
    return res;
  }
  return res;
}

const int shift = 1 << 19;

struct Node {
  Arr lef, rig;
  int size;
  int best_ans;
  Node() {
    lef = Arr();
    rig = Arr();
    best_ans = 0;
    size = 0;
  }
  Node(int val) {
    lef = Arr();
    rig = Arr();
    if (val < 2) {
      best_ans = 1;
      lef[val] = 1;
      rig[val] = 1;
    }
    else {
      best_ans = 0;
      lef[0] = -1;
      lef[1] = -1;
      rig[0] = -1;
      rig[1] = -1;
    }
    size = 1;
  }
};

Node merge(const Node& q, const Node& w) {
  Node res;
  res.size = q.size + w.size;
  res.best_ans = max(q.best_ans, w.best_ans);
  res.best_ans = max(res.best_ans, merge_ans(q.rig, w.lef));
  res.lef = merge_left(q.lef, w.lef, q.size);
  res.rig = merge_right(q.rig, w.rig, w.size);
  res.best_ans = max(res.best_ans, res.lef[0] + res.lef[1]);
  res.best_ans = max(res.best_ans, res.rig[0] + res.rig[1]);
  return res;
}

Node tree[2 * shift];

Node rmq(int l, int r) {
  if (l >= r) {
    return Node();
  }
  if (l & 1) {
    return merge(tree[l], rmq(l + 1, r));
  }
  if (r & 1) {
    return merge(rmq(l, r - 1), tree[r - 1]);
  }
  return rmq(l / 2, r / 2);
}

int get_res(int l, int r) {
  return rmq(l + shift, r + shift).best_ans;
}

void update(int v, int val) {
  v += shift;
  tree[v] = Node(val);
  v /= 2;
  while (v) {
    tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
    v /= 2;
  }
}

int add[2 * shift];

void add_val(int l, int r, int val) {
  if (l >= r) {
    return;
  }
  if (l & 1) {
    add[l] += val;
    return add_val(l + 1, r, val);
  }
  if (r & 1) {
    add[r - 1] += val;
    return add_val(l, r - 1, val);
  }
  return add_val(l / 2, r / 2, val);
}

void modify(int l, int r, int val) {
  return add_val(l + shift, r + shift, val);
}

int get_val(int v) {
  v += shift;
  int res = 0;
  while (v) {
    res += add[v];
    v /= 2;
  }
  return res;
}

int get_value(int a, int b) {
  if (a == b) {
    return 2;
  }
  return a > b;
}

void solve() {
  int n;
  cin >> n;
  //n = 300000;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    //a[i] = rand();
    modify(i, i + 1, a[i]);
  }
  for (int i = 0; i + 1 < n; ++i) {
    int val = get_value(a[i], a[i + 1]);
    update(i, val);
  }

  int m;
  cin >> m;
  //m = 300000;
  for (int i = 0; i < m; ++i) {
    int l, r;
    int d;
    cin >> l >> r >> d;
    /*l = rand() % n + 1;
    r = rand() % n + 1;
    d = rand();
    if (l > r) {
      swap(l, r);
    }*/
    --l;
    modify(l, r, d);
    if (l > 0) {
      int val = get_value(get_val(l - 1), get_val(l));
      update(l - 1, val);
    }
    if (r < n) {
      int val = get_value(get_val(r - 1), get_val(r));
      update(r - 1, val);
    }
    cout << get_res(0, n) + 1 << "\n";
  }


}