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

struct Query {
  int lx, rx;
  int ly, ry;
  int sign;
  int id;
};

struct Simple {
  int x;
  int l, r;
  int sign;
  int id;
  bool operator < (const Simple& ot) const {
    return x < ot.x;
  }
};

struct SegTree {
  int shift;
  vector<int> tree;
  explicit SegTree(int n) {
    shift = 1;
    while (shift < n) {
      shift *= 2;
    }
    tree.assign(2 * shift, 0);
  }
  int rsq(int l, int r) {
    if (l >= r) {
      return 0;
    }
    if (l & 1) {
      return tree[l] + rsq(l + 1, r);
    }
    if (r & 1) {
      return tree[r - 1] + rsq(l, r - 1);
    }
    return rsq(l / 2, r / 2);
  }
  void update(int v, int val) {
    v += shift;
    while (v) {
      tree[v] += val;
      v /= 2;
    }
  }
  int get_sum(int l, int r) {
    return rsq(l + shift, r + shift);
  }
};

void solve(bool read) {
  //read = false;
  int n, Q;
  if (read) {
    cin >> n >> Q;
  } else {
    n = 200000;
    Q = 200000;
  }
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    int cur;
    if (read) {
      cin >> cur;
      --cur;
    } else {
      cur = i;
    }
    p[cur] = i;
  }

  if (!read) {
    random_shuffle(all(p));
  }

  vector<Query> q;
  for (int i = 0; i < Q; ++i) {
    int l, d, r, u;
    if (read) {
      cin >> l >> d >> r >> u;
      --l;
      --d;
      --r;
      --u;
    } else {
      do {
        l = rand() % n;
        r = rand() % n;
      } while (l > r);
      do {
        d = rand() % n;
        u = rand() % n;
      } while (d > u);
    }
    //cout << l << " " << d << " " << r << " " << u << endl;
    if (u < n - 1) {
      q.push_back({u + 1, n, 0, n, 1, i});
    }
    if (d > 0) {
      q.push_back({0, d, 0, n, 1, i});
    }
    if (l > 0) {
      q.push_back({0, n, 0, l, 1, i});
    }
    if (r < n - 1) {
      q.push_back({0, n, r + 1, n, 1, i});
    }

    if (u < n - 1 && r < n - 1) {
      q.push_back({u + 1, n, r + 1, n, -1, i});
    }
    if (u < n - 1 && l > 0) {
      q.push_back({u + 1, n, 0, l, -1, i});
    }

    if (d > 0 && r < n - 1) {
      q.push_back({0, d, r + 1, n, -1, i});
    }
    if (d > 0 && l > 0) {
      q.push_back({0, d, 0, l, -1, i});
    }
  }

  vector<int> num(q.size(), 0);
  vector<Simple> qus;
  for (int i = 0; i < q.size(); ++i) {
    auto& cur_q = q[i];
    if (cur_q.lx > 0) {
      qus.push_back({cur_q.lx - 1, cur_q.ly, cur_q.ry, -1, i});
    }
    qus.push_back({cur_q.rx - 1, cur_q.ly, cur_q.ry, 1, i});
  }

  sort(all(qus));
  SegTree tree(n);
  int uk = 0;
  for (int i = 0; i < n; ++i) {
    tree.update(p[i], 1);
    while (uk < qus.size() && qus[uk].x == i) {
      //cout << tree.get_sum(qus[uk].l, qus[uk].r) << " " << qus[uk].id << endl;
      num[qus[uk].id] += tree.get_sum(qus[uk].l, qus[uk].r) * qus[uk].sign;
      ++uk;
    }
  }

  vector<li> ans(Q, n * 1LL * (n - 1) / 2);
  for (int i = 0; i < q.size(); ++i) {
    ans[q[i].id] -= q[i].sign * num[i] * 1LL * (num[i] - 1) / 2;
  }

  li sum = 0;
  for (int i = 0; i < Q; ++i) {
    if (read) {
      cout << ans[i] << "\n";
    } else {
      sum += ans[i];
    }
  }

  if (!read) {
    cout << sum << endl;
  }

}