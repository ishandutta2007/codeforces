#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pii pair<int, int>
#define pcc pair<char, char>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
#define ALL(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 300005;
const int M = 300005;
queue<int>Q;
vector<int>V[N];

struct Edge
{
	int next,to;
}e[N << 1];

int tot,head[N];

void insert(int u,int v)
{
	e[++tot].to = v;
	e[tot].next = head[u];
	head[u] = tot;
}

int n,m,s,p[N],x[N],y[N],vis[N],ans[N];


int main()
{
	n = read();
	m = read();
	s = read();
	rep(i, 1, m)
	{
		p[i] = read();
		x[i] = read();
		y[i] = read();
		if(p[i] == 1)insert(x[i],y[i]);
	}
	rep(i, 1, m)
	{
		if(p[i] == 1)continue;
		V[x[i]].pb(i);
		V[y[i]].pb(i);
	}
	Q.push(s);
	vis[s] = 1;
	while(!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for(int i = head[u]; i; i = e[i].next)
		{
			int v = e[i].to;
			if(!vis[v])
			{
				vis[v] = 1;
				Q.push(v);
			}
		}
		int nn = V[u].size();
		rep(i, 0, nn - 1)
		{
			int ct = V[u][i];
			int uu = x[ct], vv = y[ct];
			if(u==uu)
			{
				if(!vis[vv])
				{
					vis[vv] = 1;
					ans[ct] = 1;
					Q.push(vv);
				}
			}
			else
			{
				if(!vis[uu])
				{
					vis[uu] = 1;
					ans[ct] = 0;
					Q.push(uu);
				}
			}
		}
	}
	int Ans=0;
	rep(i, 1, n)
		if(vis[i])
			Ans ++;
	printf("%d\n",Ans);
	rep(i, 1, m)
		if(p[i] == 2)
			if(!ans[i]) printf("-");
			else printf("+");
	puts("");
	memset(vis, 0, sizeof(vis));
	Q.push(s);
	vis[s] = 1;
	while(!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for(int i = head[u]; i; i = e[i].next)
		{
			int v = e[i].to;
			if(!vis[v])
			{
				vis[v] = 1;
				Q.push(v);
			}
		}
	}
	Ans = 0;
	rep(i, 1, n)
		if(vis[i])
			Ans ++;
	printf("%d\n", Ans);
	rep(i, 1, m)
	{
		if(p[i] == 1)continue;
		int u = x[i], v =y[i];
		if(vis[u] && (!vis[v])) printf("-");
		else printf("+");
	}
	puts("");
	return 0;
}