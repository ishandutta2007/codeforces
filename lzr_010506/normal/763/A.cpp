#include <bits/stdc++.h>
#define pb push_back
#define N 200010
using namespace std;
int n, cnt;
int Col[N],f[N],g[N],is[N],Bef[N],Suf[N],ans[N];
vector<int> mp[N];

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

void dfs1(int u, int Father)
{
	ans[u] = Father;
	for(auto v: mp[u])
		if(v != Father)
			dfs1(v, u);
	f[u] = 1;
	for(auto v: mp[u])
		if(v != Father && !f[v])
			f[u] = 0;
	for(auto v: mp[u])
		if(v != Father && Col[v] != Col[u])
			f[u] = 0;
}

void dfs2(int u, int Father)
{
	cnt = 0;
	for(auto v: mp[u])
		if(v != Father) 
			is[++ cnt] = v;
	Bef[0] = 1;
	for(int i = 1; i <= cnt; i ++)
		Bef[i] = Bef[i - 1] & f[is[i]] & (Col[is[i]] == Col[u]);
	Suf[cnt + 1] = 1;
	for(int i = cnt; i; i --)
		Suf[i] = Suf[i + 1] & f[is[i]] & (Col[is[i]] == Col[u]);
	for(int i = 1; i <= cnt; i ++)
		g[is[i]] = g[u] & Bef[i - 1] & Suf[i + 1] & (Col[u] == Col[Father]);
	for(auto v: mp[u])
		if(v != Father)
			dfs2(v, u);
}

int main()
{
	n = read();
	for(int i = 1; i < n; i ++)
	{
		int x = read();
		int y = read();
		mp[x].pb(y);
		mp[y].pb(x);
	}
	for(int i = 1; i <= n; i ++)
		Col[i] = read();
	dfs1(1, 0);
	g[1] = 1;
	Col[0] = Col[1];
	dfs2(1, 0);

	for(int i = 1; i <= n; i ++)
	{
		bool flag = g[i];
		for(auto v: mp[i]) if(v != ans[i]) flag &= f[v];
		if(flag)
		{
			printf("YES\n%d", i);
			return 0;
		}
	}
	printf("NO");
	return 0;
}