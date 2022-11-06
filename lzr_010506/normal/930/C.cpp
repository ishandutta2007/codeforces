#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define ull unsigned long long
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
#define EPS 1e-8
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

int n, m;
int a[400010], t[400010], f[400010], g[400010]; 
inline int query(int x)
{
	x ++;
	int ans = 0;
	while(x)
	{
		ans = max(ans, t[x]);
		x -= x & -x;
	}
	return ans;
}
inline void add(int x, int f)
{
	x ++;
	while(x <= n)
	{
		t[x] = max(t[x], f);
		x += x & -x;
	}
}
int main()
{
	n = read();
	m = read();
	rep(i, 1, n)
	{
		int l = read();
		int r = read();
		a[l] ++;
		a[r + 1] --;
	}
	rep(i, 1, m) a[i] += a[i - 1];
	rep(i, 1, m)
	{
		f[i] = query(a[i]) + 1;
		add(a[i], f[i]);
	}
	memset(t, 0, sizeof(t));
	rrep(i, m, 1)
	{
		g[i] = query(a[i]) + 1;
		add(a[i], g[i]);
	}
	int ans = 0;
	rep(i, 1, m) ans = max(ans, f[i] + g[i + 1]);
	cout << ans;
	return 0;
}