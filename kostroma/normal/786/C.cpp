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
//int timer = 1;

int testNumber = 1;

bool todo = true;

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
  cout.precision(10);
  cout << fixed;
  //cin >> t;
  int testNum = 1;
  while (t--) {
    //cerr << testNum << endl;
    //cout << "Case #" << testNum++ << ": ";
    solve(true);
    ++testNumber;
    //++timer;
  }

  /*while (true) {
      solve(false);
  }*/

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

class Treap {
public:
  typedef struct _node {
    int key;
    int cnt;
    int prior;
    _node* l;
    _node* r;
    _node(int key) :key(key), l(nullptr), r(nullptr), cnt(1) { prior = (rand() << 16) | rand(); }

    void push() {

    }

    void recalc() {
      cnt = 1 + Cnt(l) + Cnt(r);
    }

    static int Cnt(_node* v) {
      if (!v)
        return 0;
      return v->cnt;
    }
  }*node;

  static int Cnt(node v) {
    if (!v)
      return 0;
    return v->cnt;
  }

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

  void splitCnt(node v, int idx, node& l, node& r) {
    l = r = nullptr;
    if (!v)
      return;
    v->push();
    if (Cnt(v->l) < idx) {
      l = v;
      splitCnt(l->r, idx - Cnt(v->l) - 1, l->r, r);
      l->recalc();
    }
    else {
      r = v;
      splitCnt(r->l, idx, l, r->l);
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

  void insert(int key) { //insert at the idx - position
    node l = nullptr, r = nullptr;
    split(root, key, l, r);
    node cur_node = new _node(key);
    root = merge(merge(l, cur_node), r);
    ++Size;
  }

  void erase(int key) {
    node l = nullptr, m = nullptr, r = nullptr;
    split(root, key, l, m);
    split(m, key + 1, m, r);
    root = merge(l, r);
    --Size;
  }

  int get_val_by_pos (int key) {
    if (key >= Size) {
      return -1;
    }
    node l = nullptr, m = nullptr, r = nullptr;
    splitCnt(root, key, l, r);
    splitCnt(r, 1, m, r);
    if (m == nullptr) {
      throw runtime_error("IndexTreapOutOfBound");
    }
    int ans = m->key;
    root = merge(merge(l, m), r);
    return ans;
  }
};

typedef Treap::node Node;


void solve(bool read) {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int>> poses(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
    poses[a[i]].push_back(i);
  }
  set<pair<int, int>> candy;
  vector<int> next_uk(n, 0);
  Treap firsts;
  for (int i = 0; i < n; ++i) {
    if (poses[a[i]][0] == i) {
      firsts.insert(i);
      ++next_uk[a[i]];
    }
  }

  vector<vector<pair<int, int>>> dp(n + 1);
  for (int i = 1; i <= n; ++i) {
    dp[0].push_back({i, 0});
  }
  for (int i = 0; i < n; ++i) {
    for (auto item : dp[i]) {
      int k = item.first, val = item.second;
      int new_pos = firsts.get_val_by_pos(k);
      if (new_pos == -1) {
        new_pos = n;
      }
      dp[new_pos].push_back({k, val + 1});
    }
    firsts.erase(i);
    if (next_uk[a[i]] < poses[a[i]].size()) {
      firsts.insert(poses[a[i]][next_uk[a[i]]++]);
    }
  }

  vector<int> ans(n + 1, -1);
  for (auto item : dp[n]) {
    ans[item.first] = item.second;
  }
  for (int i = 1; i <= n; ++i) {
    assert(ans[i] != -1);
    cout << ans[i] << " ";
  }

}