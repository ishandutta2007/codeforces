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
//const int mod = 1000000007;

using vec = std::array<double, 3>;
using matrix = std::array<vec, 3>;

vec mult(const matrix& m, const vec& v) {
  vec res;
  res.fill(0);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      res[i] += m[i][j] * v[j];
    }
  }
  return res;
}

matrix mult(const matrix& q, const matrix& w) {
  matrix res;
  for (int i = 0; i < 3; ++i) {
    res[i].fill(0);
  }
  for (int i = 0; i < 3; ++i) {
    for (int k = 0; k < 3; ++k) {
      for (int j = 0; j < 3; ++j) {
        res[i][j] += q[i][k] * w[k][j];
      }
    }
  }
  return res;
}

vec operator - (const vec& q, const vec& w) {
  vec res;
  res.fill(0);
  for (int i = 0; i < 3; ++i) {
    res[i] = q[i] - w[i];
  }
  return res;
}

matrix get_id() {
  matrix res;
  for (int i = 0; i < 3; ++i) {
    res[i].fill(0);
    res[i][i] = 1;
  }
  return res;
}

const int shift = 1 << 19;

struct Node {
  vec v;
  matrix push_m;
  Node() {
    push_m = get_id();
  }
};

Node tree[2 * shift];

void push(int v) {
  Node& cur = tree[v];
  for (int h = 0; h < 2; ++h) {
    Node& child = tree[2 * v + h];
    child.push_m = mult(cur.push_m, child.push_m);
    child.v = mult(cur.push_m, child.v);
  }
  cur.push_m = get_id();
}

Node rmq(int v, int tl, int tr, int id) {
  if (tl + 1 == tr) {
    return tree[v];
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (id < tm) {
    return rmq(2 * v, tl, tm, id);
  } else {
    return rmq(2 * v + 1, tm, tr, id);
  }
}

vec get_val(int id) {
  return rmq(1, 0, shift, id).v;
}

void modify(int v, int tl, int tr, int l, int r, matrix& m) {
  if (tr <= l || r <= tl) {
    return;
  }
  if (l <= tl && tr <= r) {
    tree[v].push_m = mult(m, tree[v].push_m);
    tree[v].v = mult(m, tree[v].v);
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  modify(2 * v, tl, tm, l, r, m);
  modify(2 * v + 1, tm, tr, l, r, m);
}

void update(int l, int r, matrix& m) {
  return modify(1, 0, shift, l, r, m);
}

void build(int v, int tl, int tr, const vector<vec>& vals) {
  if (tl >= vals.size()) {
    return;
  }
  if (tl + 1 == tr) {
    tree[v].push_m = get_id();
    tree[v].v = vals[tl];
    return;
  }
  int tm = (tl + tr) / 2;
  build(2 * v, tl, tm, vals);
  build(2 * v + 1, tm, tr, vals);
}

void build(const vector<vec>& vals) {
  return build(1, 0, shift, vals);
}

void solve(bool read) {
  int n, m;
  cin >> n >> m;
  vector<vec> vals(n + 1);
  for (int i = 0; i <= n; ++i) {
    vals[i] = {i, 0, 1};
  }
  build(vals);

  for (int i = 0; i < m; ++i) {
    int type, num, diff;
    cin >> type >> num >> diff;
    --num;
    if (type == 1) {
      vec beg = get_val(num), en = get_val(num + 1);
      vec d = en - beg;
      double x = d[0], y = d[1];
      double len = sqrt(x * x + y * y);
      x *= diff / len;
      y *= diff / len;
      matrix mat = get_id();
      mat[0][2] = x;
      mat[1][2] = y;
      update(num + 1, n + 1, mat);
    } else {
      double alpha = diff / 180. * acos(-1.0);
      vec beg = get_val(num);
      double x = beg[0], y = beg[1];
      matrix first = get_id(), last = get_id();
      first[0][2] = x;
      first[1][2] = y;
      last[0][2] = -x;
      last[1][2] = -y;
      matrix mid = get_id();
      mid[0][0] = mid[1][1] = cos(alpha);
      mid[0][1] = sin(alpha);
      mid[1][0] = -sin(alpha);
      matrix mat = mult(first, mult(mid, last));
      update(num + 1, n + 1, mat);
    }

    vec en = get_val(n);
    cout << en[0] << " " << en[1] << endl;
  }
}