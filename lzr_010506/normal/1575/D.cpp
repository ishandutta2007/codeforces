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
    char c, _c; int x; for (c = readChar(); !isdigit(c); c = readChar());
    for (x = 0; isdigit(c); c = readChar()) { x = x * 10 + c - '0'; } return x;
}
static char ostc[100], obuf[1 << 20]; int ol = 0; char *fos = obuf, *fot = obuf + (1 << 20) - 1;
inline void writeChar(char c) { *fos++ = c; if (fos == fot) { fwrite(obuf, 1, fos - obuf, stdout); fos = obuf; } }
inline void write(int n, char c) {
    if (!n) { writeChar('0'); } else { while (n) { ostc[++ol] = n % 10 + 48, n /= 10; } }
    for (; ol; ol--) { writeChar(ostc[ol]); } writeChar(c);
}
const int N = 200010;
int n, ans;
string a;
void dfs(int x)
{
   // cout << x << " " << a << endl;
    if(x == n)
    {
        int p = 0;
        int b[9];
        bool flag = 0;
        rep0(j, n) if(a[j] == 'X') {flag = 1; break;}
        if(flag == 1)
        {
            rep(i, 0, 9)
            {
                rep0(j, n) 
                    if(a[j] != 'X') b[j] = a[j] - '0';
                    else b[j] = i;
                if(b[0] == 0 && n == 1) ans ++;
                if(b[0] == 0) continue;
                p = 0;
                rep0(j, n) p = p * 10 + b[j];
               // cout << p << endl;
                if(p % 25 == 0) ans ++;
            }
        }
        else
        {
            rep0(j, n) 
                if(a[j] != 'X') b[j] = a[j] - '0';
            if(b[0] == 0 && n == 1) ans ++;
            if(b[0] == 0) return;
            rep0(j, n) p = p * 10 + b[j];
          //  cout << p << endl;
            if(p % 25 == 0) ans ++;
        }
        return;
    }
    if(a[x] != '_') dfs(x + 1);
    else rep(i, 0, 9) a[x] = i + '0', dfs(x + 1), a[x] = '_';
}

int main()
{
    cin >> a;
    //if(a == "0") {cout << 1 << endl; return 0;}
    n = a.size();
    dfs(0);
    cout << ans << endl;
    return 0;
}