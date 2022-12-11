#include <bits/stdc++.h>
using namespace std;

// This code uses the bossle/cp library
// Available at https://github.com/bossle/cp

// #pragma STDC FENV_ACCESS OFF
// #pragma STDC FP_CONTRACT ON
// #pragma STDC CX_LIMITED_RANGE ON
// #pragma GCC optimize "O3"

namespace cp_base {

auto init = (
  ios::sync_with_stdio(false),
  cin.tie(nullptr)
);

}  // namespace cp_base

       

#define LOG(x) 

template<class Node>
class SimpleSegtree {
 public:
  SimpleSegtree(int n) :
    n(n),
    nodes(4*n) {
  }
  Node query(int l, int r) {
    return _query(l, r, 0, n, 1);
  }
  void update(int x, Node v) {
    _update(x, v, 0, n, 1);
  }
 private:
  Node _query(int l, int r, int nl, int nr, int id) {
    if (l <= nl && nr <= r)
      return nodes[id];
    int mid = (nl+nr)/2;
    if (r <= mid)
      return _query(l, r, nl, mid, id<<1);
    if (mid <= l)
      return _query(l, r, mid, nr, (id<<1)|1);
    return _query(l, r, nl, mid, id<<1).merge(
           _query(l, r, mid, nr, id<<1|1));
  }
  void _update(int x, Node val, int nl, int nr, int id) {
    if (nr-nl == 1) {
      nodes[id] = val;
      return;
    }
    int mid = (nl+nr)/2;
    if (x < mid)
      _update(x, val, nl, mid, id<<1);
    else
      _update(x, val, mid, nr, id<<1|1);
    nodes[id] = nodes[id<<1].merge(nodes[id<<1|1]);
  }
  int n;
  vector<Node> nodes;
};

/*
struct Node {
  Node merge(const Node& rhs) const
};
*/

struct Node {
  int sum=0;
  Node merge(const Node& rhs) const {
    return Node{sum + rhs.sum};
  }
};

SimpleSegtree<Node> st(0);

int getCurPos(int origPos) {
  return st.query(0, origPos).sum;
}

int main() {
  int n, m;
  cin >> n >> m;
  string orig;
  cin >> orig;
  st = SimpleSegtree<Node>(n);
  for (int i=0; i<n; ++i)
    st.update(i, Node{1});
  map<char, set<int>> pos;
  for (int i=0; i<n; ++i)
    pos[orig[i]].insert(i);
  for (int ma=0; ma<m; ++ma) {
    int l, r;
    char c;
    cin >> l >> r >> c;
    l--;
    int origL = l, auxR = n;
    while (auxR-origL > 1) {
      int mid = (origL+auxR)/2;
      if (getCurPos(mid) <= l)
        origL = mid;
      else
        auxR = mid;
    }
    LOG(make_tuple(ma, origL, l, r));
    vector<int> toDelete;
    for (auto it = pos[c].lower_bound(origL); it != pos[c].end() && getCurPos(*it) < r; ++it)
      toDelete.push_back(*it);
    for (int i : toDelete) {
      st.update(i, Node{0});
      pos[c].erase(i);
    }
  }
  for (int i=0; i<n; ++i)
    if (st.query(i, i+1).sum == 1)
      cout << orig[i];
  cout << endl;
}