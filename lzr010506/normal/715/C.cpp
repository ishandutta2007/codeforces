#include <bits/stdc++.h>
#define N 100010
#define ll long long
using namespace std;

int n,M;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

void gcd(ll a,ll b,ll& d,ll& x,ll& y)
{
	if(!b)d = a, x = 1, y = 0;
	else gcd(b, a % b, d, y, x), y -= x * (a / b);
}

int inv(int a,int p)
{
	if(p == 1)return 0;
	ll d, x, y;
	gcd(a, p, d, x, y);
	return (p + x % p) %p;
} 

struct Edge
{
	int to, dis;
	Edge *next;
};
Edge *E[N], e[N << 1];
int cnt;
void addedge(int u,int v,int w)
{
	e[++ cnt].to = v;
	e[cnt].dis = w;
	e[cnt].next = E[u];
	E[u] = &e[cnt];
	e[++ cnt].to = u;
	e[cnt].dis = w;
	e[cnt].next = E[v];
	E[v] = &e[cnt];
}
int size[N], vis[N];
ll ans;
map<int,int> has,has2;
int dfs1(int u,int fa)
{
	size[u] = 1;
	for(Edge *P = E[u]; P; P = P -> next)
		if(!vis[P -> to] && P -> to != fa) 
			size[u] += dfs1(P -> to, u);
	return ++ size[u];
}

int dfs2(int u,int fa,int s)
{
	for(Edge *P = E[u]; P; P = P -> next)
		if(!vis[P -> to] && P -> to != fa && size[P -> to] > s / 2)return dfs2(P -> to, u, s);
	return u;
}

void dfs3(int u,int fa,int now,int wei)
{
	int x = inv(wei, M);
	ans += has[1ll * (M - now % M) * x % M] - has2[1ll * (M - now % M) * x % M];
	wei = 1ll * wei * 10 % M;
	for(Edge *P = E[u]; P; P = P -> next)
		if(!vis[P -> to] && P -> to != fa)
			dfs3(P -> to, u, (1ll * now * 10 + P -> dis) % M, wei);
}

void dfs4(int u,int fa,int now,int wei)
{
	has[now % M] ++;
	wei = 1ll * wei * 10 % M;
	for(Edge *P = E[u]; P; P = P -> next)
		if(!vis[P -> to] && P -> to != fa)
			dfs4(P -> to, u, (1ll * wei * P -> dis + now) % M, wei);
}

void dfs5(int u,int fa,int now,int wei)
{ 
 	has2[now % M] ++;
	wei = 1ll * wei * 10 % M;
	for(Edge *P = E[u]; P; P = P -> next)
		if(!vis[P -> to] && P -> to != fa)
			dfs5(P -> to, u, (1ll * wei * P -> dis + now) % M, wei);
}

void solve(int u)
{
	u = dfs2(u, 0, dfs1(u,0));
	has[0] = 1;
	for(Edge *P = E[u]; P; P = P -> next)
		if(!vis[P -> to])
			dfs4(P -> to, u, P -> dis, 1);
	for(Edge *P = E[u]; P; P = P -> next)
		if(!vis[P -> to])
		{
			has2.clear();
			dfs5(P -> to, u, P -> dis, 1);
			dfs3(P -> to, u, P -> dis, 10);
		}
	ans += has[0] - 1;
	has.clear();
	vis[u] = 1;
	for(Edge *P = E[u]; P; P = P -> next)
		if(!vis[P -> to])
			solve(P -> to);
}

int main()
{
	scanf("%d%d",&n,&M);
	for(int i = 1; i < n; i ++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		u ++;
		v ++;
		addedge(u, v, w);
	}
	solve(1);
	cout << ans << endl;
	return 0;
}