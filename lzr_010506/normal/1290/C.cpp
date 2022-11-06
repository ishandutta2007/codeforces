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
const int N = 3e5 + 10;
int n, k;
vi q[N];
int f[N], val[N], sz[N][2], vis[N], ans;

int getval(int x)
{
	if (vis[x] == -1) return min(sz[x][0], sz[x][1]);
	else return sz[x][vis[x]];
}

int Find(int x)
{
	if (x == f[x]) return x;
	Find(f[x]);
	val[x] ^= val[f[x]];
	f[x] = f[f[x]];
	return f[x];
}

void merge(int u, int v, int c)
{
	Find(u);
	Find(v);
	if (f[u] != f[v])
	{
		ans -= getval(f[u]);
		ans -= getval(f[v]);
		c ^= val[u] ^ val[v]; 
		u = f[u]; 
		v = f[v];
		sz[u][0] += sz[v][c];
		sz[u][1] += sz[v][1 - c];
		if (vis[v] != -1 && vis[u] == -1) vis[u] = vis[v] ^ c;
		f[v] = u;
		val[v] = c;
		ans += getval(u);
	}
	
}

void sure(int u, int c)
{
	Find(u);
	ans -= getval(f[u]);
	c ^= val[u];
	u = f[u];
	if (vis[u] == -1) vis[u] = c;
	ans += getval(u);
}
char ch[N];
int main()
{
	n = read();
	k = read();
	scanf("%s", ch + 1);
	rep(i, 1, k)
	{
		int num = read();
		while (num --)
		{
			int x = read();
			q[x].pb(i);
		}
	}
	rep(i, 1, k) f[i] = i, sz[i][1] = 1, sz[i][0] = 0, vis[i] = -1;

	rep(i, 1, n)
	{
		if (q[i].size() == 2) merge(q[i][0], q[i][1], 1 - (ch[i] - '0'));
		else if(q[i].size() != 0) sure(q[i][0], 1 - (ch[i] - '0'));
		printf("%d\n", ans);
	}
	return 0;
}