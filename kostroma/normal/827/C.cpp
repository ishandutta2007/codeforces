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

struct Node {
  int sum[4];
  Node() {
    memset(sum, 0, sizeof sum);
  }
};

Node merge(const Node& l, const Node& r) {
  Node res;
  for (int i = 0; i < 4; ++i) {
    res.sum[i] = l.sum[i] + r.sum[i];
  }
  return res;
}

int get_id(char c) {
  switch(c) {
    case 'A': return 0;
    case 'G' : return 1;
    case 'C' : return 2;
    case 'T' : return 3;
  }
}

struct SegTree {
  int shift = 1;
  string s;
  vector<Node> tree;
  SegTree(const string& s) : s(s) {
    while (shift < s.size()) {
      shift *= 2;
    }
    tree.assign(2 * shift, Node());
    for (int i = 0; i < s.length(); ++i) {
      ++tree[i + shift].sum[get_id(s[i])];
    }
    for (int i = shift - 1; i > 0; --i) {
      tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    }
  }
  void update(int v, char c) {
    char prev_c = s[v];
    s[v] = c;
    v += shift;
    --tree[v].sum[get_id(prev_c)];
    ++tree[v].sum[get_id(c)];
    v /= 2;
    while (v) {
      tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
      v /= 2;
    }
  }
  int rsq(int l, int r, int id) {
    if (l >= r) {
      return 0;
    }
    if (l & 1) {
      return tree[l].sum[id] + rsq(l + 1, r, id);
    }
    if (r & 1) {
      return tree[r - 1].sum[id] + rsq(l, r - 1, id);
    }
    return rsq(l / 2, r / 2, id);
  }
  int get_sum(int l, int r, char c) {
    return rsq(l + shift, r + shift, get_id(c));
  }
};

const int C = 11;

void solve(bool read) {
  string s;
  cin >> s;
  vector<vector<SegTree>> trees(C);
  for (int i = 1; i < C; ++i) {
    for (int j = 0; j < i; ++j) {
      string q;
      for (int r = j; r < s.length(); r += i) {
        q += s[r];
      }
      trees[i].push_back(SegTree(q));
    }
  }

  int Q;
  cin >> Q;
  for (int it = 0; it < Q; ++it) {
    int type;
    cin >> type;
    if (type == 1) {
      int x;
      char c;
      cin >> x >> c;
      --x;
      for (int i = 1; i < C; ++i) {
        int num = x % i, pos = x / i;
        trees[i][num].update(pos, c);
      }
    } else {
      int l, r;
      cin >> l >> r;
      --l;
      string t;
      cin >> t;
      int num = (int)t.length();
      int res = 0;
      for (int j = 0; j < num && l + j < r; ++j) {
        int L, R;
        int id = (l + j) % num, pos = (l + j) / num;
        int len = (r - 1 - l - j) / num + 1;
        res += trees[num][id].get_sum(pos, pos + len, t[j]);
      }
      cout << res << "\n";
    }
  }

}