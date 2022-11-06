#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb pb
#define mp make_pair
#define pii pair<ll, ll>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
using namespace std;
const int P = 1e9 + 7;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

inline int dec(int a, int b)
{
	a -= b;
	return a < 0 ? a + P : a;
}
inline int mul(int a, int b)
{
	return int((ll)(a) * b % P);
}
inline int qpow(int a, int b, int ans = 1)
{
	while (b)
	{
		if (b & 1) ans = mul(ans, a);
		a = mul(a, a);
		b >>= 1;
	}
	return ans;
}
inline int did(int a, int b)
{
	return mul(a, qpow(b, P - 2));
}

bool mt[110][110];
int tp[110][110], rt[110][110];
int TreeCount(int n, int a[110][110])
{
	rep(i, 1, n)
	{
		int p = i;
		while (a[p][i] == 0) p ++;
		if (p != i) swap(a[i], a[p]);
		int inv = did(1, a[i][i]);
		rep(j, i + 1, n)
		{
			int tmp = mul(a[j][i], inv);
			rep(k, i, n)
				a[j][k] = dec(a[j][k], mul(tmp, a[i][k]));
		}
	}
	int ans = 1;
	rep(i, 1, n)
		ans = mul(ans, a[i][i]);
	return ans;
}

int ans[110];
int main()
{
	int n = read();
	rep(i, 1, n - 1)
	{
		int x = read();
		int y = read();
		mt[x][y] = mt[y][x] = 1;
	}
	int now = 1, div2 = did(1, 2);
	rep(i, 1, n)
	{
		rt[i][1] = 1;
		rep(j, 2, n)
			rt[i][j] = mul(rt[i][j - 1], now);
		rep(j, 1, n)
		{
			tp[j][j] = 0;
			rep(k, 1, n)
				if (j != k)
				{
					if (mt[j][k] == 0) tp[j][k] = 1, tp[j][j] = dec(tp[j][j], 1);
					else tp[j][k] = now, tp[j][j] = dec(tp[j][j], now);
				}
		}
		rt[i][n + 1] = TreeCount(n - 1, tp);
		now = mul(now, div2);
	}
	rep(i, 1, n)
	{
		int p = i;
		while (rt[p][i] == 0) p ++;
		if (p != i) swap(rt[p], rt[i]);
		int inv = did(1, rt[i][i]);
		rep(j, 1, n)
			if (j != i)
			{
				int tmp = mul(rt[j][i], inv);
				rep(k, i, n + 1)
					rt[j][k] = dec(rt[j][k], mul(tmp, rt[i][k]));
			}
	}
	rep(i, 1, n)
		ans[i] = did(rt[i][n + 1], rt[i][i]);
	if (ans[n] != 1)
		rep(i, 1, n)
			ans[i] = dec(0, ans[i]);
	rep(i, 1, n)
		printf("%d ", ans[i]);
	return 0;
}