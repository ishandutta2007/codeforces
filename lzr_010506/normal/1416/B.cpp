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
#define X fisrt
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
const int N = 1e5 + 5;

int n, sum, a[N];


int main() 
{
	int T = read();
	while(T --)
	{
        n = read(); 
        sum = 0;
        rep(i, 1, n) a[i] = read(), sum += a[i];
        if(sum % n != 0) {puts("-1"); continue;}
        printf("%d\n", 3 * n - 3);
       	rep(i, 2, n)
       	{
       		int x = a[i] % i ? i - a[i] % i : 0;
       		printf("1 %d %d\n", i, x);
       		a[1] -= x;
       		a[i] += x;
       		x = a[i] / i;
       		printf("%d 1 %d\n", i, x);
       		a[1] += x * i;
       		a[i] -= x * i;
       	}
       	rep(i, 2, n)
       	{
       		int x = sum / n;
       		printf("1 %d %d\n", i, x);
       		a[1] -= x;
       		a[i] += x;
       	}
    }
    return 0;
}