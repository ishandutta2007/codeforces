#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define ull unsignto long long
#define db double
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
#define cntPS 1e-8
using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
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

const int N = 600005;
int n, m, cnt, head[N], to[N], next[N], v[N], fa[N], a[N], c[N], d[N], p[N], q[N];
ll s[N], f[N], g[N];

void ins(int u, int V, int w)
{
	to[++ cnt] = V;
	v[cnt] = w;
	next[cnt] = head[u];
	head[u] = cnt;
}

void insert(int u, int v, int w)
{
	ins(u, v, w);
	ins(v, u, w);
}
bool circle(int x)
{
	for (int p = head[x]; p; p = next[p])
	{
		int y = to[p];
		if (p != fa[x])
		{
			if (fa[y])
			{
				d[++ m] = v[p];
				for (int i = x; i != y; i = to[fa[i]])
					a[m] = i, d[++ m] = v[fa[i]];
				a[m] = y;
				return 1;
			}
			else fa[y] = p ^ 1;
			if (circle(y)) return 1;
		}
	}
	return 0;
}
void dp(int x)
{
	c[x] = 1;
	s[x] = 0;
	for (int p = head[x]; p; p = next[p])
	{
		int y = to[p];
		if (!fa[y]) 
		{
			fa[y] = x;
			dp(y);
			c[x] += c[y];
			s[x] += s[y] + c[y] * v[p];
		}
	}
}
void dfs(int x)
{
	for (int p = head[x]; p; p = next[p])
	{
		int y = to[p];
		if (fa[y] > 0 && fa[x] != y)
			s[y] = s[x] + (n - c[y] * 2) * v[p], dfs(y);
	}
}
int main()
{
	n = read();
	cnt = 1;
	rep(i, 1, n)
	{
		int x = read();
		int y = read();
		int z = read();
		insert(x, y, z);
	}
	fa[1] = -1;
	circle(1);
	rep(i, 1, n) fa[i] = 0;
	rep(i, 1, m) fa[a[i]] = -1;
	rep(i, 1, m)
	{
		a[m + m + i] = a[m + i] = a[i];
		d[m + m + i] = d[m + i] = d[i];
		dp(a[i]);
	}
	rrep(i, m * 3, 1)
	{
		q[i] = q[i + 1] + c[a[i]];
		g[i] = g[i + 1] + s[a[i]] + q[i + 1] * d[i + 1];
	}
	rep(i, 1, m * 3)
	{
		p[i] = p[i - 1] + c[a[i]];
		f[i] = f[i - 1] + s[a[i]] + p[i - 1] * d[i];
		d[i] += d[i - 1];
	}
	int w = 1;
	rep(i, m, m + m - 1)
	{
		while (d[i] - d[w] > d[w + m] - d[i]) w ++;
		int l = w - 1, r = w + m;
		s[a[i]] = f[i] - f[l] - 1ll * p[l] * (d[i] - d[l]) + g[i] - g[r] - 1ll * q[r] * (d[r] - d[i]) - s[a[i]];
	}
	rep(i, 1, m) dfs(a[i]);
	rep(i, 1, n) printf("%I64d ",s[i]);
	return 0;
}