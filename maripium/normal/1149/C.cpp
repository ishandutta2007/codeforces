#include <bits/stdc++.h>

using namespace std;

const int N = 200200;

struct Data {
  int mn, mx;
  int pre, suf;
  int ans;
};

char s[N];
Data t[N << 2];
int lz[N << 2];

void push(int v,int l,int r) {
  if (lz[v]) {
    t[v].mn += lz[v];
    t[v].mx += lz[v];
    t[v].pre -= lz[v];
    t[v].suf -= lz[v];
    if (l < r) {
      lz[v << 1] += lz[v];
      lz[v << 1 | 1] += lz[v];
    }
    lz[v] = 0;
  }
}

Data mrg(Data l, Data r) {
  Data ans;
  ans.mn = min(l.mn, r.mn);
  ans.mx = max(l.mx, r.mx);
  ans.pre = max(l.pre, r.pre);
  ans.pre = max(ans.pre, l.mx - r.mn - r.mn);
  ans.suf = max(l.suf, r.suf);
  ans.suf = max(ans.suf, r.mx - l.mn - l.mn);
  ans.ans = max(l.ans, r.ans);
  ans.ans = max(ans.ans, l.mx + r.suf);
  ans.ans = max(ans.ans, l.pre + r.mx);
  return ans;
}

void add(int v,int l,int r,int L,int R,int val) {
  push(v, l, r);
  if (L > r || R < l) return;
  if (L <= l && r <= R) {
    lz[v] = val;
    push(v, l, r);
    return;
  }
  int md = (l + r) >> 1;
  add(v << 1, l, md, L, R, val);
  add(v << 1 | 1, md + 1, r, L, R, val);
  t[v] = mrg(t[v << 1], t[v << 1 | 1]);
}

int main() {
  int n, q;
  scanf("%d %d %s", &n, &q, s + 1);
  n = n + n - 2;
  for (int i = 1; i <= n; ++i) {
    add(1, 1, n, i, n, (s[i] == '(' ? 1 : -1));
  }
  printf("%d\n", t[1].ans);
  while (q--) {
    int x, y;
    scanf("%d %d", &x, &y);
    add(1, 1, n, x, n, (s[x] == '(' ? -1 : 1));
    add(1, 1, n, y, n, (s[y] == '(' ? -1 : 1));
    swap(s[x], s[y]);
    add(1, 1, n, x, n, (s[x] == '(' ? 1 : -1));
    add(1, 1, n, y, n, (s[y] == '(' ? 1 : -1));
    printf("%d\n", t[1].ans);
  }
}