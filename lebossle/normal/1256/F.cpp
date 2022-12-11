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

typedef long long int lli;

struct Node {
  lli sum=0;
  Node merge(const Node& rhs) const {
    return Node{sum+rhs.sum};
  }
};

lli inversions(string s) {
  SimpleSegtree<Node> st(26);
  lli ans=0;
  for (char c : s) {
    st.update(c-'a', Node{st.query(c-'a', c-'a'+1).sum+1});
    if (c != 'z')
      ans += st.query(c-'a'+1, 26).sum;
  }
  return ans;
}

void solve() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  bool ans = (inversions(s)%2 == inversions(t)%2);
  if (set<char>(s.begin(), s.end()).size()  < s.size())
    ans = true;
  if (set<char>(t.begin(), t.end()).size()  < t.size())
    ans = true;
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  if (s != t)
    ans = false;
  cout << (ans ? "YES" : "NO") << endl;
}

int main() {
  int t;
  cin >> t;
  for (int ta=0; ta<t; ++ta)
    solve();
}