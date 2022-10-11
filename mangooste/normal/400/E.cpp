#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Segment_tree { ;

  struct node {
    int len, left, right;
    ll ans;

    node(int len = 0, int left = 0, int right = 0, ll ans = 0ll) : len(len), left(left), right(right), ans(ans) {}
  };

  int n;
  vector<node> tree;

  void unite(int n_) {
    n = n_;
    tree.resize(4 * n);
    build(0, 0, n);
  }

  void build(int v, int vl, int vr) {
    tree[v] = node(vr - vl, 0, 0, 0);
    if (vr - vl > 1) {
      int vm = (vl + vr) / 2;
      build(2 * v + 1, vl, vm);
      build(2 * v + 2, vm, vr);
    }
  }

  inline ll C2(int n) {
    return 1ll * n * (n + 1) / 2;
  }

  inline node merge(node L, node R) {
    node cur;
    cur.len = L.len + R.len;
    cur.ans = L.ans + R.ans - C2(L.right) - C2(R.left) + C2(L.right + R.left);
    cur.left = (L.len == L.left ? L.len + R.left : L.left);
    cur.right = (R.right == R.len ? R.len + L.right : R.right);
    return cur;
  }

  void update(int pos) {
    update(0, 0, n, pos);
  }

  void update(int v, int vl, int vr, int pos) {
    if (pos < vl || vr <= pos) {
      return;
    }
    if (vr - vl == 1) {
      tree[v].ans = tree[v].left = tree[v].right ^= 1;
      return;
    }
    int vm = (vl + vr) / 2;
    update(2 * v + 1, vl, vm, pos);
    update(2 * v + 2, vm, vr, pos);
    tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
  }

  ll get() {
    return tree[0].ans;
  }
};

const int LOG = 18;
int n, m;
vector<int> a, p2;
vector<Segment_tree> tree;

void precalc() {
  p2.resize(LOG);
  p2[0] = 1;
  for (int i = 1; i < LOG; i++) {
    p2[i] = p2[i - 1] * 2;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  precalc();
  cin >> n >> m;
  a.resize(n);
  for (auto &el : a) {
    cin >> el;
  }
  tree.resize(LOG);
  for (int i = 0; i < LOG; i++) {
    tree[i].unite(n);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < LOG; j++) {
      if (a[i] & (1 << j)) {
        tree[j].update(i);
      }
    }
  }
  while (m--) {
    int pos, value;
    cin >> pos >> value;
    pos--;
    ll ans = 0;
    for (int i = 0; i < LOG; i++) {
      if (((a[pos] >> i) & 1) != ((value >> i) & 1)) {
        tree[i].update(pos);
      }
      ans += 1ll * p2[i] * tree[i].get();
    }
    a[pos] = value;
    cout << ans << '\n';
  }
}