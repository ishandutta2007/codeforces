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
#define sz(x) (x).size()
#define All(x) (x).begin(), (x).end()
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
#define int long long
const int N = 50010;
const int mod = 998244353;
int n, m;
int d[N][25];
void add(int &a, int b) {a += b; if (a >= mod) a -= mod;}
void dec(int &a, int b) {a -= b; if (a < 0) a += mod;}
int pow_mod(int a, int i)
{
	int s = 1;
	while (i)
	{
		if (i & 1) s = 1LL * s * a % mod;
		a = 1LL * a * a % mod;
		i >>= 1;
	}
	return s;
}
signed main()
{
	n = read();
	m = read();
	rep0(i, n)
		rep0(j, m)
			d[j][i] = read();
	rep0(i, m) sort(d[i], d[i] + n);
	int ans = m;
	int jc = 1;
	rep(i, 1, n) jc = 1LL * jc * i % mod;
	jc = pow_mod(jc, mod - 2);
	rep0(i, m)
	{
		int res = 1;
		rrep(j, n - 1, 0) res = 1LL * res * max(0LL, d[i][j] - (j + 1)) % mod;
		dec(ans, 1LL * res * jc % mod);
	}
	printf("%d\n", ans);
	return 0;
}