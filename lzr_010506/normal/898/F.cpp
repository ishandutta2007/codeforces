#include <bits/stdc++.h>
#define rep(i,	x,	y) for(int i = x; i <= y; i ++)
#define ll unsigned long long
#define X first
#define Y second
#define ls rt << 1
#define rs rt << 1 | 1
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1000005;
const int K = 5;
const int MOD[] = {0, 19260817, 998244353, 1e9 + 7, 1e9 + 9, 1e6 + 3};

int n;
char s[N];
ll h[K + 2][N], p[K + 2][N], inv[K + 2][N];

ll bigMod (ll a, ll e, int mod)
{
	if (e == -1) e = mod - 2;
	ll ret = 1;
	while (e)
	{
		if (e & 1) ret = (ret * a) % mod;
		a = (a * a) % mod, e >>= 1;
	}
	return ret;
}

ll getHash (int i, int j, int k)
{
	ll one = h[k][i], two = MOD[k] - h[k][j + 1];
	ll ret = (one + two) * inv[k][n - j + 1] % MOD[k];
	return ret;
}

bool check (int i, int j)
{
	if (i <= 1 || j >= n || i > j) return 0;
	if (i - 1 > 1 && s[1] == '0') return 0;
	if (i < j && s[i] == '0') return 0;
	if (j + 1 < n && s[j + 1] == '0') return 0;
	rep(k, 1, K)
	{
		ll add = getHash(1, i - 1, k) + getHash(i, j, k);
		if (add >= MOD[k]) add -= MOD[k];
		if (add != getHash(j + 1, n, k)) return 0;
	}
	return 1;
}

void print (int i, int j)
{
	rep(k, 1, n)
	{
		if (k == i) putchar('+');
		putchar(s[k]);
		if (k == j) putchar('=');
	}
}

int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	rep(i, 1, K)
	{
		p[i][0] = 1, p[i][1] = 10;
		inv[i][0] = 1, inv[i][1] = bigMod(10, -1, MOD[i]);
	}
	rep(i, 1, n)
		rep(j, 1, K)
		{
			p[j][i] = p[j][i - 1] * p[j][1] % MOD[j];
			inv[j][i] = inv[j][i - 1] * inv[j][1] % MOD[j];
		}
	for (int i = n; i; --i)
	{
		int d = s[i] - '0';
		rep(j, 1, K)  h[j][i] = (h[j][i + 1] + d * p[j][n - i + 1]) % MOD[j];
	}
	if (s[1] == '0')
	{
		rep(i, 1, n)
			if (check(2, i))
			{
				print(2, i);
				return 0;
			}
		return 0;
	}
	rep(j, 1, n)
	{
		int len = n - j;
		for (int i = len - 3; i <= len + 3; i ++)
			if (check(i, j))
			{
				print(i, j);
				return 0;
			}
		for (int i = j - len + 1 - 3; i <= j - len + 1 + 3; ++i)
			if (check(i, j))
			{
				print(i, j);
				return 0;
			}
	}
	return 0;
}