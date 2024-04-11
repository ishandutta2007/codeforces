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
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
using namespace std;
static char ibuf[1 << 20]; char *fis = ibuf, *fit = ibuf;
inline char readChar() { return fis == fit && (fit = (fis = ibuf) + fread(ibuf, 1, 1 << 20, stdin), fis == fit) ? EOF : *fis++; }
inline int read() {
    char c; int x; for (c = readChar(); !isdigit(c); c = readChar());
    for (x = 0; isdigit(c); c = readChar()) { x = x * 10 + c - '0'; } return x;
}
static char ostc[100], obuf[1 << 20]; int ol = 0; char *fos = obuf, *fot = obuf + (1 << 20) - 1;
inline void writeChar(char c) { *fos++ = c; if (fos == fot) { fwrite(obuf, 1, fos - obuf, stdout); fos = obuf; } }
inline void write(int n, char c) {
    if (!n) { writeChar('0'); } else { while (n) { ostc[++ol] = n % 10 + 48, n /= 10; } }
    for (; ol; ol--) { writeChar(ostc[ol]); } writeChar(c);
}
const int N = 4e6 + 10;
int st, n, m, a[N];
int flag;
vector<int> ans;

void getans(int x)
{
    ans.pb(x);
    reverse(a + 1, a + 1 + x);
}

void Do(int len)
{
    if(len == 1) return;
    int px, py, x = 0, y = 0;
    rep(i, 1, len)
    {
        if(a[i] > x) py = px, y = x, px = i, x = a[i];
        else if(a[i] > y) py = i, y = a[i];
    }
    if(px % 2 == 0 || py % 2)
    {
        flag = 0;
        return;
    }
    getans(px);
    rep(i, 1, len)
        if(a[i] == y)
        {
            py = i;
            break;
        }
    getans(py - 1);
    getans(py + 1);
    getans(3);
    getans(len);
    Do(len - 2);
}
int main()
{
    int T = read();
    while(T --)
    {
        ans.clear();
        flag = 1;
        int n = read();
        rep(i, 1, n) a[i] = read();
        Do(n);
        if(flag == 0) printf("-1\n");
        else    
        {
            printf("%d\n", (int)sz(ans));
            for(auto x : ans) printf("%d ", x);
            printf("\n");
        }
    }
    return 0;
}