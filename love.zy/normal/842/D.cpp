#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 300005;
namespace trie {
  const int Len = 20;
  int st[MAXN*Len], ls[MAXN*Len], rs[MAXN*Len];
  int queue[MAXN], root, cnt, res;
  void pre(int val) {
    for(int i = Len; i >= 1; i--) {
      if((1 << (i - 1)) & val) {
        queue[Len - i] = 1;
      } else {
        queue[Len - i] = 0;
      }
    }
  }
  void insert2(int & cur, int deep) {
    if(!cur) cur = ++cnt;
    st[cur]++;
    if(deep == Len) return;
    if(queue[deep + 1]) {
      insert2(rs[cur], deep + 1);
    } else {
      insert2(ls[cur], deep + 1);
    }
  }
  void insert(int val) {
    pre(val);
    insert2(root, 0);
  }
  void query2(int cur, int deep) {
    if(deep == Len) return;
    if(!queue[deep + 1]) {
      if(st[ls[cur]] == (1 << Len - deep - 2)) {
        res += (1 << Len - deep - 2);
        query2(rs[cur], deep + 1);
      } else {
        query2(ls[cur], deep + 1);
      }
    } else {
      if(st[rs[cur]] == (1 << Len - deep - 2)) {
        res += (1 << Len - deep - 2);
        query2(ls[cur], deep + 1);
      } else {
        query2(rs[cur], deep + 1);
      }
    }
  }
  int query(int val) {
    pre(val);
    res = 0;
    query2(root, 0);
    return res;
  }
}
int n, m, a[MAXN];
int main() {
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1);
  n = unique(a + 1, a + n + 1) - a - 1;
  for(int i = 1; i <= n; i++) {
    trie::insert(a[i]);
  }
  int now = 0;
  while(m--) {
    int x; scanf("%d", &x);
    now ^= x;
    printf("%d\n", trie::query(now));
  }
  return 0;
}