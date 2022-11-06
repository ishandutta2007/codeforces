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
const int N = 405;
int jc[N], ny[N], q[N];
int a[N][N], n, mod;
int qpow(int x, int times)
{
	int res = 1;
    while(times)
    {
    	if(times & 1) res = 1LL * res * x % mod;
    	x = 1LL * x * x % mod;
    	times >>= 1;
    }
    return res;
}
int main()
{
	n = read();
	mod = read();
    jc[0] = 1;
    rep(i, 1, n) jc[i] = 1LL * jc[i - 1] * i % mod;
    rep(i, 0, n) ny[i] = qpow(jc[i], mod - 2);
    q[0] = 1;
    rep(i, 1, n) q[i] = q[i - 1] * 2LL % mod;
    a[0][0] = 1;
    rep(i, 1, n)
    	rep(j, 1, n + 1)
    		rep0(k, j - 1)
    			a[i][j] = (a[i][j] + 1LL * a[i - 1][k] * q[j - k - 2] % mod * ny[j - k - 1]) % mod;
    int ans = 0;
    rep(i, 1, n) ans = (ans + 1LL * a[i][n + 1] * jc[n + 1 - i]) % mod;
    printf("%d\n", ans);
    return 0;
}