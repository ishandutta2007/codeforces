#include <bits/stdc++.h>
#define N 200005
#define int long long
using namespace std;

template <typename T>

void read(T &a)
{
	T x = 0,f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	a = x * f;
}

template <typename T,typename... Args> void read(T &t,Args &... args) {read(t); read(args...); }

int n,m,d,fa[N];
bool vis[N],viss[N];
std::vector<int> e[N],ans;
std::vector<pair<int,int> > res;

int find(int x)
{
	int u = x;
	while (u != fa[u])
	{
		u = fa[u] = fa[fa[u]];
	}
	return u;
}

void dfs(int u)
{
	int xx = find(u);
	for (int i = 0; i < e[u].size(); i++)
	{
		int v = e[u][i];
		if (v == 1) continue;
		int yy = find(v);
		if (xx == yy) continue;
		fa[yy] = xx;
		dfs(v);
	}
}

void dfs2(int u)
{
	for (int i = 0; i < e[u].size(); i++)
	{
		// cout << u << ' ' << e[u][i] << endl;
		int v = e[u][i];
		if (vis[v]) continue;
		vis[v] = 1;
		res.push_back(make_pair(u,v));
		dfs2(v);
	}
}

signed main()
{
	read(n,m,d);
	for (int i = 1; i <= m; i++)
	{
		int u,v;
		read(u,v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 0; i < e[1].size(); i++)
	{
		if (fa[e[1][i]] == e[1][i]) dfs(e[1][i]);
	}
	int cnt = 0;
	vis[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (fa[i] == i)
		{
			cnt++;
			vis[i] = 1;
			viss[i] = 1;
			res.push_back(make_pair(1,i));
		}
	}
	// cout <<fa[2] << ' ' << fa[3] << endl;
	if (cnt > d || e[1].size() < d) return puts("NO") * 0;
	for (int i = 0; i < e[1].size(); i++)
	{
		if (cnt == d) break;
		if (viss[e[1][i]]) continue;
		vis[e[1][i]] = 1;
		viss[e[1][i]] = 1;
		res.push_back(make_pair(1,e[1][i]));
		cnt++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (viss[i]) dfs2(i);
	}
	puts("YES");
	for (int i = 0; i < res.size(); i++)
	{
		printf("%lld %lld\n",res[i].first,res[i].second);
	}
	return 0;
}