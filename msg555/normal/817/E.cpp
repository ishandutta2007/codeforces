#include <iostream>
#include <vector>

using namespace std;

struct tnode {
  tnode() : cnt(0), lft(NULL), rht(NULL) {
  }

  tnode* get_lft() {
    if (!lft) {
      lft = new tnode;
    }
    return lft;
  }

  tnode* get_rht() {
    if (!rht) {
      rht = new tnode;
    }
    return rht;
  }

  void insert(int pos, int x, int v) {
    if (pos == -1) {
      cnt += v;
      return;
    }
    if (x & 1 << pos) {
      get_rht()->insert(pos - 1, x, v);
    } else {
      get_lft()->insert(pos - 1, x, v);
    }
    cnt = (lft ? lft->cnt : 0) + (rht ? rht->cnt : 0);
  }

  int query(int pos, int p, int L) {
    tnode* c1 = lft;
    tnode* c2 = rht;
    if (p & 1 << pos) {
      swap(c1, c2);
    }
    if (L & (1 << pos)) {
      return (c1 ? c1->cnt : 0) +
             (c2 ? c2->query(pos - 1, p, L) : 0);
    }
    return c1 ? c1->query(pos - 1, p, L) : 0;
  }

  int cnt;
  tnode* lft;
  tnode* rht;
};

int main() {
  tnode root;

  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    int p;
    int cmd;
    cin >> cmd >> p;
    if (cmd == 1 || cmd == 2) {
      root.insert(29, p, cmd == 1 ? 1 : -1);
    } else {
      int L;
      cin >> L;
      cout << root.query(29, p, L) << '\n';
    }
  }
  
  return 0;
}