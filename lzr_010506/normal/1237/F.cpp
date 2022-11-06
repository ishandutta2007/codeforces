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
const ll mod = 998244353;
const int N = 4010;
ll jc[N + 10],ny[N + 10];
ll qp(ll x, ll p)
{
	ll ret = 1ll;
	while (p)
	{
		if (p & 1) ret = ret * x % mod;
		x = x * x % mod;
		p >>= 1;
	}
	return ret;
}
ll C(ll x, ll y) 
{
	return jc[x] * ny[y] % mod * ny[x - y] % mod;
}
ll A[N][N], B[N][N];
int va[N], vb[N];
ll f[N][N][2], tmp[N];
int main()
{
	jc[0] = 1;
	rep(i, 1, N) jc[i] = jc[i - 1] * i % mod;
	ny[N] = qp(jc[N], mod - 2);
	rrep(i, N - 1, 0) ny[i] = (ny[i + 1] * (i + 1)) % mod;
	int n = read(); 
	int m = read();
	int p = read();
	while(p --)
	{
		int x1 = read();
		int y1 = read();
		int x2 = read();
		int y2 = read();
		va[x1] = va[x2] = 1;
		vb[y1] = vb[y2] = 1;
	}
	int sa = 0, sb = 0;
	rep(i, 1, n) if (!va[i]) sa ++;
	f[0][0][0] = 1;
	rep(i, 1, n)
		rep0(j, i + 1)
			if (va[i]) (f[i][j][0] += f[i - 1][j][0]) %= mod;
			else
			{
				if (j && i != n && !va[i + 1]) (f[i][j][1] += f[i - 1][j - 1][0]) %= mod;
				(f[i][j][0] += f[i - 1][j][1]) %= mod;
				(f[i][j][0] += f[i - 1][j][0]) %= mod;
			}
	
	rep0(i, n + 1)
	{
		tmp[i] = f[n][i][0];
		if (tmp[i])
			for(int j = 0; i * 2 + j <= sa; j ++)
				A[i][j] = tmp[i] * C(sa - i * 2, j) % mod;
	}
	memset(f, 0, sizeof(f));
	rep(i, 1, m) if (!vb[i]) sb ++;
	f[0][0][0] = 1;
	rep(i, 1, m)
		rep(j, 0, i)
			if (vb[i]) (f[i][j][0] += f[i - 1][j][0]) %= mod;
			else
			{
				if (j && i != m && !vb[i + 1]) (f[i][j][1] += f[i - 1][j - 1][0]) %= mod;
				(f[i][j][0] += f[i - 1][j][1]) %= mod;
				(f[i][j][0] += f[i - 1][j][0]) %= mod;
			}
	rep(i, 0, m)
	{
		tmp[i] = f[m][i][0];
		if (tmp[i])
			for (int j = 0; i * 2 + j <= sb; j ++)
				B[i][j] = tmp[i] * C(sb - i * 2, j) % mod;
	}
	int Mx = max(n, m);
	ll ans = 0;
	rep(i, 0, Mx)
		rep(j, 0, Mx)
			if (A[i][j]&& B[j][i])
			{
				ans += 1ll * A[i][j] * B[j][i] % mod * jc[i] % mod * jc[j] % mod;
				ans %= mod;
			}
	printf("%lld\n", ans);
	return 0;
}