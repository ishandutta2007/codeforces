#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define MAXN (1 << 20)

int BT[MAXN];

/* Logically executes array[x] += v. */
void bit_add(int x, int v) {
  for(int i = x | MAXN; i < (MAXN << 1); i += i & -i) {
    BT[i ^ MAXN] += v;
  }
}
 
/* Returns the sum of array[i] for 0 <= i < x */
int bit_get(int x) {
  int ret = 0;
  for(int i = x - 1; x != 0; i &= i - 1) {
    ret += BT[i];
    if(!i) break;
  }
  return ret;
}

struct op {
  int cmd;
  int tm;
  int ind;
};

int main() {
  int N, Q;
  scanf("%d", &N);

  map<int, vector<op> > ops;
  vector<int> tmlst;
  for (int i = 0; i < N; i++) {
    int x;
    op o;
    scanf("%d%d%d", &o.cmd, &o.tm, &x);
    o.ind = i;
    ops[x].push_back(o);
    tmlst.push_back(o.tm);
  }

  sort(tmlst.begin(), tmlst.end());
  tmlst.resize(unique(tmlst.begin(), tmlst.end()) - tmlst.begin());

  vector<int> R(N, -1);
  for (auto it : ops) {
    for (auto& o : it.second) {
      o.tm = 1 + lower_bound(tmlst.begin(), tmlst.end(), o.tm) - tmlst.begin();
      if (o.cmd == 3) {
        R[o.ind] = bit_get(o.tm);
      } else {
        bit_add(o.tm, o.cmd == 1 ? 1 : -1);
      }
    }
    for (auto o : it.second) {
      if (o.cmd != 3) {
        bit_add(o.tm, o.cmd == 1 ? -1 : 1);
      }
    }
  }
  for (int i = 0; i < N; i++) {
    if (R[i] != -1) {
      cout << R[i] << '\n';
    }
  }

  return 0;
}