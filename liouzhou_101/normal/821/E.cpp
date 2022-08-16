#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MOD = 1000000007;
const int MAXN = 111;

ll a[MAXN], b[MAXN], c[MAXN];

int A[MAXN][MAXN], t[MAXN][MAXN], v[MAXN][MAXN];
int u[MAXN], uu[MAXN];

int mul(int x, int y)
{
	return (ll)x*y%MOD;
}

int add(int x, int y)
{
	x += y;
	if (x >= MOD) x -= MOD;
	return x;
}

void calc(ll n, ll d)
{
	if (!n)
	{
		for (int i = 0; i <= d; ++ i)
			for (int j = 0; j <= d; ++ j)
				v[i][j] = i == j;
		return;
	}
	calc(n/2, d);
	for (int i = 0; i <= d; ++ i)
		for (int j = 0; j <= d; ++ j)
		{
			t[i][j] = v[i][j];
			v[i][j] = 0;
		}
	for (int i = 0; i <= d; ++ i)
		for (int j = 0; j <= d; ++ j)
			for (int k = 0; k <= d; ++ k)
				v[i][j] = add(v[i][j], mul(t[i][k], t[k][j]));
	if (n&1)
	{
	for (int i = 0; i <= d; ++ i)
		for (int j = 0; j <= d; ++ j)
		{
			t[i][j] = v[i][j];
			v[i][j] = 0;
		}
	for (int i = 0; i <= d; ++ i)
		for (int j = 0; j <= d; ++ j)
			for (int k = 0; k <= d; ++ k)
				v[i][j] = add(v[i][j], mul(A[i][k], t[k][j]));
	}
}

int main()
{
	
	int n;
	ll k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i] >> b[i] >> c[i];
	b[n] = k;
	
	u[0] = 1;
	c[0] = 1;
	for (int i = 1; i <= n; ++ i)
	{
		for (int x = 0; x <= c[i]; ++ x)
			for (int y = 0; y <= c[i]; ++ y)
				A[x][y] = 0;
		for (int x = 0; x <= c[i]; ++ x)
			for (int d = -1; d <= 1; ++ d)
			{
				int y = x+d;
				if (!(0 <= y && y <= c[i])) continue;
				A[x][y] = 1;
			}
		calc(b[i]-a[i], c[i]);
		if (c[i] > c[i-1])
		{
			for (int x = c[i-1]+1; x <= c[i]; ++ x)
				u[x] = 0;
		}
		else if (c[i] < c[i-1])
		{
			for (int x = c[i]+1; x <= c[i-1]; ++ x)
				u[x] = 0;
		}
		for (int x = 0; x <= c[i]; ++ x)
		{
			uu[x] = u[x];
			u[x] = 0;
		}
		for (int x = 0; x <= c[i]; ++ x)
			for (int y = 0; y <= c[i]; ++ y)
				u[x] = add(u[x], mul(v[x][y], uu[y]));
	}
	
	cout << u[0] << endl;
	
	return 0;
}