#include <bits/stdc++.h>
#define N 400010
using namespace std;
int n;
int fa[N],f[N],size[N],g[N];
struct Edge
{
	int to;
	Edge *next;
};
Edge *E[N],Tr[N<<1];
int cnt;
void addedge(int u,int v)
{
	Tr[++ cnt].to = v;
	Tr[cnt].next = E[u];
	E[u] = &Tr[cnt];
	Tr[++ cnt].to = u;
	Tr[cnt].next = E[v];
	E[v] = &Tr[cnt];
}

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

inline int max(int a, int b)
{
	if(a < b) return b;
	return a;
}

bool check(int u)
{
	int v = -1;
	for(Edge *P = E[u]; P; P = P -> next)
	{
		int t = 0;
		if(P -> to != fa[u])t = size[P -> to];
		else t = n - size[u];
		if(t > n / 2)v = P -> to;
	}
	if(v == -1)return true;
	if(v != fa[u])return size[v] - f[v] <= n / 2;
	return n - size[u] - g[u] <= n / 2;
}


void dfs(int u)
{
	for(Edge *P = E[u]; P; P = P -> next)
		if(P -> to != fa[u])
		{
			fa[P -> to] = u;
			dfs(P -> to);
			size[u] += size[P -> to];
			f[u] = max(f[P -> to], f[u]);
		}
	size[u] ++;
	if(size[u] <= n / 2)f[u] = size[u];
}

void dfs2(int u)
{
	if(n - size[u] <= n / 2)g[u] = n - size[u];
	int mx1 = 0;
	int mx2 = 0;
	for(Edge *P = E[u]; P; P = P -> next)
		if(P -> to != fa[u])
		{
			if(f[P -> to] < mx2)continue;
			mx2 = f[P -> to];
			if(mx2 > mx1)swap(mx1,mx2);
		}
	for(Edge *P = E[u]; P; P = P -> next)
		if(P -> to != fa[u])
		{
			int mx = mx1;
			if(mx == f[P->to])mx = mx2;
			
			g[P -> to] = max(g[u],mx);
			
			dfs2(P -> to);
		}
}

int main()
{
	n = read();
	for(int i = 1; i < n; i ++)
	{
		int u,v;
		u = read();
		v = read();
		addedge(u,v);
	}
	dfs(1);
	dfs2(1);
	for(int i = 1; i <= n; i ++)
		printf("%d ",check(i));
	return 0;
}