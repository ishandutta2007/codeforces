#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100100;
const int M = 1001;

int a[MAX_N];

vector<int> graph[MAX_N];
int tin[MAX_N];
int tout[MAX_N];

int b[MAX_N];
bitset<M> tree[4 * MAX_N];
bitset<M> primes;
bitset<M> values;

int m;

void dfs(int &timer, int v, int p) {
  tin[v] = ++timer;
  for (int u : graph[v]) {
    if (u == p) {
      continue;
    } 
    dfs(timer, u, v);
  }
  tout[v] = timer;
}

void build_tree(int v, int l, int r) {
  if (l == r) {
    tree[v].flip(b[l] % m);
    return;
  }

  int x = (l + r) / 2;
  build_tree(v + v, l, x);
  build_tree(v + v + 1, x + 1, r);

  tree[v] = tree[v + v] | tree[v + v + 1];
}

void print(const bitset<M> &bs) {
  for (int i = 0; i < m; i++) {
    cerr << bs[i];
  }
  cerr << "\n";
}

void rotate(bitset<M> &bs, int x) {
  // print(bs);

  x %= m;
  x = (m - x) % m;
  bs = ((bs << (m - x)) | (bs >> x)) & values;

  // print(bs);
}

int pls[4 * MAX_N];

void push(int v, bool is_leaf) {
  if (!is_leaf) {
    rotate(tree[v + v], pls[v]);
    rotate(tree[v + v + 1], pls[v]);

    (pls[v + v] += pls[v]) %= m;
    (pls[v + v + 1] += pls[v]) %= m;
  }

  pls[v] = 0;
}

void upd(int v, int l, int r, int ll, int rr, int x) {
  push(v, l == r);
  if (l == ll && rr == r) {
    (pls[v] += x) %= m;
    rotate(tree[v], x);
    return;
  }

  int mid = (l + r) / 2;
  if (ll <= mid) {
    upd(v + v, l, mid, ll, min(mid, rr), x);
  } 
  if (mid + 1 <= rr) {
    upd(v + v + 1, mid + 1, r, max(ll, mid + 1), rr, x);
  }

  tree[v] = tree[v + v] | tree[v + v + 1];
}

bitset<M> collector;

void collect(int v, int l, int r, int ll, int rr) {
  push(v, l == r);
  if (l == ll && rr == r) {
    collector |= tree[v];
    return;
  }

  int mid = (l + r) / 2;

  if (ll <= mid) {
    collect(v + v, l, mid, ll, min(mid, rr));
  } 
  if (mid + 1 <= rr) {
    collect(v + v + 1, mid + 1, r, max(ll, mid + 1), rr);
  }
}

void solve() {
  int n; scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i < n; i++) {
    int u, v; scanf("%d%d", &u, &v);
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  for (int i = 0; i < m; i++) {
    values.flip(i);
    if (i > 1) {
      bool flag = true;
      for (int j = 2; j * j <= i; j++) {
        if (i % j == 0) {
          flag = false;
        }
      }

      if (flag) {
        primes.flip(i);
      }
    }
  }

  int timer = 0;
  dfs(timer, 1, -1);
  for (int i = 1; i <= n; i++) {
    b[tin[i]] = a[i];
  }

  build_tree(1, 1, n);
  // print(tree[1]);
  int q; scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int tp; scanf("%d", &tp);
    if (tp == 1) {
      int v, x; scanf("%d%d", &v, &x);
      upd(1, 1, n, tin[v], tout[v], x);
      // print(tree[1]);
    } else {
      int v; scanf("%d", &v);
      collector = bitset<M>();
      collect(1, 1, n, tin[v], tout[v]);
      // print(collector);
      // print(primes);
      printf("%d\n", (primes & collector).count());
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int cases; cases = 1;

  for (int i = 0; i < cases; i++) {
    solve();
  }

  return 0;
}