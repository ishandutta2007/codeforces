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
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define rrep(i, x, y) for (int i = x; i >= y; i--)
#define rep0(i, n) for (int i = 0; i < (n); i++)
#define per0(i, n) for (int i = (n)-1; i >= 0; i--)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define All(x) (x).begin(), (x).end()
#define int long long
#define vi vector<int>
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
const int N = 100010;
int n, c[N], sz[N], ans[N], son[N], sum, mx, cnt[N], S;
vi G[N];

void dfs(int x, int fa)
{
	sz[x] = 1;
	rep0(i, sz(G[x]))
	{
		int to = G[x][i];
		if(to == fa) continue;
		dfs(to, x);
		sz[x] += sz[to];
		if(sz[to] > sz[ son[x] ]) son[x] = to;
	}
}

void calc(int x, int fa, int val)
{
	cnt[c[x]] += val;
	if(cnt[c[x]] > mx) sum = c[x], mx = cnt[c[x]];
	else
	{
		if(cnt[c[x]] == mx) sum += c[x];
	}
	rep0(i, sz(G[x]))
	{
		int to = G[x][i];
		if(to == fa || to == S) continue;
		calc(to, x, val);
	}
}



void dfs1(int x, int fa, int t)
{
	rep0(i, sz(G[x]))
	{
		int to = G[x][i];
		if(to == fa) continue;
		if(to == son[x]) continue;
		dfs1(to, x, -1);
	}
	if(son[x]) dfs1(son[x], x, 1), S = son[x];
	calc(x, fa, 1);
	S = 0;
	ans[x] = sum;
	if(t == -1) calc(x, fa, -1), mx = sum = 0;
}

signed main()
{
	n = read();
	rep(i, 1, n) c[i] = read();
	rep0(i, n - 1)
	{
		int u, v;
		u = read();
		v = read();
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1, 0);
	dfs1(1, 0, 1);
	rep(i, 1, n) printf("%lld ", ans[i]);
	return 0;
}