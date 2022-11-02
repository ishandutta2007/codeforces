#include <bits/stdc++.h>

using namespace std;

struct BIT { 
  vector<long long> f;
  
  BIT(int n=0) {
    f.assign(n, 0);
  }
  
  void upd(int at, long long by) {
    for (; at < f.size(); at = at | (at + 1))
      f[at] += by;
  }
  
  long long get(int at) {
    long long res = 0;
    for (; at >= 0; at = (at & (at + 1)) - 1)
      res += f[at];
    return res;
  }
  
  long long sum(int l, int r) {
    return get(r) - get(l - 1);
  }
};

BIT tree;
int cur_l;
int cur_r;
int reversed = 0;

void fold(int pos) {
  if (reversed)
    pos = cur_r - cur_l - pos;
  if (2 * pos - 1 + cur_l < cur_r) {
    reversed = 0;
    int ptr = 2 * pos - 1 + cur_l;
    for (int i = cur_l; i < cur_l + pos; i++) {
      long long val = tree.sum(i, i);
      tree.upd(i, -val);
      tree.upd(ptr, val);
      ptr--;
    }
    cur_l += pos;
  }
  else {
    reversed = 1;
    pos = cur_r - cur_l - pos;
    int ptr = -2 * pos + cur_r;
    for (int i = cur_r - 1; i >= cur_r - pos; i--) {
      long long val = tree.sum(i, i);
      tree.upd(i, -val);
      tree.upd(ptr, val);
      ptr++;
    }
    cur_r -= pos;
  }
}
 
int main() {
  ios_base::sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  cur_l = 0;
  cur_r = n;
  tree = BIT(n);
  for (int i = 0; i < n; i++)
    tree.upd(i, 1);
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int p;
      cin >> p;
      //cerr << p << " " << reversed << endl;
      fold(p);
      /*cerr << cur_l << " " << cur_r << " " << reversed << endl;
      for (int i = 0; i < n; i++)
        cerr << tree.sum(i, i) << " ";
      cerr << endl;*/
    } else {
      int l, r;
      cin >> l >> r;
      if (reversed) {
        //cerr << "l  r 1 " << l << " " << r << endl;
        int old_l = l;
        l = cur_r - cur_l - r;
        r = cur_r - cur_l - old_l - 1;
        //cerr << "l  r " << l << " " << r << endl;
      } else {
        r--;
      }
      cout << tree.sum(cur_l + l, cur_l + r) << "\n";
    }
  }
  return 0;
}