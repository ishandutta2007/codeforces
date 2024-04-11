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
#define pdd pair<double, double>
#define db double
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
using namespace std;

const int N = 20;
pdd p1[N], p2[N];
int n, m;
bool tag;
int p[N], vis[N];

bool ok(pdd a, pdd b, pdd c, pdd d)
{
    if(!(min(a.X , b.X) <= max(c.X, d.X) && min(c.Y, d.Y) <= max(a.Y, b.Y) && min(c.X, d.X) <= max(a.X, b.X) && min(a.Y, b.Y) <= max(c.Y, d.Y))) return 0;
    db u,v,w,z;
    u = (c.X - a.X) * (b.Y - a.Y) - (b.X - a.X) * (c.Y - a.Y);
    v = (d.X - a.X) * (b.Y - a.Y) - (b.X - a.X) * (d.Y - a.Y);
    w = (a.X - c.X) * (d.Y - c.Y) - (d.X - c.X) * (a.Y - c.Y);
    z = (b.X - c.X) * (d.Y - c.Y) - (d.X - c.X) * (b.Y - c.Y);
    return (u * v <= 0.00000001 && w * z <= 0.00000001);
}

void dfs(int now)
{
	bool flag;
	if (tag) return;
	if (now > n)
	{
		flag = 1;
		rep(i, 1, n)
			rep(j, i + 1, n)
				if (!ok(p1[i], p2[p[i]], p1[j], p2[p[j]])) return;
		tag = 1;
		return;
	}
	rep(i, 1, m)
		if (!vis[i])
		{
			p[now] = i;
			dfs(now + 1);
		}
}

int main()
{
	n = read();
	m = read();
	rep(i, 1, n) scanf("%lf%lf",&p1[i].X,&p1[i].Y);
	rep(i, 1, m) scanf("%lf%lf",&p2[i].X,&p2[i].Y);
	if (n != m)
	{
		puts("No");
		return 0;
	}
	tag = 0;
	dfs(1);
	if (tag) puts("Yes");
	else puts("No");
	return 0;
}