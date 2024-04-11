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

struct node {
  int len;
  int max_block_len;
  int ans10, ans01;
  int left_type, cnt_left0, cnt_left1;
  int right_type, cnt_right0, cnt_right1;
  node() : 
    len(0), max_block_len(0), ans10(0), ans01(0), left_type(-1), cnt_left0(0), cnt_left1(0), right_type(-1), cnt_right0(0), cnt_right1(0)
  {}
};

int n, q;
string s;
vector<node> tree;
vector<char> mod;

node merge(node left, node right) {
  if (left.len == 0) {
    return right;
  }
  if (right.len == 0) {
    return left;
  }
  node ans;
  // len
  ans.len = left.len + right.len;
  // max_block_len
  ans.max_block_len = max(left.max_block_len, right.max_block_len);
  if (left.right_type == right.left_type) {
    ans.max_block_len = max(ans.max_block_len, left.cnt_right0 + right.cnt_left0);
  }
  // ans10
  ans.ans10 = max(left.ans10, right.ans10);
  if (left.right_type == 1) {
    if (right.left_type == 1) {
      ans.ans10 = max(ans.ans10, left.cnt_right0 + right.cnt_left0 + right.cnt_left1);
    } else {
      ans.ans10 = max(ans.ans10, left.cnt_right0 + right.cnt_left0);
    }
  } else if (right.left_type == 0) {
    ans.ans10 = max(ans.ans10, left.cnt_right1 + left.cnt_right0 + right.cnt_left0);
  }
  // ans01
  ans.ans01 = max(left.ans01, right.ans01);
  if (left.right_type == 0) {
    if (right.left_type == 0) {
      ans.ans01 = max(ans.ans01, left.cnt_right0 + right.cnt_left0 + right.cnt_left1);
    } else {
      ans.ans01 = max(ans.ans01, left.cnt_right0 + right.cnt_left0);
    }
  } else if (right.left_type == 1) {
    ans.ans01 = max(ans.ans01, left.cnt_right1 + left.cnt_right0 + right.cnt_left0);
  }
  // left parameters
  ans.left_type = left.left_type;
  if (left.cnt_left0 == left.len) {
    if (right.left_type == left.left_type) {
      ans.cnt_left0 = left.len + right.cnt_left0;
      ans.cnt_left1 = right.cnt_left1;
    } else {
      ans.cnt_left0 = left.len;
      ans.cnt_left1 = right.cnt_left0;
    }
  } else {
    ans.cnt_left0 = left.cnt_left0;
    ans.cnt_left1 = left.cnt_left1;
    if (left.cnt_left1 + left.cnt_left0 == left.len && right.left_type != left.left_type) {
      ans.cnt_left1 += right.cnt_left0;
    }
  }
  // right parameters
  ans.right_type = right.right_type;
  if (right.cnt_right0 == right.len) {
    if (left.right_type == right.right_type) {
      ans.cnt_right0 = right.len + left.cnt_right0;
      ans.cnt_right1 = left.cnt_right1;
    } else {
      ans.cnt_right0 = right.len;
      ans.cnt_right1 = left.cnt_right0;
    }
  } else {
    ans.cnt_right0 = right.cnt_right0;
    ans.cnt_right1 = right.cnt_right1;
    if (right.cnt_right1 + right.cnt_right0 == right.len && left.right_type != right.right_type) {
      ans.cnt_right1 += left.cnt_right0;
    }
  }
  return ans;
}

void build(int v, int vl, int vr) {
  if (vr - vl == 1) {
    tree[v].len = 1;
    tree[v].max_block_len = 1;
    tree[v].ans10 = tree[v].ans01 = 0;
    tree[v].left_type = tree[v].right_type = (s[vl] == '<' ? 0 : 1);
    tree[v].cnt_left0 = tree[v].cnt_right0 = 1;
    tree[v].cnt_left1 = tree[v].cnt_right1 = 0;
    return;
  }
  int vm = (vl + vr) / 2;
  build(2 * v + 1, vl, vm);
  build(2 * v + 2, vm, vr);
  tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
}

inline void push(int v, int vl, int vr) {
  if (mod[v]) {
    swap(tree[v].ans10, tree[v].ans01);
    tree[v].left_type ^= 1;
    tree[v].right_type ^= 1;
    if (vr - vl > 1) {
      mod[2 * v + 1] ^= 1;
      mod[2 * v + 2] ^= 1;
    }    
    mod[v] = 0;
  }
}

void update(int v, int vl, int vr, int L, int R) {
  push(v, vl, vr);
  if (R <= vl || vr <= L) {
    return;
  }
  if (L <= vl && vr <= R) {
    mod[v] ^= 1;
    return;
  }
  int vm = (vl + vr) / 2;
  update(2 * v + 1, vl, vm, L, R);
  update(2 * v + 2, vm, vr, L, R);
  push(2 * v + 1, vl, vm);
  push(2 * v + 2, vm, vr);
  tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
}

node get(int v, int vl, int vr, int L, int R) {
  push(v, vl, vr);
  if (R <= vl || vr <= L) {
    return node();
  }
  if (L <= vl && vr <= R) {
    return tree[v];
  }
  int vm = (vl + vr) / 2;
  return merge(get(2 * v + 1, vl, vm, L, R), get(2 * v + 2, vm, vr, L, R));
}

void Main() {
  cin >> n >> q >> s;
  tree.resize(4 * n);
  mod.resize(4 * n);
  build(0, 0, n);
  while (q--) {
    int L, R;
    cin >> L >> R;
    L--;
    update(0, 0, n, L, R);
    node cur = get(0, 0, n, L, R);
    cout << max(cur.max_block_len, cur.ans10) << '\n';
  }
}