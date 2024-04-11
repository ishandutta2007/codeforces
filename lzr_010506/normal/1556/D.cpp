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


int n, k, lef, a[N], b[N], num[N];

int ask(int ty, int x, int y)
 {
    if (!ty) 
    {
        printf("and %d %d\n", x, y);
        fflush(stdout);
    }
    else 
    {
        printf("or %d %d\n", x, y);
        fflush(stdout);
    }

    int tmp; scanf("%d", &tmp);
    return tmp;
}

int main() 
{
    scanf("%d %d", &n, &k);
    rep(i, 2, n)
    {
        a[i] = ask(0, 1, i);
        b[i] = ask(1, 1, i);
    }
    lef = ask(0, 2, 3);


    int S = (1 << 30) - 1;
    rep(i, 2, n) S &= (b[i] - a[i]);

    num[1] = 0;
    rep(i, 2, n) num[1] |= a[i];

    ///

    lef = S - (lef & S); num[1] |= lef;
    rep(i, 2, n)
    {
        int tmp = (b[i] - a[i]) & num[1];
        tmp = (b[i] - a[i]) - tmp; num[i] = a[i] + tmp;
    }

    ///

    std::sort(num + 1, num + 1 + n);

    printf("finish %d\n", num[k]);
    fflush(stdout);

    return 0;
}