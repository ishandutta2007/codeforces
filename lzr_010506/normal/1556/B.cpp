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
int a[N];
int main()
{
    int T = read();
    while(T --)
    {
        int n = read();
        vector<int> b;
        rep(i, 1, n)
        {
            a[i] = read();
            if(a[i] % 2 == 1) b.pb(i);
        }
        //cout << sz(b) << endl;
        if(min(sz(b), n - sz(b)) != n / 2) {puts("-1"); continue;}
        int j = 0;
        ll ans = 0, sum = 0;
        for(int i = 1; i <= n; i += 2)
            if(j < sz(b)) ans += abs(b[j ++] - i);
            else {ans = 1e18; break;}
        if(j < sz(b)) ans = 1e18;
        j = 0;
        for(int i = 2; i <= n; i += 2)
            if(j < sz(b)) sum += abs(b[j ++] - i);
            else {sum = 1e18; break;}
        if(j < sz(b)) sum = 1e18;
       // L1:;
        printf("%lld\n", min(sum, ans));
    }
    return 0;
}