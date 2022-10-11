#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

void Main();

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(10);
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Main();
#ifdef LOCAL
  cout << "\nTime: " << (int)ceil((double)1000 * clock() / CLOCKS_PER_SEC) << " ms";
#endif
}

struct Segment_tree {
  int n;
  vector<ll> tree, mod;

  void unite(int n_) {
    n = n_;
    tree.assign(4 * n, 0);
    mod.assign(4 * n, 0);
  }

  inline void push(int v, int vl, int vr) {
    tree[v] += mod[v];
    if (vr - vl > 1) {
      mod[2 * v + 1] += mod[v];
      mod[2 * v + 2] += mod[v];
    }
    mod[v] = 0;
  }

  void add(int L, int R, int delta) {
    add(0, 0, n, L, R, delta);
  }

  void add(int v, int vl, int vr, int L, int R, int delta) {
    push(v, vl, vr);
    if (R <= vl || vr <= L) {
      return;
    }
    if (L <= vl && vr <= R) {
      mod[v] += delta;
      return;
    }
    int vm = (vl + vr) / 2;
    add(2 * v + 1, vl, vm, L, R, delta);
    add(2 * v + 2, vm, vr, L, R, delta);
    push(2 * v + 1, vl, vm);
    push(2 * v + 2, vm, vr);
    tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
  }

  ll get() {
    push(0, 0, n);
    return tree[0];
  }
};

const ll INF = (ll)1e18;
int n;
vector<int> p, a;
Segment_tree tree;
ll ans = INF;

void Main() {
  cin >> n;
  p.resize(n);
  for (auto &el : p) {
    cin >> el;
  }
  a.resize(n);
  for (auto &el : a) {
    cin >> el;
  }
  tree.unite(n + 1);
  for (int i = 0; i < n; i++) {
    tree.add(p[i], n + 1, a[i]);
  }
  for (int i = 0; i < n - 1; i++) {
    tree.add(p[i], n + 1, -a[i]);
    tree.add(0, p[i], a[i]);
    ans = min(ans, tree.get());
  }
  cout << ans << '\n';
}