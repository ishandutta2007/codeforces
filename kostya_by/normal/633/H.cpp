#include <bits/stdc++.h>

using namespace std;

const int N = 3;
const int MAX_N = 30030;

int BLOCK = 250;

int MOD;

struct Matrix {
  unsigned int a[N][N];
  Matrix() {
    memset(a, 0, sizeof(a));
  }

  void make_identity() {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        a[i][j] = (i == j);
      }
    }
  }

  void print() const {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cerr << a[i][j] << " ";
      }
      cerr << "\n";
    }
    cerr << "\n";
  }
};

struct Query {
  int l;
  int r;
  int id;
};

bool cmp_queries(const Query &a, const Query &b) {
  return make_pair((a.l - 1) / BLOCK, a.r) < make_pair((b.l - 1) / BLOCK, b.r);
}

void multiply(const Matrix &a, const Matrix &b, Matrix &c) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      unsigned int value = 0ul;

      for (int k = 0; k < N; k++) {
        value += a.a[i][k] * b.a[k][j];
      }

      c.a[i][j] = value % MOD;
    }
  }
}

int a[MAX_N];
int real_a[MAX_N];
pair<int, int> buffer[MAX_N];

int compress_a(int n, int a[], int real_a[]) {
  for (int i = 1; i <= n; i++) {
    buffer[i] = make_pair(a[i], i);
  }
  sort(buffer + 1, buffer + n + 1);

  int h = 1;
  real_a[1] = buffer[1].first;
  a[buffer[1].second] = 1;

  for (int i = 2; i <= n; i++) {
    if (real_a[h] < buffer[i].first) {
      real_a[h + 1] = buffer[i].first;
      h += 1;
    }
    a[buffer[i].second] = h;
  }

  return h;
}

Matrix tree[4 * MAX_N];
int counters[MAX_N];

int h;

void build_tree(int v, int l, int r) {
  tree[v].make_identity();
  if (l == r) {
    return;
  }

  int x = (l + r) / 2;

  build_tree(v + v, l, x);
  build_tree(v + v + 1, x + 1, r);
}

void switch_on(int pos) {
  int v = 1;
  int l = 1;
  int r = h;

  while (l < r) {
    int x = (l + r) / 2;
    if (pos <= x) {
      v = v + v;
      r = x;
    } else {
      v = v + v + 1;
      l = x + 1;
    }
  }

  tree[v].a[0][0] = 0;
  tree[v].a[0][1] = 1;
  tree[v].a[0][2] = 0;

  tree[v].a[1][0] = 1;
  tree[v].a[1][1] = 1;
  tree[v].a[1][2] = 0;

  tree[v].a[2][0] = 0;
  tree[v].a[2][1] = real_a[pos] % MOD;
  tree[v].a[2][2] = 1;

  v >>= 1;
  while (v) {
    // --------------------------------
    tree[v].a[0][0] = (tree[v + v + 1].a[0][0] * tree[v + v].a[0][0] + tree[v + v + 1].a[0][1] * tree[v + v].a[1][0] + tree[v + v + 1].a[0][2] * tree[v + v].a[2][0]) % MOD;
    tree[v].a[0][1] = (tree[v + v + 1].a[0][0] * tree[v + v].a[0][1] + tree[v + v + 1].a[0][1] * tree[v + v].a[1][1] + tree[v + v + 1].a[0][2] * tree[v + v].a[2][1]) % MOD;
    tree[v].a[0][2] = (tree[v + v + 1].a[0][0] * tree[v + v].a[0][2] + tree[v + v + 1].a[0][1] * tree[v + v].a[1][2] + tree[v + v + 1].a[0][2] * tree[v + v].a[2][2]) % MOD;

    tree[v].a[1][0] = (tree[v + v + 1].a[1][0] * tree[v + v].a[0][0] + tree[v + v + 1].a[1][1] * tree[v + v].a[1][0] + tree[v + v + 1].a[1][2] * tree[v + v].a[2][0]) % MOD;
    tree[v].a[1][1] = (tree[v + v + 1].a[1][0] * tree[v + v].a[0][1] + tree[v + v + 1].a[1][1] * tree[v + v].a[1][1] + tree[v + v + 1].a[1][2] * tree[v + v].a[2][1]) % MOD;
    tree[v].a[1][2] = (tree[v + v + 1].a[1][0] * tree[v + v].a[0][2] + tree[v + v + 1].a[1][1] * tree[v + v].a[1][2] + tree[v + v + 1].a[1][2] * tree[v + v].a[2][2]) % MOD;

    tree[v].a[2][0] = (tree[v + v + 1].a[2][0] * tree[v + v].a[0][0] + tree[v + v + 1].a[2][1] * tree[v + v].a[1][0] + tree[v + v + 1].a[2][2] * tree[v + v].a[2][0]) % MOD;
    tree[v].a[2][1] = (tree[v + v + 1].a[2][0] * tree[v + v].a[0][1] + tree[v + v + 1].a[2][1] * tree[v + v].a[1][1] + tree[v + v + 1].a[2][2] * tree[v + v].a[2][1]) % MOD;
    tree[v].a[2][2] = (tree[v + v + 1].a[2][0] * tree[v + v].a[0][2] + tree[v + v + 1].a[2][1] * tree[v + v].a[1][2] + tree[v + v + 1].a[2][2] * tree[v + v].a[2][2]) % MOD;
    // --------------------------------
    v >>= 1;
  }
}

void switch_off(int pos) {
  int v = 1;
  int l = 1;
  int r = h;

  while (l < r) {
    int x = (l + r) / 2;
    if (pos <= x) {
      v = v + v;
      r = x;
    } else {
      v = v + v + 1;
      l = x + 1;
    }
  }

  tree[v].make_identity();

  v >>= 1;
  while (v) {
    // --------------------------------
    tree[v].a[0][0] = (tree[v + v + 1].a[0][0] * tree[v + v].a[0][0] + tree[v + v + 1].a[0][1] * tree[v + v].a[1][0]) % MOD;
    tree[v].a[0][1] = (tree[v + v + 1].a[0][0] * tree[v + v].a[0][1] + tree[v + v + 1].a[0][1] * tree[v + v].a[1][1]) % MOD;
    tree[v].a[0][2] = 0ul;

    tree[v].a[1][0] = (tree[v + v + 1].a[1][0] * tree[v + v].a[0][0] + tree[v + v + 1].a[1][1] * tree[v + v].a[1][0]) % MOD;
    tree[v].a[1][1] = (tree[v + v + 1].a[1][0] * tree[v + v].a[0][1] + tree[v + v + 1].a[1][1] * tree[v + v].a[1][1]) % MOD;
    tree[v].a[1][2] = 0ul;

    tree[v].a[2][0] = (tree[v + v + 1].a[2][0] * tree[v + v].a[0][0] + tree[v + v + 1].a[2][1] * tree[v + v].a[1][0] + tree[v + v + 1].a[2][2] * tree[v + v].a[2][0]) % MOD;
    tree[v].a[2][1] = (tree[v + v + 1].a[2][0] * tree[v + v].a[0][1] + tree[v + v + 1].a[2][1] * tree[v + v].a[1][1] + tree[v + v + 1].a[2][2] * tree[v + v].a[2][1]) % MOD;
    tree[v].a[2][2] = 1ul;
    // --------------------------------
    v >>= 1;
  }
}

void add_value(int x) {
  if (counters[x] == 0) {
    switch_on(x);
  }

  counters[x] += 1;
}

void delete_value(int x) {
  if (counters[x] == 1) {
    switch_off(x);
  }

  counters[x] -= 1;
}

int get_answer() {
  // tree[1].print();

  return (int) tree[1].a[2][1];
}

Query queries[MAX_N];
int answer[MAX_N];

void solve() {
  int n; scanf("%d%d", &n, &MOD);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }

  h = compress_a(n, a, real_a);
  build_tree(1, 1, h);

  int q; scanf("%d", &q);
  for (int it = 0; it < q; it++) {
    int l, r; scanf("%d%d", &l, &r);

    queries[it].l = l;
    queries[it].r = r;
    queries[it].id = it;
  }

  sort(queries, queries + q, cmp_queries);
  int l = queries[0].l;
  int r = queries[0].r;
  for (int i = l; i <= r; i++) {
    add_value(a[i]);
  }
  answer[queries[0].id] = get_answer();

  for (int i = 1; i < q; i++) {
    // cerr << l << " " << r << "\n";

    while (r < queries[i].r) {
      r += 1;
      add_value(a[r]);
    }
    while (queries[i].l < l) {
      l -= 1;
      add_value(a[l]);
    }
    while (r > queries[i].r) {
      delete_value(a[r]);
      r -= 1;
    }
    while (queries[i].l > l) {
      delete_value(a[l]);
      l += 1;
    }
    answer[queries[i].id] = get_answer();
  }

  for (int i = 0; i < q; i++) {
    printf("%d\n", answer[i]);
  }
}

int main() {
  int cases; cases = 1;

  for (int i = 0; i < cases; i++) {
    solve();
  } 

  return 0;
}