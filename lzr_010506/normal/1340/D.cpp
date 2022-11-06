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
#define pll pair<ll, ll>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vll vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define All(x) (x).begin(), (x).end()
#define lowbit(x) ((x) & -(x))
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
const int N = 2e6 + 5, M = 1e3 + 5;
vector<int> G[N];
vector<pii> ans;
int n, mx, deg[N];

void dfs(int x, int fa, int st, int fi)
{
	ans.pb(mp(x, st));
	int Len = G[x].size() + 1, vl, vr;
	int son = x == 1 ? deg[x] : deg[x] - 1;
	if(fi + Len - 1 <= mx) vl = fi, vr = fi + Len - 1;
	else vl = mx - Len + 1, vr = mx;
	rep0(i, Len - 1)
	{
		int to = G[x][i];
		if(to == fa) continue;
		if(x > 1 && st == vr) ans.pb(mp(x, vl)), st = vl;
		dfs(to, x, st + 1, st);
		ans.pb(mp(x, ++ st));
		if(x > 1 && st == vr) ans.pb(mp(x, vl)), st = vl;
	}
	if(x > 1 && st == vr) ans.pb(mp(x, vl));
}

int main()
{
	n = read();
	if(n == 1)
	{
		puts("1");
		puts("1 0");
		return 0;
	}
	rep0(i, n - 1)
	{
		int u = read();
		int v = read();
		G[u].pb(v);
		G[v].pb(u);
		deg[u] ++;
		deg[v] ++;
	}
	mx = *max_element(deg + 1, deg + n + 1);
	dfs(1, 0, 0, mx);
	printf("%d\n", sz(ans));
	for(auto v : ans) printf("%d %d\n", v.X, v.Y);
	return 0;
}