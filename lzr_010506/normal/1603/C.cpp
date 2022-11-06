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
#define sz(x) (int)(x).size()
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
const int N = 1e5 + 10;
const int mod = 998244353;
int n, m, a[N], vis[N];
struct Node
{
    int t, d, ed;
};
vector<Node> G, G1;
ll ans;
int main()
{
	int T = read();
	while(T --)
	{
		n = read();
		rep(i, 1, n) a[i] = read();
		G1.clear();
		ans = 0;
	    G1.pb(Node{1,a[n],n});
	    rrep(i, n - 1, 1)
	    {
		    G.pb(Node{1, a[i], i});
		    for(auto x : G1)
		    {
		        int t = (a[i] + x.d - 1) / x.d;
		        int d = a[i] / t;
		        if(d != G[sz(G) - 1].d || t != G[sz(G) - 1].t) G.pb(Node{t,d,x.ed});
		    }
		    G.pb(Node{0, 0, n + 1});
		    rep0(j, sz(G) - 1)
		    {
		        ans += 1LL * i * (G[j].t - 1) % mod * (G[j + 1].ed - G[j].ed) % mod;
		        ans %= mod;
		    }
		    G.pop_back();
		    G1 = G;
		    G.clear();
	    }
	    printf("%lld\n", ans);
	}
}
/*

*/