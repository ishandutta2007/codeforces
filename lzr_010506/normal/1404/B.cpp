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
const int N = 2e5 + 10;
const int mod = 1e9 + 7; 
int n, a, b, da, db;
int dep[N];
vector<int> G[N];
void dfs(int u, int fa)
{
	dep[u] = dep[fa] + 1;
	for(auto v : G[u])
	{
		if(v == fa) continue;
		dfs(v, u);
	}
}
int main()
{
	int T = read();
	while(T --)
	{
		n = read();
		a = read();
		b = read();
		da = read();
		db = read();
		rep(i, 1, n) G[i].clear();
		rep(i, 1, n - 1)
		{
			int u = read();
			int v = read();
			G[u].pb(v);
			G[v].pb(u);
		}
		dep[0] = -1;
		dfs(a, 0);
		int x = 0, mx = 0;
		bool flag = 1;
		//cout << dep[b] << " "; 
		if(dep[b] <= da) flag = 0;
		rep(i, 1, n)
		{
			if(dep[i] > mx) mx = dep[i], x = i;
			dep[i] = 0;
		}
		dfs(x, 0);
		x = 0, mx = 0;
		rep(i, 1, n)
			if(dep[i] > mx) mx = dep[i], x = i;
		//cout << mx << " ";
		
		if(db > 2 * da && mx > 2 * da && flag == 1) puts("Bob");
		else puts("Alice");
	}

	return 0;
}