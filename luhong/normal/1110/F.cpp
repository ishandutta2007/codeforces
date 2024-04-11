#include <cstdio>
#include <vector>
#include <cstring>
#define MN 2001000

int siz[MN]; 
long long ans[MN], Min[MN], lazy[MN];
struct xxx{int l, r, id;};
std::vector<xxx> v[MN];

void add(int x, long long v) {lazy[x] += v; Min[x] += v;}

void pd(int x) {if(lazy[x]) add(x << 1, lazy[x]), add(x << 1 | 1, lazy[x]), lazy[x] = 0;}

void modify(int x, int L, int R, int l, int r, long long v)
{
	if(l > r) return;
	if(L == l && R == r) {add(x, v); return;}
	pd(x); int mid = L + R >> 1;
	if(r <= mid) modify(x << 1, L, mid, l, r, v);
	else if(l > mid) modify(x << 1 | 1, mid + 1, R, l, r, v);
	else modify(x << 1, L, mid, l, mid, v), modify(x << 1 | 1, mid + 1, R, mid + 1, r, v);
	Min[x] = std::min(Min[x << 1], Min[x << 1 | 1]);
}

long long query(int x, int L, int R, int l, int r)
{
	if(L == l && R == r) return Min[x];
	pd(x); int mid = L + R >> 1;
	if(r <= mid) return query(x << 1, L, mid, l, r);
	else if(l > mid) return query(x << 1 | 1, mid + 1, R, l, r);
	else return std::min(query(x << 1, L, mid, l, mid), query(x << 1 | 1, mid + 1, R, mid + 1, r));
}

int h[MN], nxt[2 * MN], to[2 * MN], cost[2 * MN], K = 0;
int n;

void ins(int u, int v, int c) {nxt[++K] = h[u]; h[u] = K; to[K] = v; cost[K] = c;} 

void dfs(int x, int fa, long long d)
{
	siz[x] = 1;
	for(int i = h[x]; i; i = nxt[i]) if(to[i] != fa) dfs(to[i], x, d + cost[i]), siz[x] += siz[to[i]];
	if(siz[x] == 1) modify(1, 1, n, x, x, (long long)-1e18 + d);
}

void solve(int x, int fa, int c)
{
	modify(1, 1, n, x, x + siz[x] - 1, -c);
	modify(1, 1, n, 1, x - 1, c);
	modify(1, 1, n, x + siz[x], n, c);
	
	for(int i = h[x]; i; i = nxt[i]) if(to[i] != fa) solve(to[i], x, cost[i]);
	int S = v[x].size(); 
	for(int i = 0; i < S; i++) ans[v[x][i].id] = query(1, 1, n, v[x][i].l, v[x][i].r);
	
	modify(1, 1, n, x, x + siz[x] - 1, c);
	modify(1, 1, n, 1, x - 1, -c);
	modify(1, 1, n, x + siz[x], n, -c);
}

int main()
{
	int q; scanf("%d%d", &n, &q);
	std::fill(Min + 1, Min + 4 * n + 1, 1e18); 
	for(int i = 2; i <= n; i++) 
	{
		int p, w; scanf("%d%d", &p, &w);
		ins(p, i, w); ins(i, p, w);
	}
	for(int i = 1; i <= q; i++)
	{
		int l, r, v; scanf("%d%d%d", &v, &l, &r);
		::v[v].push_back(xxx{l, r, i});
	}
	dfs(1, 0, 0);
	solve(1, 0, 0);
	for(int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
}