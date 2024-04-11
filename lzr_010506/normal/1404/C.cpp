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
int n, q, b[N], ans[N];
vector<pii> qry[N];

int g[N], f[N], fi[N];

inline int lowbit(int x)
{
	return x & (-x);
}

inline void pushUp(int rt) 
{
    f[rt] = 1e9;
    if (f[rt] > f[rs]) 
        f[rt] = f[rs], fi[rt] = fi[rs];
	if (f[rt] > f[ls]) 
        f[rt] = f[ls], fi[rt] = fi[ls];
}
inline void pushTag(int rt, int x) 
{
    f[rt] += x; 
    g[rt] += x;
}
inline void pushDown(int rt) 
{
    if (g[rt] != 0) 
    {
        pushTag(ls, g[rt]); 
        pushTag(rs, g[rt]);
        g[rt] = 0;
    }
}

void modify(int rt, int l, int r, int p, int x)
 {
    if (l + 1 >= r) { f[rt] = x; fi[rt] = l; return; }
    int mid = l + r >> 1;
    pushDown(rt);
    if (p < mid) modify(ls, l, mid, p, x);
    else modify(rs, mid, r, p, x);
    pushUp(rt);
}
void modify(int rt, int l, int r, int pl, int pr, int x) 
{
    if (pl >= pr) { return; }
    if (l == pl && r == pr) { pushTag(rt, x); return; }
    int mid = l + r >> 1;
    pushDown(rt);
    if (pr <= mid)  modify(ls, l, mid, pl, pr, x);
    else if (pl >= mid)  modify(rs, mid, r, pl, pr, x);
    else 
	{
        modify(ls, l, mid, pl, mid, x);
        modify(rs, mid, r, mid, pr, x);
    }
    pushUp(rt);
}
struct FenwickTree 
{
    int f[N];
    void modify(int u, int x) 
	{
		int i = u;
		while(i <= n)
		{
			f[i] += x;
			i += lowbit(i);
		}
    }
    int query(int u) 
	{
        int res = 0;
        int i = u;
        while(i >= 1) res += f[i], i ^= lowbit(i);
        return res;
    }
} tr;

int main() 
{
    n = read(); q = read();
    rep0(i, n)
    {
        int x = read(); 
        b[i] = i - x + 1;
        modify(1, 0, n, i, 1e9);
    }
	rep0(i, q)
	{
        int l = read(), r = read();
        r = n - r;
        qry[l].pb(mp(r, i));
    }
    rrep(i, n - 1, 0)
	{
        if (b[i] >= 0) modify(1, 0, n, i, b[i]); 
        while (f[1] <= 0) 
		{
            int u = fi[1];
            modify(1, 0, n, u, 1e9);
            modify(1, 0, n, u, n, -1);
            tr.modify(u + 1, 1);
        }
        rep0(j, sz(qry[i]))
            ans[qry[i][j].Y] = tr.query(qry[i][j].X);
        
    }
    rep0(i, q) printf("%d\n", ans[i]);
    
    return 0;
}