#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
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
#define eps 1e-9
using namespace std;
const db pi = acos(-1.0);
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
struct point
{
    int x, y;
}p[2010];

bool cmp(point p1, point p2)
{
    return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

int H, W, n;
ll dp[2010], ny[200010], jc[200010];

ll qpow(ll x, int times)
{
    ll ret = 1;
    while(times)
    {
        if(times & 1) ret = ret * x % mod;
        times >>= 1;
        x = x * x % mod;
    }
    return ret;
}

ll C(ll n, int m)
{
    if(n < m) return 1;
    return (jc[n] * ny[m] % mod * ny[n - m] % mod);
}

int main()
{
    jc[0] = 1;
    ny[0] = 1;
    rep(i, 1, 200009)
    {
    	jc[i] = jc[i - 1] * i % mod;
    	ny[i] = qpow(jc[i], mod - 2) % mod;
    }
    H = read();
    W = read();
    n = read();
    rep(i, 1, n)
    	p[i].x = read(), p[i].y = read();
    p[0].x = p[0].y = 1;
    p[n + 1].x = H, p[n + 1].y = W;
    sort(p, p + n + 2, cmp);
    dp[0] = 1ll;
    rep(i, 1, n + 1)
    {
        dp[i] = C(p[i].x - p[0].x + p[i].y - p[0].y, p[i].x - p[0].x) % mod;
        rep(j, 1, i - 1)
            if(p[j].y <= p[i].y)
                dp[i] = (dp[i] - dp[j] * C(p[i].x - p[j].x + p[i].y - p[j].y, p[i].x - p[j].x) % mod + mod) % mod;
    }
    cout << dp[n + 1];
    return 0;
}
//dp[i] = C(xi - 1 + yi - 1, xi - 1) - sigma(dp[j] * C(xi - xj + yi - yj, xi - xj))