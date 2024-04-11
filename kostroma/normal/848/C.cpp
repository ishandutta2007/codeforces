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

class Treap {
public:
  typedef struct _node {
    int key;
    int prior;
    int val;
    li sum;
    _node* l;
    _node* r;
    _node(int key, int val) :key(key), val(val), sum(val), l(nullptr), r(nullptr) { prior = (rand() << 16) | rand(); }

    void push() {

    }

    void recalc() {
      sum = val;
      if (l) {
        sum += l->sum;
      }
      if (r) {
        sum += r->sum;
      }
    }
  }*node;

  node root;

  size_t Size;

  node merge(node l, node r) {
    if (!l)
      return r;
    if (!r)
      return l;
    if (l->prior < r->prior) {
      l->push();
      l->r = merge(l->r, r);
      l->recalc();
      return l;
    }
    else {
      r->push();
      r->l = merge(l, r->l);
      r->recalc();
      return r;
    }
  }

  void split(node v, int key, node& l, node& r) {
    l = r = nullptr;
    if (!v)
      return;
    v->push();
    if (v->key < key) {
      l = v;
      split(l->r, key, l->r, r);
      l->recalc();
    }
    else {
      r = v;
      split(r->l, key, l, r->l);
      r->recalc();
    }
  }

public:
  Treap() {
    root = nullptr;
    Size = 0;
  }

  size_t size() const {
    return Size;
  }

  void insert(int, int);
  void erase(int);

  li get_sum(int L) {
    node l = nullptr, r = nullptr;
    split(root, L, l, r);
    li ans = 0;
    if (r) {
      ans = r->sum;
    }
    root = merge(l, r);
    return ans;
  }

};

typedef Treap::node Node;

vector<Node> free_nodes;

void Treap::insert(int key, int val) { //insert at the idx - position
  node l = nullptr, r = nullptr;
  split(root, key, l, r);
  node cur_node = nullptr;
  if (!free_nodes.empty()) {
    cur_node = free_nodes.back();
    free_nodes.pop_back();
    *cur_node = _node(key, val);
  } else {
    cur_node = new _node(key, val);
  }
  root = merge(merge(l, cur_node), r);
  ++Size;
}

void Treap::erase(int key) {
  node l = nullptr, m = nullptr, r = nullptr;
  split(root, key, l, m);
  split(m, key + 1, m, r);
  if (m) {
    free_nodes.push_back(m);
  }
  --Size;
  root = merge(l, r);
}

struct SegTree {
  int shift;
  vector<Treap> tree;

  SegTree(int n) {
    shift = 1;
    while (shift < n) {
      shift *= 2;
    }
    tree.assign(2 * shift, Treap());
  }

  li rmq(int l, int r, int L) {
    if (l >= r) {
      return 0;
    }
    if (l & 1) {
      return tree[l].get_sum(L) + rmq(l + 1, r, L);
    }
    if (r & 1) {
      return tree[r - 1].get_sum(L) + rmq(l, r - 1, L);
    }
    return rmq(l / 2, r / 2, L);
  }

  li get_sum(int l, int r) {
    return rmq(l + shift, r + shift, l);
  }

  void update(int v, int key, bool type) {
    int pos = v;
    v += shift;
    while (v) {
      if (type) {
        tree[v].insert(key, pos - key);
      } else {
        tree[v].erase(key);
      }
      v /= 2;
    }
  }
};


void solve(bool read) {
  //read = false;
  int n, Q;
  if (read) {
    cin >> n >> Q;
  } else {
    n = 100000;
    Q = 100000;
  }
  vector<int> a(n);
  vector<set<int>> poses(n);
  for (int i = 0; i < n; ++i) {
    if (read) {
      cin >> a[i];
      --a[i];
    } else {
      a[i] = rand() % n;
    }
    poses[a[i]].insert(i);
  }

  SegTree tree(n);
  for (int i = 0; i < n; ++i) {
    for (auto it = poses[i].begin(); it != poses[i].end(); ++it) {
      if (it != poses[i].begin()) {
        int prev_pos = *prev(it);
        tree.update(*it, prev_pos, true);
      }
    }
  }

  li sum_ans = 0;

  while (Q--) {
    int type;
    if (read) {
      cin >> type;
    } else {
      type = rand() % 2;
    }
    if (type == 1) {
      int id, x;
      if (read) {
        cin >> id >> x;
        --id;
        --x;
      } else {
        id = rand() % n;
        x = rand() % n;
      }

      int cur_val = a[id];
      auto it = poses[cur_val].find(id);
      int prev_pos = (it == poses[cur_val].begin()) ? -1 : *prev(it);
      int next_pos = (next(it) == poses[cur_val].end()) ? n : *next(it);
      if (prev_pos != -1) {
        tree.update(*it, prev_pos, false);
      }
      if (next_pos != n) {
        tree.update(next_pos, *it, false);
        if (prev_pos != -1) {
          tree.update(next_pos, prev_pos, true);
        }
      }
      poses[cur_val].erase(id);

      a[id] = x;
      poses[x].insert(id);
      it = poses[x].find(id);
      prev_pos = (it == poses[x].begin()) ? -1 : *prev(it);
      next_pos = (next(it) == poses[x].end()) ? n : *next(it);
      if (next_pos != n) {
        tree.update(next_pos, prev_pos, false);
        tree.update(next_pos, id, true);
      }
      if (prev_pos != -1) {
        tree.update(id, prev_pos, true);
      }

    } else {
      int l, r;
      if (read) {
        cin >> l >> r;
      } else {
        do {
          l = rand() % n + 1;
          r = rand() % n + 1;
        }
        while (l > r);
      }
      --l;
      if (read) {
        cout << tree.get_sum(l, r) << "\n";
      } else {
        sum_ans += tree.get_sum(l, r);
      }
    }
  }

  if (!read) {
    cout << sum_ans << endl;
  }

  //while(true);

}