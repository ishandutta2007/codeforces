#include <stdio.h>
#define MAXN 100005

struct edge
{
	int p, n;
	void var(int _n, int _p){n = _n; p = _p;}
}edges[MAXN * 2];
int a2t[MAXN], t2a[MAXN], n, cur[MAXN], goal[MAXN], g[MAXN], edge_size, depcnt[2], dep[MAXN], bit[2][MAXN], confine[MAXN][2], dfs_clock[2], ans[MAXN], backward[2][MAXN];
bool vis[MAXN];

inline int lowbit(int x){return x & (-x);}
int query(int a[], int pos)
{
	int retval = 0;
	for(; pos; pos -= lowbit(pos))
		retval ^= a[pos];
	return retval;
}
void update(int a[], int pos, int size)
{
	for(; pos <= size + 1; pos += lowbit(pos))
		a[pos] ^= 1;
}
void add_edge(int u, int v)
{
	edges[++ edge_size].var(v, g[u]);
	g[u] = edge_size;
	edges[++ edge_size].var(u, g[v]);
	g[v] = edge_size;
}
int init()
{
	int i, u, v;
	scanf("%d", &n);
	for(i = 1; i < n; i ++)
	{
		scanf("%d%d", &u, &v);
		add_edge(u, v);
	}
	for(i = 1; i <= n; i ++)
		scanf("%d", &cur[i]);
	for(i = 1; i <= n; i ++)
		scanf("%d", &goal[i]);
	return 0;
}
void dfs_build(int x, int depth)
{
	vis[x] = true;
	dep[x] = depth % 2;
	depcnt[dep[x]] ++;
	t2a[x] = ++ dfs_clock[dep[x]];
	backward[dep[x]][dfs_clock[dep[x]]] = x;
	for(int p = g[x]; p; p = edges[p].p)
		if(!vis[edges[p].n])
		{
			dfs_build(edges[p].n, depth + 1);
			confine[x][dep[x] ^ 1] = confine[edges[p].n][dep[x] ^ 1];
			confine[x][dep[x]] = confine[edges[p].n][dep[x]] ? confine[edges[p].n][dep[x]] : confine[x][dep[x]];
		}
	if(!confine[x][dep[x]])
		confine[x][dep[x]] = t2a[x];
}
int solve()
{
	int i;
	dfs_build(1, 1);
	for(i = 1; i <= n; i ++)
	{
		if(cur[i])
		{
			update(bit[dep[i]], t2a[i], depcnt[dep[i]]);
			update(bit[dep[i]], t2a[i] + 1, depcnt[dep[i]]);
		}
	}
	for(i = 1; i <= depcnt[1]; i ++)
		if(query(bit[1], i) != goal[backward[1][i]])
		{
			update(bit[1], i, depcnt[1]);
			update(bit[1], confine[backward[1][i]][1] + 1, depcnt[1]);
			ans[++ ans[0]] = backward[1][i];
		}
	for(i = 1; i <= depcnt[0]; i ++)
		if(query(bit[0], i) != goal[backward[0][i]])
		{
			update(bit[0], i, depcnt[0]);
			update(bit[0], confine[backward[0][i]][0] + 1, depcnt[0]);
			ans[++ ans[0]] = backward[0][i];
		}
	for(i = 0; i <= ans[0]; i ++)
		printf("%d\n", ans[i]);
	return 0;
}
int main()
{
	init();
	solve();
	return 0;
}