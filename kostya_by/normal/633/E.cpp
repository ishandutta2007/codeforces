#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000100;
const int INF = 1000000001;

int a[MAX_N];
int b[MAX_N];

pair<int, int> tree[4 * MAX_N];

int f[MAX_N];

void init(int v, int l, int r) {
  tree[v] = make_pair(-INF, INF);
  if (l == r) {
    return;
  }

  int x = (l + r) / 2;
  init(v + v, l, x);
  init(v + v + 1, x + 1, r);
}

void upd(int v, int l, int r, int pos) {
  if (l == r) {
    tree[v] = make_pair(a[pos], b[pos]);
    return;
  }

  int x = (l + r) / 2;
  if (pos <= x) {
    upd(v + v, l, x, pos);
  } else {
    upd(v + v + 1, x + 1, r, pos);
  }

  tree[v].first = max(tree[v + v].first, tree[v + v + 1].first);
  tree[v].second = min(tree[v + v].second, tree[v + v + 1].second);
}

int get_pos(int v, int l, int r) {
  if (l == r) {
    return l;
  }

  int x = (l + r) / 2;
  if (tree[v + v].first > tree[v + v].second) {
    return get_pos(v + v, l, x);
  } else {
    return get_pos(v + v + 1, x + 1, r);
  }
}

pair<int, int> collector;

void get_fun(int v, int l, int r, int pos) {
  if (l == r) {
    collector.first = max(collector.first, tree[v].first);
    collector.second = min(collector.second, tree[v].second);
    return;
  }

  int x = (l + r) / 2;
  if (pos <= x) {
    return get_fun(v + v, l, x, pos);
  } else {
    collector.first = max(collector.first, tree[v + v].first);
    collector.second = min(collector.second, tree[v + v].second);
    get_fun(v + v + 1, x + 1, r, pos);
  }
}

void solve() {
  int n, k; scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    a[i] *= 100;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
  }

  a[n + 1] = INF;
  b[n + 1] = -INF;
  init(1, 1, n + 1);
  upd(1, 1, n + 1, n + 1);

  for (int i = n; i >= 1; i--) {
    upd(1, 1, n + 1, i);
    int pos = get_pos(1, 1, n + 1);

    collector = make_pair(-INF, INF);
    get_fun(1, 1, n + 1, pos);
    f[i] = min(collector.first, collector.second);
    if (i < pos) {
      collector = make_pair(-INF, INF);
      get_fun(1, 1, n + 1, pos - 1);
      f[i] = max(f[i], min(collector.first, collector.second));
    }
  }

  sort(f + 1, f + n + 1);

  long double answer = 0.0;
  long double q = 1.0 * k / n;
  for (int i = 1; i <= n; i++) {
    answer += f[i] * q;
    q *= (n - k - i + 1);
    q /= n - i;

    if (q < 1e-100) {
      break;
    }
  }

  printf("%.30lf\n", (double) answer);
}

int main() {
  int cases; cases = 1;

  for (int i = 0; i < cases; i++) {
    solve();
  }

  return 0;
}