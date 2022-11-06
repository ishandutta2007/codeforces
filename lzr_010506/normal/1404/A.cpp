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
#define db double
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
const int N = 3e5 + 10;
const int mod = 1e9 + 7; 
char ch[N];
int main()
{
	int T = read();
	while(T --)
	{
		int n = read();
		int m = read();
		scanf("%s", ch + 1);
		int c0 = 0, c1 = 0;
        bool ok = 1;
        rep(i, 1, m)
        {
            int u0 = 0, u1 = 0;
            for (int j = i; j <= n; j += m) u0 |= (ch[j] == '0'), u1 |= (ch[j] == '1');
            if (u0 && u1) 
            {
                ok = false;
                break;
            }
            if (ch[i] == '?') 
            {
                if (u0) ch[i] = '0';
                else if (u1) ch[i] = '1';
            }
        }
        rep(i, 1, m) c0 += ch[i] == '0', c1 += ch[i] == '1';
        if (c0 > m / 2 || c1 > m / 2) ok = 0;
        if (!ok) puts("NO");
        else  puts("YES");

	}

	return 0;
}