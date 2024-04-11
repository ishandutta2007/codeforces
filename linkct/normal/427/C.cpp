#include <stdio.h>
#include <iostream>
#define MAXN 100005
#define MAXM 300005
using std :: cout;
using std :: endl;
using std :: min;
typedef long long int ll;

struct edge
{
	int n, p;
	void var(int _n, int _p)
	{
		n = _n;
		p = _p;
	}
}edges[MAXM];
int g[MAXN], n, m, scccnt, dfs_clock, sccno[MAXN], s[MAXN], c, edge_size, price[MAXN], pre[MAXN], dfn[MAXN], min_price[MAXN], ways[MAXN];
bool ins[MAXN];

void add_edge(int f, int t)
{
	edges[++ edge_size].var(t, g[f]);
	g[f] = edge_size;
}
int init()
{
	int i, s, t;
	scanf("%d", &n);
	for(i = 1; i <= n; i ++)
		scanf("%d", &price[i]);
	scanf("%d", &m);
	for(i = 1; i <= m; i ++)
	{
		scanf("%d%d", &s, &t);
		add_edge(s, t);
	}
	return 0;
}
void tarjan(int x)
{
	pre[x] = dfn[x] = ++ dfs_clock;
	s[++ c] = x;
	ins[x] = true;
	for(int p = g[x]; p; p = edges[p].p)
		if(!dfn[edges[p].n])
		{
			tarjan(edges[p].n);
			pre[x] = min(pre[x], pre[edges[p].n]);
		}
		else if(ins[edges[p].n])
			pre[x] = min(pre[x], dfn[edges[p].n]);
	if(pre[x] == dfn[x])
	{
		scccnt ++;
		while(s[c --] != x)
		{
			sccno[s[c + 1]] = scccnt;
			ins[s[c + 1]] = false;
		}
		sccno[s[c + 1]] = scccnt;
		ins[s[c + 1]] = false;
	}
}
int solve()
{
	int i;
	ll ans = 0;
	for(i = 1; i <= n; i ++)
		if(!dfn[i])
			tarjan(i);
	for(i = 1; i <= scccnt; i ++)
		min_price[i] = 1000000010;
	for(i = 1; i <= n; i ++)
		if(price[i] < min_price[sccno[i]])
		{
			min_price[sccno[i]] = price[i];
			ways[sccno[i]] = 1;
		}
		else if(price[i] == min_price[sccno[i]])
			ways[sccno[i]] ++;
	for(i = 1; i <= scccnt; i ++)
		ans += (ll)min_price[i];
	cout << ans << ' ';
	ans = 1;
	for(i = 1; i <= scccnt; i ++)
		ans = ans * (ll)ways[i] % 1000000007LL;
	cout << ans << endl;
	return 0;
}
int main()
{
	init();
	solve();
	return 0;
}