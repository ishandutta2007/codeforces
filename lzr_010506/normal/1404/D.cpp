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
#define F fisrt
#define S second
#define X first
#define Y second
#define inf 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
#define ll long long
//#define rep(i, a, b) for(int i = a; i < (b); ++i)
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
#define getchar IO::_getchar
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
const int N = 2e6 + 10;
const int mod = 1e9 + 7; 
int n, a[N], vis[N], nxt[N], ans[N], sum;
void dfs(int x)
{
	if(vis[x]) return;
	ans[x] = 1; 
	sum = (sum + x) % (2 * n);
	vis[x] = vis[nxt[x]] = 1;
	dfs((nxt[x] + n - 1) % (2 * n) + 1);
}
int main()
{
	scanf("%d", &n);
	if(!(n & 1))
	{
		puts("first");
		fflush(stdout);
		rep(i, 1, 2 * n) printf("%d ", (i - 1) % n + 1);
		puts("");
		fflush(stdout);
		scanf("%d", &n);
		return 0;
	}
	puts("second"); 
	fflush(stdout);
	rep(i, 1, 2 * n) scanf("%d", &a[i]);
	rep(i, 1, 2 * n)
	{
		if(vis[a[i]]) nxt[vis[a[i]]] = i, nxt[i] = vis[a[i]], vis[a[i]] = 0;
		else vis[a[i]] = i;
	}
	rep(i, 1, 2 * n) if(!vis[i]) dfs(i);
	if(sum == n)
	{
		rep(i, 1, 2 * n) if(!ans[i]) printf("%d ", i);
	}
	else
	{
		rep(i, 1, 2 * n) if(ans[i]) printf("%d ", i);
	}
	printf("\n"); fflush(stdout);
	scanf("%d", &n);
    return 0;
}