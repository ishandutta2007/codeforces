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

struct SegTree {
  int shift;
  vector<int> tree;
  SegTree(int n) {
    shift = 1;
    while (shift < n) {
      shift *= 2;
    }
    tree.assign(2 * shift, shift);
  }
  void update(int v, int val) {
    v += shift;
    tree[v] = val;
    v /= 2;
    while (v) {
      tree[v] = min(tree[2 * v], tree[2 * v + 1]);
      v /= 2;
    }
  }
  int rmq(int l, int r) {
    if (l >= r) {
      return shift;
    }
    if (l & 1) {
      return min(tree[l], rmq(l + 1, r));
    }
    if (r & 1) {
      return min(tree[r - 1], rmq(l, r - 1));
    }
    return rmq(l / 2, r / 2);
  }
  int get_min(int l, int r) {
    return rmq(l + shift, r + shift);
  }
};

int get_min(int l, int r, int n, SegTree& tree) {
  //cout << l << " " << r << " " << n << endl;
  //cout << tree.get_min(0, l) << " " << tree.get_min(r, n) << endl;
  return min(min(tree.get_min(0, l), tree.get_min(r, n)), n);
}

void solve(bool read) {
  //read = false;
  int n;
  vector<int> s(2);
  if (read) {
    cin >> n >> s[0] >> s[1];
  } else {
    n = 100000;
    s[0] = ((rand() << 16) | rand()) % 1000000000;
    s[1] = ((rand() << 16) | rand()) % 1000000000;
  }
  vector<int> x(n);
  vector<pair<int, int>> coords;
  set<int> have;
  for (int i = 0; i < n; ++i) {
    if (read) {
      cin >> x[i];
    } else {
      do {
        x[i] = ((rand() << 16) | rand()) % 1000000000;
      } while (have.count(x[i]));
    }
    coords.push_back({x[i], i});
  }
  sort(all(coords));

  int L = abs(s[1] - s[0]) - 1, R = (int)1e9 + 1;
  while (L + 1 < R) {
    int M = (L + R) / 2;
    SegTree tree(n);
    for (int i = 0; i < n; ++i) {
      tree.update(i, coords[i].second);
    }
    vector<int> pref(n + 1, 0);
    for (int c : s) {
      auto start_it = lower_bound(all(coords), make_pair(c - M, 0));
      auto finish_it = upper_bound(all(coords), make_pair(c + M, n));
      int val = get_min(start_it - coords.begin(), finish_it - coords.begin(), n, tree);
      ++pref[0];
      --pref[val];
    }
    int transes = 0;
    bool flag = true;
    for (int i = 0; i < n; ++i) {
      transes += pref[i];
      if (transes == 0) {
        flag = false;
        break;
      }
      int c = x[i];
      auto start_it = lower_bound(all(coords), make_pair(c - M, 0));
      auto finish_it = upper_bound(all(coords), make_pair(c + M, n));
      int val = get_min(start_it - coords.begin(), finish_it - coords.begin(), n, tree);
      assert(val > i);
      ++pref[i + 1];
      --pref[val];
      int id = lower_bound(all(coords), make_pair(x[i], i)) - coords.begin();
      //assert(coords[id] == make_pair(x[i], i));
      tree.update(id, n);
    }
    if (flag) {
      R = M;
    } else {
      L = M;
    }
  }

  cout << R << endl;

}