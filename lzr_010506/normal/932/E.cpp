#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
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

const int mod = 1e9 + 7;
int qpow(int x ,int y)
{
	int res = 1;
	while (y)
	{
		if (y & 1) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod;y>>=1;
	}
	return res;
}
int s[5010][5010];
int main()
{
	int n = read();
	int k = read();
	s[0][0] = 1;

	rep(i, 1, k)
		rep(j, 1, i)
			s[i][j] = (1ll * s[i - 1][j] * j + s[i - 1][j - 1]) % mod;
	ll ans = 0, jc = 1;
	rep(i, 1, min(n, k))
	{
		jc = 1ll * jc * (n + 1 - i) % mod;
		ans = (ans + 1ll * s[k][i] * qpow(2, n - i) % mod * jc) % mod;
	}
	cout << ans;
	return 0;
}