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
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), py(n), pm(n);
    vector<char> op(n);
    rep0(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    string s;
    cin >> s;
    rep0(i, n)
    {
        if(s[i] != s[i - 1] || i == 0) pm[i] = i, op[i] = s[i];
        else 
        {
            py[i - 1] = 1;
            pm[i] = 0;
            if(i & 1) op[i] = s[i] == 'L' ? 'R' : 'L';
            else op[i] = s[i];

        }
        //cout << op[i] << endl;
    }

    rrep(i, n - 2, 0) py[i] += py[i + 1];
    //rep(i, 1, n) printf("%d\n", py[i]);
    rep0(i, n) cout << a[py[i] + pm[i]] << " " << op[i] << endl;
    return 0;
}