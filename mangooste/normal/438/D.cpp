#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Segment_tree {
  struct Node {
    int max_element, where_max_element;
    ll sum;

    Node(int max_element = 0, int where_max_element = -1, ll sum = 0) : max_element(max_element), where_max_element(where_max_element), sum(sum) {}

    Node operator + (Node n) {
      Node res = Node();
      res.sum = sum + n.sum;
      if (max_element > n.max_element) {
        res.max_element = max_element;
        res.where_max_element = where_max_element;
      } else {
        res.max_element = n.max_element;
        res.where_max_element = n.where_max_element;
      }
      return res;
    }
  };

  int n;
  vector<Node> tree;

  void unite(int n_) {
    n = n_;
    tree.assign(4 * n, Node());
  }

  void update_value(int pos, int new_value) {
    update_value(0, 0, n, pos, new_value);
  }

  void update_value(int v, int vl, int vr, int pos, int new_value) {
    if (pos < vl || vr <= pos) {
      return;
    }
    if (vr - vl == 1) {
      tree[v].sum = tree[v].max_element = new_value;
      tree[v].where_max_element = vl;
      return;
    }
    int vm = (vl + vr) / 2;
    update_value(2 * v + 1, vl, vm, pos, new_value);
    update_value(2 * v + 2, vm, vr, pos, new_value);
    tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
  }

  Node get(int L, int R) {
    return get(0, 0, n, L, R);
  }

  Node get(int v, int vl, int vr, int L, int R) {
    if (R <= vl || vr <= L) {
      return Node();
    }
    if (L <= vl && vr <= R) {
      return tree[v];
    }
    int vm = (vl + vr) / 2;
    return get(2 * v + 1, vl, vm, L, R) + get(2 * v + 2, vm, vr, L, R);
  }

  void update_by_mod(int L, int R, int mod) {
    while (true) {
      Node cur = get(0, 0, n, L, R);
      if (cur.max_element < mod) {
        break;
      }
      update_value(0, 0, n, cur.where_max_element, cur.max_element % mod);
    }
  }
};

int n, m;
Segment_tree tree;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  tree.unite(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    tree.update_value(i, x);
  }
  while (m--) {
    int type;
    cin >> type;
    if (type == 1) {
      int L, R;
      cin >> L >> R;
      cout << tree.get(L - 1, R).sum << '\n';
    } else if (type == 2) {
      int L, R, x;
      cin >> L >> R >> x;
      tree.update_by_mod(L - 1, R, x);
    } else {
      int pos, x;
      cin >> pos >> x;
      tree.update_value(pos - 1, x);
    }
  }
}