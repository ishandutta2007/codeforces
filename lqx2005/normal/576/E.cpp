#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define mid ((l + r) / 2)
#define ls (p) * 2
#define rs (p) * 2 + 1
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int N = 5e5 + 10, K = 52;

int f[N], t[N], suf[N], vis[N];
int n, m, k, Q;
int e[N], c[N], bl[N], col[N], top = 0;
vector<pii> g[N << 2];
piii st[N << 1];
struct Mergeset
{
  int fa[N << 1], siz[N << 1], C;
  void init(int n){ for(int i = 1; i <= n * 2; i++) fa[i] = i, siz[i] = 1; }
  int find(int x){for(; fa[x] != x; x = fa[x]); return x;}
  void merge(int x, int y)
  {
    x = find(x), y = find(y);
    if(x == y) return;
    if(siz[x] > siz[y]) swap(x, y);
    fa[x] = y, siz[y] += siz[x];
    st[++top] = mp( mp(x, y), C);
    return;
  }
  int Merge(int u, int v)
  {
    merge(u, v + n);
    merge(v, u + n);
    if(find(u) == find(u + n) || find(v) == find(v + n)) return 0;
    return 1;
  }
}s[K];

void revoke(int be)
{
  while(top > be)
  {
    int u = st[top].x.x, v = st[top].x.y, c = st[top].y;
    s[c].fa[u] = u, s[c].siz[v] -= s[c].siz[u];
    top--;
  }
  return;
}
void modify(int p, int l, int r, int L, int R, int id, int c)
{
  if(L <= l && r <= R) return g[p].push_back(mp(id, c)), void();
  if(L <= mid) modify(ls, l, mid, L, R, id, c);
  if(R > mid) modify(rs, mid + 1, r, L, R, id, c);
  return;
}



void pushd(int x, int id, int c)
{
  if(c == 0) return;
  if(x + 1 > suf[x] - 1) return;
  // cout << x <<" "<< id <<" "<< c <<" " << suf[x]<< endl;
  modify(1, 1, Q, x + 1, suf[x] - 1, id, c);
  return;
}

void build(int p, int l, int r, int opt)
{
  int bk = top;
  for(int i = 0; i < (int)g[p].size(); i++)  
  {
    if(!opt) break;
    int id = g[p][i].x, c = g[p][i].y;
    // cout << id << " "<< c << endl;
    if(s[c].Merge(f[id], t[id])) continue;
    opt = 0;
  }
  // cout << l <<" "<< r <<" "<< opt << endl;
  if(l == r)
  {
    if(opt) pushd(l, e[l], c[l]), col[e[l]] = c[l];
    else pushd(l, e[l], col[e[l]]);
    bl[l] = opt;
  } 
  else
  {
    build(ls, l, mid, opt);
    build(rs, mid + 1, r, opt);
  }
  revoke(bk);
  return;
}


int main()
{
  scanf("%d%d%d%d", &n, &m, &k, &Q);
  for(int i = 1; i <= k; i++) s[i].init(n), s[i].C = i;
  for(int i = 1; i <= m; i++) scanf("%d%d", &f[i], &t[i]);
  for(int i = 1; i <= Q; i++) scanf("%d%d", &e[i], &c[i]), modify(1, 1, Q, i, i, e[i], c[i]);
  for(int i = 1; i <= m; i++) vis[i] = Q + 1;
  for(int i = Q; i >= 1; i--) suf[i] = vis[e[i]], vis[e[i]] = i;
  build(1, 1, Q, 1);
  for(int i = 1; i <= Q; i++) printf(bl[i] ? "YES\n" : "NO\n");
  return 0;
}