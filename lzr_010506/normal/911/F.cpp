#include <bits/stdc++.h>
#define rep(i,  x,  y) for(int i = x; i <= y; i ++)
#define rrep(i, x,  y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ls rt << 1
#define rs rt << 1 | 1
#define INF 0x3f3f3f3f
#define pll pair<ll, ll>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

vector<int> G[200010];
struct P
{
	int x, y;
};
vector<P>aa;
int n,mx,z,rt,fa[200010],dep[200010],in[200010];
ll ans;

void dfs(int x, int fff)
{
	dep[x] = dep[fa[x] = fff] + 1;
	if (dep[x] > mx) mx = dep[x], z = x;
	for (auto y : G[x]) 
		if (y - fff) 
			dfs(y, x);
}

void D(int x, int dis, int fr, int fl = 0)
{
	in[x] = 1;
	for (auto y : G[x]) 
		if (!in[y]) 
			D(y, dis + 1, fr, 1);
	if (fl) ans += dis, aa.pb(P{fr, x});
}

int main()
{
	n = read();
	rep(i, 1, n - 1)
	{
		int x, y;
		x = read();
		y = read();
		G[x].pb(y);
		G[y].pb(x);
	}
	
	mx = 0; 
	dfs(1, 0);
	mx = 0; 
	rt = z; 
	dfs(rt, 0);
	ans = (ll)mx * (mx - 1) / 2;
	for (int t = z; t; t = fa[t]) in[t] = 1;
	for (int t = z; t; t = fa[t])
	{
		if (dep[t] - 1 > dep[z] - dep[t]) D(t, dep[t] - 1, rt);
		else D(t, dep[z] - dep[t], z);
	}
	cout << ans << endl;
	for (int i = 0; i < aa.size(); i ++) 
		printf("%d %d %d\n",aa[i].x,aa[i].y,aa[i].y);
	for (int t = z; t - rt; t = fa[t]) 
		printf("%d %d %d\n",rt,t,t);
	return 0;
}