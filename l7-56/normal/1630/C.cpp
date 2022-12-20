#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int n,a[maxn],lst[maxn],q[maxn],hd = 1,tl;

struct node {
  int l,r;
}b[maxn];
int tot;

int ans;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]), lst[a[i]] = i;
  for (int i = 1, mxr = 0; i <= n; ++i) {
    if (lst[a[i]] <= i + 1 || mxr >= lst[a[i]]) continue;
    // printf("[%d, %d]\n", i, lst[a[i]]);
    b[++tot] = (node) {i, lst[a[i]]};
    mxr = lst[a[i]];
  }
  for (int i = 1, mxr = 0; i <= tot; ) {
    // printf("[%d, %d]\n", b[i].l, b[i].r);
    while (hd <= tl && (q[hd] < b[i].l || q[hd] <= mxr)) ++hd;
    int cst = b[i].r - max(b[i].l, mxr) - 1 - (tl - hd + 1);
    // printf("%d\n", cst);
    if (cst <= 0) { ++i; continue; }
    ans += cst;
    mxr = b[i].r;
    q[++tl] = b[i].r;
    int j = i + 1;
    while (j < tot && b[i].r >= b[j + 1].l + 1) ++j;
    i = j;
  }
  printf("%d\n", ans);
  return 0;
}