#include <bits/stdc++.h>
#define rep(i,  x,  y) for(int i = x; i <= y; i ++)
#define rrep(i, x,  y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ls rt << 1
#define rs rt << 1 | 1
#define INF 0x3f3f3f3f
#define pll pair<ll, ll>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const ll mod = 1e9 + 7;
ll k, pa, pb;

const int maxk = 1111;

ll dp[1010][1010];
int vis[1010][1010];
ll Ta, Tb;

ll qpow(ll x, ll times)
{
    ll res = 1;
    while (times)
    {
        if (times & 1) res = res * x % mod;
        times >>= 1;
        x = x * x % mod;
    }
    return res;
}

ll ny(ll x)
{
    return qpow(x, mod - 2);
}

ll solve(ll x, ll d)
{
    if (d >= k) return 0;
    if (x >= k) return (x + Ta * ny(Tb) % mod) % mod;
    if (vis[x][d]) return dp[x][d];
    vis[x][d] = 1;
    if (!x && !d) dp[x][d] = solve(x + 1, d) % mod;
    else
    {
        dp[x][d] += Ta * solve(x + 1, d) % mod;
        dp[x][d] %= mod;
        dp[x][d] += Tb * (solve(x, d + x) + x) % mod;
        dp[x][d] %= mod;
    }
    return dp[x][d];
}

int main()
{
	cin >> k >> pa >> pb;
    Ta = pa * ny((pa + pb) % mod) % mod;
    Tb = pb * ny((pa + pb) % mod) % mod;
    ll ans = solve(0, 0);
    cout << ans << endl;
    return 0;
}