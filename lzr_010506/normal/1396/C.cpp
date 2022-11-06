#include <bits/stdc++.h>
#define pcc pair<char, char>
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define mp make_pair
#define pb push_back
//#define ls rt << 1
//#define rs rt << 1 | 1
#define F head
#define S second
#define X head
#define Y second
#define inf 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
#define ll long long
#define db double
#define trav(a, x) for(auto& a : x)
using namespace std;
namespace IO
{
const int sz = 1 << 15;
char inbuf[sz], outbuf[sz];
char *pinbuf = inbuf + sz;
char *poutbuf = outbuf;
inline char _getchar()
{
	if (pinbuf == inbuf + sz)fread(inbuf, 1, sz, stdin), pinbuf = inbuf;
	return *(pinbuf++);
}
inline void _putchar(char x)
{
	if (poutbuf == outbuf + sz)fwrite(outbuf, 1, sz, stdout), poutbuf = outbuf;
	*(poutbuf++) = x;
}
inline void flush()
{
	if (poutbuf != outbuf)fwrite(outbuf, 1, poutbuf - outbuf, stdout), poutbuf = outbuf;
}
}
//#define getchar IO::_getchar
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
#define mod1  1000000007ll
#define mod2  1000000009ll
using namespace std;
const int N = 2e6 + 10;
int a[N];
ll ans, w[N], f[N];

int main() 
{
    int n = read(); 
    int x = read(); 
    int y = read(); 
    int z = read(); 
    int d = read();
    rep(i, 1, n)
    {
        a[i] = read();
        w[i] = min(min(1ll * x * a[i] + z, 1ll * x * (a[i] + 2)), 0ll + x + y);
    }
    memset(f, 60, sizeof(f));
    f[0] = 0;
    rep(i, 1, n)
    {
        f[i] = f[i - 1] + 1ll * x * a[i] + z + d;
        if (i > 1) f[i] = min(f[i], f[i - 2] + w[i - 1] + w[i] + d * 4ll);
        if (i > 2) f[i] = min(f[i], f[i - 3] + w[i - 2] + w[i - 1] + w[i] + d * 7ll);
    }
    ans = min(f[n] - d, f[n - 2] + w[n - 1] + 1ll * x * a[n] + z + d * 2ll);
    if (n > 2) 
        ans = min(ans, f[n - 3] + w[n - 2] + w[n - 1] + 1ll * x * a[n] + z + d * 5ll);
    printf("%lld\n", ans);
    return 0;
}