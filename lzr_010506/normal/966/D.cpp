#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
#define ite iterator
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
 	return x * f;
}
using namespace std;
const int N = 3e5 + 10;
int n,m,siz,d[N],dis[N],top,st[N],p[N],pre[N];
int cnt,head[N], nxt[N + N], to[N + N];
bool vis[N];

void add_edge(int u, int v)
{
	nxt[++ cnt] = head[u];
	to[cnt] = v;
	head[u] = cnt;
}

void dfs(int u)
{
	vis[u] = 1;
	st[++ siz] = u;
	for(int i = head[u],v; i; i = nxt[i])
		if(!vis[v = to[i]])
			dfs(v);
}
int main()
{
	n = read();
	m = read();
	rep(i, 1, m)
	{
		int u = read();
		int v = read();
		d[u] ++;
		d[v] ++;
		add_edge(u, v);
		add_edge(v, u);
	}
	memset(dis, -1, sizeof dis);
	dis[1] = 1;
	st[++ top] = 1;
	rep(i, 1, top)
		for(int u = st[i], j = head[u], v; j; j = nxt[j])
			if(!~dis[v = to[j]])
			{
				dis[v] = dis[u] + 1;
				pre[v] = u;
				st[++ top] = v;
			}
	if(~dis[n] && dis[n] <= 5)
	{
		printf("%d\n",dis[n] - 1);
		top = 0;
		for(int i = n; i != 1; i = pre[i])
			st[++ top] = i;
		st[++ top] = 1;
		rrep(i, top, 1)
			printf("%d ",st[i]);
		return 0;
	}
	p[1] = top;
	if(d[1] + 1 < p[1])
	{
		vis[1] = 1;
		for(int i = head[1]; i; i = nxt[i]) vis[to[i]] = 1;
		for(int i = head[1]; i; i = nxt[i])	
			for(int j = head[to[i]]; j; j = nxt[j])
				if(!vis[to[j]])
				{
					puts("4");
					printf("%d %d %d %d %d\n",1,to[i],to[j],1,n);
					return 0;
				}
	}
	else 
	{
		if(~dis[n] && dis[n] <= 6)
		{
			printf("%d\n",dis[n] - 1);
			top = 0;
			for(int i = n; i != 1; i = pre[i])
				st[++ top] = i;
			st[++ top] = 1;
			for(int i = top; i; i --)
				printf("%d ", st[i]);
			return 0;
		}
		vis[1] = 1;
		for(int i = head[1],v;i;i=nxt[i])
			if(!vis[v = to[i]])
			{
				siz = 0;
				dfs(v);
				rep(j, 1, siz)
					if(d[v = st[j]] < siz)
					{
						memset(vis, 0, sizeof vis);
						vis[v] = 1;
						for(int k = head[v]; k; k = nxt[k]) vis[to[k]] = 1;
						for(int k = head[v]; k; k = nxt[k])	
							for(int l = head[to[k]]; l; l = nxt[l])
								if(!vis[to[l]])
								{
									puts("5");
									printf("%d %d %d %d %d %d\n",1,v,to[k],to[l],v,n);
									return 0;
								}
					}
			}
	}
	puts("-1");
}