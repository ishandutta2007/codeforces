#include <bits/stdc++.h>
using namespace std;

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
    if (x+1 <= nl || nr <= x)
      return;
    if (x <= nl && nr <= x+1) {
      nodes[id] = val;
      return;
    }
    int mid = (nl+nr)/2;
    _update(x, val, nl, mid, id<<1);
    _update(x, val, mid, nr, id<<1|1);
    nodes[id] = nodes[id<<1].merge(nodes[id<<1|1]);
  }
  int n;
  vector<Node> nodes;
};

struct Node {
  int colors=0;
  int toOpen=0;
  int toClose=0;
  Node merge(const Node& rhs) const {
    int done=min(rhs.toOpen, toClose);
    return Node{
      max(colors+rhs.toOpen-done, rhs.colors+toClose-done),
      toOpen+rhs.toOpen-done,
      toClose+rhs.toClose-done
    };
  }
};

void solve() {
  int n;
  while (cin >> n) {
    string s;
    cin >> s;
    string line(n, ' ');
    int cursor=0;
    SimpleSegtree<Node> st(n);
    for (char c : s) {
      switch(c) {
        case 'L':
          if (cursor>0)
            cursor--;
          break;
        case 'R':
          cursor++;
          break;
        case '(':
          st.update(cursor, Node{1, 0, 1});
          break;
        case ')':
          st.update(cursor, Node{1, 1, 0});
          break;
        default:
          st.update(cursor, Node{0, 0, 0});
      }
      Node ans = st.query(0, n);
      if (ans.toOpen > 0 || ans.toClose > 0)
        cout << -1 << ' ';
      else
        cout << ans.colors << ' ';
    }
    cout << endl;
  }
}

int main() {
  solve();
}