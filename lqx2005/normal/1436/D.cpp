#include<bits/stdc++.h>
#define int long long
#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define mpr make_pair
#define x(v) (v).first
#define y(v) (v).second
#define siz(v) (int)(v).size()
#define pb push_back
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef double db;
const int N = 2e5 + 10;
struct edge
{
	int to, nxt;
}e[N << 1];
int head[N], tot = 0;
int n, siz[N], cost[N], vis[N], a[N], dp[N];
void adde(int u, int v)
{
	e[++tot] = edge{v, head[u]};
	return head[u] = tot, void();
}
void dfs(int u)
{
	int flag = 0;
	siz[u] = cost[u] = 0;
	cost[u] = a[u];
	for(int i = head[u]; i; i = e[i].nxt)
	{
		int v = e[i].to;
		dfs(v);
		siz[u] += siz[v];
		cost[u] += cost[v];
		flag = 1;
	}
	siz[u] += flag ^ 1;
	if(!flag) vis[u] = 1;
	return;
}
void Dfs(int u)
{
	if(vis[u])
	{
		dp[u] = a[u];
		return;
	}
	int now = a[u], mx = 0;
	for(int i = head[u]; i; i = e[i].nxt)
	{
		int v = e[i].to;
		Dfs(v);
		mx = max(mx, dp[v]);
	}
	for(int i = head[u]; i; i = e[i].nxt)
	{
		int v = e[i].to;
		int all = mx * siz[v] - cost[v];
		all = min(all, now);
		now -= all;
	} 
	dp[u] = mx;
	if(now > 0)
	{
		now = (now + siz[u] - 1) / siz[u];
		dp[u] += now;
	}
	return;
}

signed main()
{
	scanf("%lld", &n);
	int p;
	for(int i = 2; i <= n; i++)
	{
		scanf("%lld", &p);
		adde(p, i);
	}
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	dfs(1);
	Dfs(1);
	printf("%lld\n", dp[1]);
	return 0;
}