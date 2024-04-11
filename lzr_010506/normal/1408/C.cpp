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
int n, l, a[N];
int main()
{
	int T = read();
	while (T --)
	{
		int n = read();
		int l = read();
		int x = 1, y = 1, X = 0, Y = n + 1;
		double tx = 0, ty = 0;
		a[n + 1] = l;
		rep(i, 1, n) a[i] = read();
		rep(i, 1, n)
		{
			if (tx + (a[X + 1] - a[X]) * 1.0 / (x * 1.0) < ty + (a[Y] - a[Y - 1]) * 1.0 / (y * 1.0)) 
				tx += (a[X + 1] - a[X]) * 1.0 / (x * 1.0), ++X, ++x;
			else ty += (a[Y] - a[Y - 1]) * 1.0 / (y * 1.0), --Y, ++y;
		}
		if (tx > ty)printf("%.10lf\n", tx + (a[Y] - a[X] - (tx - ty) * y) / (x * 1.0 + y));
		else printf("%.10lf\n", ty + (a[Y] - a[X] - (ty - tx) * x) / (x * 1.0 + y));
	}

	return 0;
}