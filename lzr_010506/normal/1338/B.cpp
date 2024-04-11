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
#define py pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define dep(i, x, y) for(int i = x; i >= y; i --)
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
const int N = 1e6 + 10;
vector<int> G[N];
int c[2], ans;
void dfs(int x, int fa, int d)
{
	if (sz(G[x]) == 1) c[d] = 1;
	int cnt = 0;
	for(auto to : G[x])
	{
		if(to == fa) continue;
		if (sz(G[to]) == 1) cnt++;
		dfs(to, x, d ^ 1);
	}
	if (cnt) ans -= cnt - 1;
}
int main()
{
	int n = read();
	rep0(i, n - 1)
	{
		int u = read();
		int v = read();
		G[u].pb(v);
		G[v].pb(u);
	}
	int rt;
	rep(i, 1, n)
		if (sz(G[i]) != 1) rt = i;
	ans = n - 1;
	dfs(rt, -1, 0);
	if(c[0] && c[1]) printf("3 ");
	else printf("1 ");
	printf("%d", ans);
	return 0;
}