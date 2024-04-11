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
const int N = 1 << 20;
const int mod = 998244353;
int jc[N + 1], ny[N + 1], s[N + 1];
int C(int n, int m)
{
    if(n < m) return 0;
    return 1LL * jc[n] * ny[m] % mod * ny[n - m] % mod;
}

int qpow(int x, int times)
{
    int res = 1;
    while(times)
    {
        if(times & 1) res = 1LL * res * x % mod;
        times >>= 1;
        x = 1LL * x * x % mod;
    }
    return res;
}

inline int lowbit(int x)
{
    return x & (-x);
}

void add(int pos, int x)
{
    while(pos <= N)
    {
        s[pos] += x;
        pos += lowbit(pos);
    }
}

int x[N], y[N];
int main()
{
    jc[0] = 1; ny[0] = 1;
    rep(i, 1, N) jc[i] = 1LL * jc[i - 1] * i % mod;
    rep(i, 1, N) ny[i] = qpow(jc[i], mod - 2);

    int T = read();
    while(T --)
    {
        int n = read();
        int m = read();
        set<int> st;
        vector<int> w;
        rep(i, 1, m)
        {
            x[i] = read();
            y[i] = read();
        }
        int k = n - 1;
        rrep(i, m, 1)
        {
            int p = y[i];
            int L = 0, R = N;
            while(L + 1 < R)
            {
                int mid = L + R >> 1;
                if(mid - L - s[mid] < p)
                {
                    p -= mid - L - s[mid];
                    L = mid;
                }
                else R = mid;
            }
            int ans = L + 1;
            add(ans, 1);
            w.pb(ans);
            if(ans < n && !st.count(ans + 1)) k --;
            st.insert(ans);
        }
        //cout << k  << endl;
        printf("%d\n", C(n + k, n));
        for(int x : w) add(x, -1);
    }

    return 0;
}