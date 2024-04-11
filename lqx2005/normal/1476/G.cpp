#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, B = 2238, MV = 2e5;
struct Que {
  int l, r, k, t;
}q[N];
struct modi {
  int p, v, vr, t;
}cg[N];
int cgt = 0;
int n, m, a[N], tot = 0;
int bel[N], ans[N];
int pos[N], stk[N], top = 0;
int cnt[N], num[N];
int L, R, T;
int cmp(Que a, Que b) {
  if(bel[a.l] != bel[b.l]) return bel[a.l] < bel[b.l];
  if(bel[a.r] != bel[b.r]) return bel[a.r] < bel[b.r];
  if((bel[a.l] + bel[a.r]) & 1) return a.t < b.t;
  return a.t > b.t;
}

void dele(int x) {
  num[x]--;
  if(!num[x] && x) {
    pos[stk[top]] = pos[x];
    stk[pos[x]] = stk[top];
    top--;
    pos[x] = 0;
  }
  return;
}

void inser(int x) {
  if(!num[x] && x) {
    stk[++top] = x;
    pos[x] = top;
  }
  num[x]++;
  return;
}

void ins(int x) {
  dele(cnt[x]);
  cnt[x]++;
  inser(cnt[x]);
}

void del(int x) {
  dele(cnt[x]);
  cnt[x]--;
  inser(cnt[x]);
}

void modify(modi v, int t) {
  if(t == 1) {
    a[v.p] = v.v;
    if(v.p < L || R < v.p) return;
    del(v.vr);
    ins(v.v);
  } else {
    a[v.p] = v.vr;
    if(v.p < L || R < v.p) return;
    del(v.v);
    ins(v.vr);
  }
  return;
}

int query(int k) {
  sort(stk + 1, stk + top + 1);
  for(int i = 1; i <= top; i++) pos[stk[i]] = i;
  // for(int i = 1; i <= n; i++) printf("%d ", a[i]);
  // printf("\n");
  // for(int i = 1; i <= n; i++) printf("%d ", cnt[i]);
  // printf("\n");
  // printf("%d\n", k);
  // for(int i = 1; i <= top; i++) printf("%d ", stk[i]);
  // printf("\n");
  // for(int i = 1; i <= top; i++) printf("%d ", num[stk[i]]);
  // printf("\n");
  int las = 0, sum = 0, mn = n + 1;
  for(int i = 1; i <= top; i++) {
    while(las + 1 <= top && sum < k) las++, sum += num[stk[las]];
    if(sum >= k) mn = min(mn, stk[las] - stk[i]);
    sum -= num[stk[i]];
  }
  if(mn == n + 1) return -1;
  return mn;
}

void initS() {
  cg[0].t = -1;
  cg[cgt + 1].t = m + 1;
  L = 1, R = 0, T = cgt;
  num[0] = n;
  return;
}

int main(){
  // freopen("in.in", "r", stdin);
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int opt, l, r, k, p, x;
  for(int i = 1; i <= m; i++) {
    ans[i] = -2;
    scanf("%d", &opt);
    if(opt == 1) {
      scanf("%d%d%d", &l, &r, &k);
      q[++tot] = Que{l, r, k, i};
    } else {
      scanf("%d%d", &p, &x);
      cg[++cgt] = modi{p, x, a[p], i};
      a[p] = x;
    }
  }
  for(int i = 1; i <= n; i++) bel[i] = (i - 1) / B + 1;
  sort(q + 1, q + tot + 1, cmp);
  initS();
  for(int i = 1; i <= tot; i++) {
    int l = q[i].l, r = q[i].r, t = q[i].t;
    while(R < r) ins(a[++R]);
    while(L > l) ins(a[--L]);
    while(R > r) del(a[R--]);
    while(L < l) del(a[L++]);
    while(cg[T + 1].t <= t) modify(cg[++T], 1);
    while(cg[T].t > t) modify(cg[T--], -1);
    // cout << l <<" " << r <<" " << t << endl;
    ans[t] = query(q[i].k);
    // cout <<"ans " << ans[t] << endl;
  }
  for(int i = 1; i <= m; i++) if(ans[i] >= -1) printf("%d\n", ans[i]);
  return 0;
}