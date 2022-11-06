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
#define sz(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
using namespace std;
static char ibuf[1 << 20]; char *fis = ibuf, *fit = ibuf;
inline char readChar() { return fis == fit && (fit = (fis = ibuf) + fread(ibuf, 1, 1 << 20, stdin), fis == fit) ? EOF : *fis++; }
inline int read() {
    char c, _c; int x; for (c = readChar(); !isdigit(c); c = readChar());
    for (x = 0; isdigit(c); c = readChar()) { x = x * 10 + c - '0'; } return x;
}
static char ostc[100], obuf[1 << 20]; int ol = 0; char *fos = obuf, *fot = obuf + (1 << 20) - 1;
inline void writeChar(char c) { *fos++ = c; if (fos == fot) { fwrite(obuf, 1, fos - obuf, stdout); fos = obuf; } }
inline void write(int n, char c) {
    if (!n) { writeChar('0'); } else { while (n) { ostc[++ol] = n % 10 + 48, n /= 10; } }
    for (; ol; ol--) { writeChar(ostc[ol]); } writeChar(c);
}
const int N = 1e5 + 10;
int n, q, a[N];
ll qw[N] , f[N][30] , g[N][30] ;
ll sum[N];
ll qmax(int x , int y)
{
    int l = y - x + 1 , j = qw[l] , p = y - (1 << j) + 1 ;
    return std::max(f[x][j] , f[p][j]) ;
}

ll qmin(int x , int y)
{
    int l = y - x + 1 , j = qw[l] , p = y - (1 << j) + 1 ;
    return std::min(g[x][j] , g[p][j]) ;
}
int main()
{
    n = read();
    q = read();
    rep(i, 1, n) a[i] = read();
    rep(i, 1, n)
    {
        a[i] -= read();
        sum[i] = sum[i - 1] + a[i];
    }

    qw[1] = 0 ;

    for (int i = 2 ; i <= n ; ++i) qw[i] = qw[i >> 1] + 1 ;

    for (int i = 1 ; i <= n ; ++i) f[i][0] = g[i][0] = sum[i] ;

    for (int j = 1 ; j <= qw[n] ; ++j)
        for (int i = 1 ; i <= n ; ++i)
        { 
            int p = i + (1 << (j - 1)) ;

            if (p > n) f[i][j] = f[i][j - 1] , g[i][j] = g[i][j - 1] ;
            else f[i][j] = std::max(f[i][j - 1] , f[p][j - 1]) , g[i][j] = std::min(g[i][j - 1] , g[p][j - 1]) ;
        }
    while(q --)
    {
        int l = read();
        int r = read();
        if(sum[r] - sum[l - 1]) {puts("-1"); continue;}
        if(qmax(l, r) - sum[l - 1] > 0) {puts("-1"); continue;}
        printf("%lld\n", -(qmin(l, r) - sum[l - 1]));
    }


    return 0;
}