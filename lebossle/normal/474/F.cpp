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
  int g;
  int amtG;
  Node merge(const Node& rhs) const {
    int newG = __gcd(g, rhs.g);
    return Node {
      newG,
      (newG==g ? amtG : 0) + (newG==rhs.g ? rhs.amtG : 0)
    };
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> s(n);
  for (int& i : s)
    cin >> i;
  SimpleSegtree<Node> st(n);
  for (int i=0; i<n; ++i) {
    st.update(i, Node{s[i], 1});
    LOG(st.query(i, i+1).g);
    LOG(st.query(i, i+1).amtG);
  }
  int t;
  cin >> t;
  for (int ta=0; ta<t; ++ta) {
    int l, r;
    cin >> l >> r;
    cout << (r-l+1)-st.query(l-1, r).amtG << '\n';
  }
}