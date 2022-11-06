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
#define ALL(x) (x).begin(), (x).end()
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
const int N = 1e5 + 10;
int a[N], b[N], n, m;
int main()
{
	int T = read();
	while(T --)
	{
		n = 0;
		m = 0;
		int nn = read();
		rep(i, 1, 2 * nn)
		{
			int x = read();
			int y = read();
			if(x == 0) a[++ n] = max(-y, y);
			else b[++ m] = max(-x, x);
		}
		sort(a + 1, a + n + 1);
		sort(b + 1, b + m + 1);
		double ans = 0.0;
		rep(i, 1, nn)
			ans += sqrt((double)a[i] * a[i] + (double)b[i] * b[i]);
		printf("%.12f\n", ans);
	}

	return 0;
}