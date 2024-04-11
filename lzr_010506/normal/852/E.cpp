#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X headst
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
using namespace std;
const db pi = acos(-1.0);
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

const int N = 200010, mod = 1000000007;
int to[N], next[N], head[N] ,sz, dp[N] ,ans, n, deg[N];
int ni(int x, int times = mod - 2)
{
	int now = 1;
	while(times)
	{
		if(times & 1) now = (ll)now * x % mod;
		times >>= 1;
		x = (ll)x * x % mod;
	}
	return now;
}
void add(int x,int y)
{
	next[++ sz] = head[x];
	head[x] = sz;
	to[sz] = y;
	deg[x] ++;
}
void dfs(int x, int fa)
{
	bool flag = 0;
	dp[x] = 1;
	for(int u = head[x]; u; u = next[u])
	{
		if(to[u] != fa)
		{
			dfs(to[u], x);
			dp[x] = (ll)dp[x] * dp[to[u]] % mod;
		}
	}
	if(deg[x] != 1) dp[x] = dp[x] * 2 % mod;
}
void dfs(int x, int fa, int rt)
{
	int now = rt;
	for(int u = head[x]; u; u = next[u])
		if(to[u] != fa)
			now = (ll)now * dp[to[u]] % mod;
	ans=((ll)ans + now * 2) % mod;
	for(int u = head[x]; u; u = next[u])
		if(to[u] != fa)
			if(deg[x] != 1) dfs(to[u], x, (ll)now * ni(dp[to[u]]) % mod * 2 % mod);
			else dfs(to[u], x, (ll)now * ni(dp[to[u]]) % mod);
}
int main()
{
	n = read();
	if(n == 1) puts("1"), exit(0);
	rep(i, 1, n - 1)
	{
		int u = read();
		int v = read();
		add(u, v);
		add(v, u);
	}
	dfs(1, 0);
	dfs(1, 0, 1);
	cout << ans;
	return 0;
}