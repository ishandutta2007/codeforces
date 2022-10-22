#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 2e6 + 10;
int n;
int san[N], tot = 0;
vector<int> g[N];
int fa[N], siz[N], cal[N], vis[N], flag = 0;
int a[N], b[N];
vector<int> gro;
int find(int x)
{
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
	x = find(x), y = find(y);
	if(x == y) return;
	fa[x] = y;
	siz[y] += siz[x];
	siz[x] = 0;
	return;
}
void addedge(int u, int v)
{
	g[u].push_back(v);
	return;
}
void init()
{
	for(int i = 1; i <= n; i++) san[++tot] = a[i], san[++tot] = b[i];
	sort(san + 1, san + tot + 1);
	tot = unique(san + 1, san + tot + 1) - (san + 1);
	for(int i = 1; i <= tot; i++) fa[i] = i, siz[i] = 1;
	for(int i = 1; i <= n; i++) 
	{
		a[i] = lower_bound(san + 1, san + tot + 1, a[i]) - san;
		b[i] = lower_bound(san + 1, san + tot + 1, b[i]) - san;
		addedge(a[i], b[i]);
		addedge(b[i], a[i]);
		merge(a[i], b[i]);
	}
	return;
}
void dfs(int u, int fa)
{
	gro.push_back(u);
	vis[u] = 1;
	for(int i = 0; i < (int)g[u].size(); i++)
	{
		int v = g[u][i];
		if(v == fa) continue;
		if(vis[v]) 
		{
			flag = 1;
			return;
		}
		else dfs(v, u);
	}
	return;
}
int cmp(int a, int b)
{
	return san[a] < san[b];
}
int solve(int root)
{
	flag = 0;
	gro.clear();
	dfs(root, 0);
	sort(gro.begin(), gro.end(), cmp);
	int siz = (int)gro.size();
	return san[gro[siz - 1 - (flag ^ 1)]];
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
	init();
	int mx = 0;
	for(int i = 1; i <= n; i++) cal[find(a[i])]++;
	for(int i = 1; i <= tot; i++) if(fa[i] == i && siz[i] < cal[i]) return printf("-1\n"), 0;
	for(int i = 1; i <= tot; i++) if(fa[i] == i) mx = max(mx, solve(i));
	printf("%d\n", mx);
	return 0;
}