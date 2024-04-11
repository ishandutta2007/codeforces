#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 4e5 + 20;
int n, m, c[maxn];
int st[maxn], ed[maxn], ind;
long long f[maxn << 2];
int tag[maxn << 2];
std::vector<int> G[maxn];
int dfn[maxn];

void build(int l,int r,int s)
{
	if(l == r) f[s] = 1LL << (c[dfn[l]] - 1);
	else
	{
		int mid = (l + r) >> 1;
		build(l, mid, s << 1);
		build(mid + 1, r, s << 1 | 1);
		f[s] = f[s << 1] | f[s << 1 | 1];
	}
}
void dfs(int a,int fa)
{
	st[a] = ++ind;
	dfn[ind] = a;
	for(int i = 0; i < G[a].size(); i++)
	{
		int v = G[a][i];
		if(v != fa) dfs(v, a);
	}
	ed[a] = ind;
}
void pushdown(int x)
{
	if(tag[x])
	{
		f[x << 1] = f[x << 1 | 1] = 1LL << (tag[x] - 1);
		tag[x << 1] = tag[x << 1 | 1] = tag[x], tag[x] = 0;
	}
}
void change(int l,int r,int col,int ll,int rr,int s)
{
	if(ll == l && rr == r)
	{
		f[s] = 1LL << (col - 1);
		tag[s] = col;
	}
	else
	{
		int mid = (ll + rr) >> 1;
		pushdown(s);
		if(r <= mid) change(l, r, col, ll, mid, s << 1);
		else if(l > mid) change(l, r, col, mid + 1, rr, s << 1 | 1);
		else change(l, mid, col, ll, mid, s << 1), change(mid + 1, r, col, mid + 1, rr, s << 1 | 1);
		f[s] = f[s << 1] | f[s << 1 | 1];
	}
}
long long query(int l,int r,int ll,int rr,int s)
{
	if(l == ll && r == rr) return f[s];
	int mid = (ll + rr) >> 1;
	pushdown(s);
	if(r <= mid) return query(l, r, ll, mid, s << 1);
	if(l > mid) return query(l, r, mid + 1, rr, s << 1 | 1);
	return query(l, mid, ll, mid, s << 1) | query(mid + 1, r, mid + 1, rr, s << 1 | 1);
}
int count(long long x)
{
	int ret = 0;
	while(x) ret += x & 1, x >>= 1;
	return ret;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	
	scanf("%d%d", &n, &m);
	
	for(int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	for(int i = 1, u, v; i < n; i++)
	{
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs(1, 0), build(1, n, 1);

	for(int t = 1; t <= m; t++)
	{
		int p, v, c;
		
		scanf("%d", &p);
		
		if(p == 1)
			scanf("%d%d", &v, &c), change(st[v], ed[v], c, 1, n, 1);
		else
			scanf("%d", &v), printf("%d\n", count(query(st[v], ed[v], 1, n, 1)));
	}
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}