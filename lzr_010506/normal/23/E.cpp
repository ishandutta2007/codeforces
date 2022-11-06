#include <bits/stdc++.h>
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
#define all(x) (x).begin(), (x).end()
#define cmax(u,v) (u)<(v)?(u)=(v):0;
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
struct Bign
{
	int a[110], tot;
	Bign(int x = 0)
	{
		memset(a, 0, sizeof(a));
		tot = 1;
		a[0] = x;
	}

	Bign operator * (const Bign &b) const
	{
		Bign c;
		c.tot = tot + b.tot - 1;
		rep(i, 0, tot - 1)
			rep(j, 0, b.tot - 1)
				c.a[i + j] += a[i] * b.a[j];
		rep(i, 0, c.tot - 1)
			c.a[i + 1] += c.a[i] / 10000, c.a[i] %= 10000;
		while(c.a[c.tot]) c.tot ++;
		return c;
	}

	Bign operator + (const Bign &b) const
	{
		Bign c;
		c.tot = max(tot, b.tot);
		rep(i, 0, c.tot - 1)
			c.a[i] = a[i] + b.a[i], c.a[i + 1] += c.a[i] / 10000, c.a[i] %= 10000;
		while(c.a[c.tot]) c.tot ++;
		return c;
	}

	friend bool operator < (Bign a, Bign b)
	{
		if(a.tot != b.tot) return a.tot < b.tot;
		rrep(i, a.tot - 1, 0)
			if(a.a[i] != b.a[i]) return a.a[i] < b.a[i];
		return 0;
	}

	void print()
	{
		printf("%d", a[tot - 1]);
		rrep(i, tot - 2, 0)
			printf("%04d", a[i]);
	}
}f[710][710];
const int N = 710;
int n, head[N], ecnt = 1, sz[N];
struct edge
{
	int next, to;
}e[10010];

void insert(int u, int v)
{
	e[++ ecnt].to = v;
	e[ecnt].next = head[u];
	head[u] = ecnt;
}

void dp(int x, int fa)
{
	sz[x] = 1;
	f[x][1] = Bign(1);
	for(int k = head[x]; k; k = e[k].next)
	{
		int y = e[k].to;
		if(y == fa)continue;
		dp(y, x);
		rrep(i, sz[x], 1)
			rrep(j, sz[y], 0)
				cmax(f[x][i + j], f[x][i] * f[y][j]);
		sz[x] += sz[y];
	}
	rep(i, 1, sz[x])
		cmax(f[x][0], f[x][i] * Bign(i));
}

int main()
{
	n = read();
	rep(i, 1, n - 1)
	{
		int x, y;
		x = read();
		y = read();
		insert(x, y);
		insert(y, x);
	}
	dp(1, 0);
	f[1][0].print();
	return 0;
}