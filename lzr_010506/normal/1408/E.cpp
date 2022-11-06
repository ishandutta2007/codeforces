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
const int N = 1e6 + 10;
int a[N],b[N], num, f[N];
pair<int, pii >p[N];
int find(int x)
{
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}
int main()
{
	int n = read();
	int m = read();
	rep(i, 1, n) a[i] = read();
	rep(i, 1, m) b[i] = read();
	rep(i, 1, n + m) f[i] = i;
	rep(i, 1, n)
	{
		int ss = read();
		while(ss --)
		{
			int x = read();
			p[++ num] = mp(a[i] + b[x], mp(i, x + n));
		}
	}
	sort(p + 1, p + num + 1);
	ll ans = 0;
	rrep(i, num, 0)
	{
		int d = p[i].X, x = p[i].Y.X, y = p[i].Y.Y;
		int u = find(x);
		int v = find(y);
		if(u == v)
		{
			ans += d;
			continue;
		}
		f[f[x]] = f[y];
	}
	printf("%I64d\n", ans);
    return 0;
}