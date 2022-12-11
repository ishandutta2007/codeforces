#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 400400;
const int MAX_L = 25;
int P;

bool is_prime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }

  return true;
}

void set_up() {
  // srand(time(NULL));
  srand(2318);

  P = 1000000000;
  int cnt = rand() % 20;
  while (true) {
    cnt -= is_prime(P);
    if (cnt == 0) {
      break;
    } else {
      P += 1;
    }
  }

   P = 1000000007;
}

struct Query {
  int pos;
  int value;
  int id;
};

struct Node {
  int lson;
  int rson;

  int mx;
  int cnt; 
};

Node tree[MAX_N * MAX_L];
int root[MAX_N]; 
int next_untaken;

int a[MAX_N];
int b[MAX_N];
pair<int, int> buffer[MAX_N];

int compress(int n, int a[]) {
  for (int i = 1; i <= n; i++) {
    buffer[i] = make_pair(a[i], i);
  }

  sort(buffer + 1, buffer + n + 1);
  int last_value = buffer[1].first;
  int last_compressed = 1;

  b[1] = last_value;

  for (int i = 1; i <= n; i++) {
    if (last_value < buffer[i].first) {
      last_value = buffer[i].first;
      last_compressed += 1;

      b[last_compressed] = last_value;
    }
    a[buffer[i].second] = last_compressed;
  }

  return last_compressed;
}

int build_tree(int l, int r) {
  int id = next_untaken++;

  tree[id].lson = -1;
  tree[id].rson = -1;
  tree[id].mx = 0;
  tree[id].cnt = 0;

  if (l < r) {
    int x = (l + r) / 2;
    tree[id].lson = build_tree(l, x);
    tree[id].rson = build_tree(x + 1, r);
  } 

  return id;
}

int query_mx;
int query_cnt;

void combine(int &mx_1, int &cnt_1, int mx_2, int cnt_2) {
  if (mx_1 < mx_2) {
    mx_1 = mx_2;
    cnt_1 = cnt_2;
  } else if (mx_1 == mx_2) {
    (cnt_1 += cnt_2) %= P;
  }
}

void query(int v, int l, int r, int ll, int rr) {
  if (l == ll && rr == r) {
    combine(query_mx, query_cnt, tree[v].mx, tree[v].cnt);
    return;
  }

  int x = (l + r) / 2;

  if (ll <= x) {
    query(tree[v].lson, l, x, ll, min(x, rr));
  }
  if (x + 1 <= rr) {
    query(tree[v].rson, x + 1, r, max(ll, x + 1), rr);
  }
}

int make_version(int v, int l, int r, int pos) {
  int id = next_untaken++;

  tree[id] = tree[v];
  if (l < r) {
    int x = (l + r) / 2;

    if (pos <= x) {
      tree[id].lson = make_version(tree[id].lson, l, x, pos);
    } else {
      tree[id].rson = make_version(tree[id].rson, x + 1, r, pos);
    }
  }

  return id;
}

void upd(int v, int l, int r, int pos, int mx, int cnt) {
  if (l == r) {
    combine(tree[v].mx, tree[v].cnt, mx, cnt);
    return;
  }

  int x = (l + r) / 2;

  if (pos <= x) {
    upd(tree[v].lson, l, x, pos, mx, cnt);
  } else {
    upd(tree[v].rson, x + 1, r, pos, mx, cnt);
  }

  tree[v].mx = tree[tree[v].lson].mx;
  tree[v].cnt = tree[tree[v].lson].cnt;

  combine(tree[v].mx, tree[v].cnt, tree[tree[v].rson].mx, tree[tree[v].rson].cnt);
}

Query queries[MAX_N];
int answer[MAX_N];

bool cmp_queries(const Query &a, const Query &b) {
  return a.pos > b.pos;
}

void solve() {
  int n, m; scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }

  /*int n = 400000;
  int m = 400000;
  for (int i = 1; i <= n; i++) {
    a[i] = rand() % 1000000000 + 1;
  }*/

  int h = compress(n, a);

  int total_mx = 0;
  int total_cnt = 0;

  root[0] = build_tree(0, h);
  for (int i = 1; i <= n; i++) {
    query_mx = 0;
    query_cnt = 0;
    query(root[i - 1], 0, h, 0, a[i] - 1);

    query_mx += 1;
    if (query_mx == 1) {
      query_cnt = 1;
    }

    root[i] = make_version(root[i - 1], 0, h, a[i]);
    upd(root[i], 0, h, a[i], query_mx, query_cnt);

    combine(total_mx, total_cnt, query_mx, query_cnt);
  }

  for (int i = 1; i <= m; i++) {
    int pos, value; scanf("%d%d", &pos, &value);

    //int pos = rand() % n + 1;
    //int value = rand() % 1000000000 + 1;

    queries[i].pos = pos;
    queries[i].value = value;
    queries[i].id = i;
  }

  sort(queries + 1, queries + m + 1, cmp_queries);
  int ptr = 1;
  
  int r = build_tree(0, h);
  for (int i = n; i >= 1; i--) {
    query_mx = 0;
    query_cnt = 0;
    query(root[i - 1], 0, h, 0, a[i] - 1);

    int mx_1 = query_mx;
    int cnt_1 = query_cnt;

    if (mx_1 == 0) {
      cnt_1 = 1;
    }

    query_mx = 0;
    query_cnt = 0;
    query(r, 0, h, 0, h - a[i]);
    int mx_2 = query_mx;
    int cnt_2 = query_cnt;

    if (mx_2 == 0) {
      cnt_2 = 1;
    }

    int lcs_without_i = total_mx;
    if (mx_1 + mx_2 + 1 == total_mx && (cnt_1 * 1ll * cnt_2) % P == total_cnt) {
      lcs_without_i -= 1;
    }

    // processing queries
    while (ptr <= m && queries[ptr].pos == i) {
      int value = queries[ptr].value;

      int compressed_1 = 0;
      int left = 1;
      int right = h;
      while (left <= right) {
        int middle = (left + right) / 2;
        if (b[middle] < value) {
          compressed_1 = middle;
          left = middle + 1;
        } else {
          right = middle - 1;
        }
      }

      int compressed_2 = h + 1;
      left = 1;
      right = h;
      while (left <= right) {
        int middle = (left + right) / 2;
        if (b[middle] > value) {
          compressed_2 = middle;
          right = middle - 1;
        } else {
          left = middle + 1;
        }
      }
      compressed_2 = h - compressed_2 + 1;

      query_mx = 0;
      query(root[i - 1], 0, h, 0, compressed_1);
      int mx_1 = query_mx;

      query_mx = 0;
      query(r, 0, h, 0, compressed_2);
      int mx_2 = query_mx;

      answer[queries[ptr].id] = max(lcs_without_i, mx_1 + mx_2 + 1);
      ptr++;
    }

    upd(r, 0, h, h - a[i] + 1, mx_2 + 1, cnt_2);
  } 

  for (int i = 1; i <= m; i++) {
    printf("%d\n", answer[i]);
  }
}

int main() {
  set_up();

  int cases; cases = 1;

  for (int i = 0; i < cases; i++) {
    solve();
  }

  return 0;
}