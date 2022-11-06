#include <cstdio>
#include <iostream>
#include <vector>
#define MN 301000

typedef long long ll;
int ls[MN * 20], rs[MN * 20], tot = 0, rt[MN];
ll Min[MN * 20], lazy[MN * 20];
typedef std::pair<int, int> P;
std::vector<P> v[MN];
int n, m, dep[MN];
int h[MN], nxt[2 * MN], to[2 * MN], K = 0;

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

void add(int x, ll v) {Min[x] += v; lazy[x] += v;}

void pushdown(int x)
{
	if(lazy[x])
	{
		if(ls[x]) add(ls[x], lazy[x]);
		if(rs[x]) add(rs[x], lazy[x]);
		lazy[x] = 0;
	}
}

int merge(int x, int y, int l, int r)
{
	if(!x) return y;
	if(!y) return x;
	if(l == r)
	{
		Min[x] = std::min(Min[x], Min[y]);
		return x;
	}
	pushdown(x); pushdown(y);
	int mid = l + r >> 1;
	ls[x] = merge(ls[x], ls[y], l, mid);
	rs[x] = merge(rs[x], rs[y], mid + 1, r);
	Min[x] = std::min(Min[ls[x]], Min[rs[x]]);
	return x;
}

void modify(int x, int l, int r, int k, ll v)
{
	if(l == k && r == k) {Min[x] = std::min(Min[x], v); return;}
	int mid = l + r >> 1;
	if(k <= mid && !ls[x]) ls[x] = ++tot, Min[tot] = (ll)1e18;
	if(k > mid && !rs[x]) rs[x] = ++tot, Min[tot] = (ll)1e18;
	pushdown(x);
	if(k <= mid) modify(ls[x], l, mid, k, v);
	else if(k > mid) modify(rs[x], mid + 1, r, k, v);
	Min[x] = std::min(Min[ls[x]], Min[rs[x]]);
}

ll query(int x, int l, int r, int L, int R)
{
	if(!x) return (ll)1e18;
	if(l == L && r == R) return Min[x];
	pushdown(x); int mid = l + r >> 1;
	if(R <= mid) return query(ls[x], l, mid, L, R);
	else if(L > mid) return query(rs[x], mid + 1, r, L, R);
	else return std::min(query(ls[x], l, mid, L, mid), query(rs[x], mid + 1, r, mid + 1, R));
}

void dfs(int x, int fa)
{
	dep[x] = dep[fa] + 1;
	for(int i = h[x]; i; i = nxt[i])
		if(to[i] != fa) dfs(to[i], x);
	
	ll sum = 0;
	for(int i = h[x]; i; i = nxt[i])
		if(to[i] != fa)
		{
			sum += query(rt[to[i]], 1, n, 1, dep[x]);
			if(sum >= 1e18) {puts("-1"); exit(0);}
		}
	
	rt[x] = ++tot; Min[tot] = (ll)1e18;
	for(int i = 0; i < v[x].size(); i++)
		modify(rt[x], 1, n, dep[v[x][i].first], sum + v[x][i].second);
	
	for(int i = h[x]; i; i = nxt[i])
		if(to[i] != fa)
		{
			add(rt[to[i]], sum - query(rt[to[i]], 1, n, 1, dep[x]));
			rt[x] = merge(rt[x], rt[to[i]], 1, n);
		}
		
}

int main()
{
	Min[0] = 1e18;
	scanf("%d%d", &n, &m);
	if(n == 1) return 0 * puts("0");
	for(int i = 1; i < n; i++)
	{
		int u, v; scanf("%d%d", &u, &v);
		ins(u, v); ins(v, u);
	}
	for(int i = 1; i <= m; i++)
	{
		int u, v, c; scanf("%d%d%d", &u, &v, &c);
		::v[u].push_back(P(v, c));
	}
	dfs(1, 0);
	printf("%lld\n", query(rt[1], 1, n, 1, 1));
}