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
#define ls rt << 1
#define rs rt << 1 | 1
#define F first
#define S second
#define X first
#define Y second
#define eps 1e-9
#define inf 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
#define ll long long
#define db double
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
template<typename T> inline T qmin(const T a,const T b) {return a < b ? a : b;}
template<typename T> inline T qmax(const T a,const T b) {return a > b ? a : b;}
template<typename T> inline void getmin(T &a,const T b) {if(a > b) a = b;}
template<typename T> inline void getmax(T &a,const T b) {if(a < b) a = b;}
const ll linf = 1e17 + 7;
const int N = 30;

int n;
ll a[N][N];
ll b[N][N];
char c[N];
void init()
{
	rep(i, 1, N - 1) a[2][i] = 1;
	rep(i, 1, N - 1) a[i][1] = (1 << (i - 2));
	a[1][1] = 0;
	rep(i, 3, N - 1)
		rep(j, 2, N - 1)
			a[i][j] = a[i - 1][j] + a[i][j - 1];
}
ll get(int x,int y)
{
	if (y == 1) return 1ll << 62;
	ll sum = 0;
	y --; 
	while (x != 1) sum += a[x --][y];
	return sum;
}
void mian()
{
	int n;
	scanf("%d", &n);
	rep(i, 1, n)
	{
		rep(j, 1, n)
			printf("%lld ", a[i][j]);
		puts("");
	}
	fflush(stdout);
	rep(i, 1, n)
		rep(j, 1, n)
			b[i][j] = min(b[i - 1][j], b[i][j - 1]) + a[i][j];
	int q;
	scanf("%d", &q);
	vector<pii> ans;
	while(q --)
	{
		ans.clear();
		ll x;
		scanf("%lld", &x);
		int u = n, v = n;
		while (u != 1 || v != 1)
		{
			x -= a[u][v];
			ans.pb(mp(u, v));
			if (get(u, v) > x) u --;
			else v --;
		}
		ans.pb(mp(1, 1));
		reverse(ALL(ans));
		for(auto A : ans) printf("%d %d\n", A.X, A.Y);
		//puts("");
		fflush(stdout);
	}

}
int main()
{
	init();
	/*rep(i, 1, N - 1)
	{
		rep(j, 1, N - 1)
			printf("%lld ", a[i][j]);
		puts("");
	}*/
	//int T = read();
	int T = 1;
	while(T --)
	{
		mian();
	}

	return 0;
}