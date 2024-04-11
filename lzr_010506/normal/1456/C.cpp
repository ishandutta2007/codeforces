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
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 1e6 + 10;

int n, m;
ll ss, _s, ans, now, f[N], g[N];
vector<ll> a, b;
inline long long getb(int t, long long c) 
{
    return f[t] + g[t] * (c - t);
}


int main() 
{
    n = read(); 
    m = read();
    rep(i, 1, n)
    {
        int x = read();
        if (x >= 0) a.pb(x);
        else b.pb(x);
    }
    sort(ALL(a));
    rep0(i, sz(a))
        ss += 1ll * i * a[i], _s += a[i];
    sort(ALL(b));
    rrep(i, sz(b) - 1, 0)
    {
        f[i] = f[i + 1] + 1ll * i * b[i];
        g[i] = g[i + 1] + b[i];
    }
   // rep0(i, sz(b)) printf("%d %d\n", f[i], g[i]);
   // cout << 1ll * sz(b) * _s << " " << ss << " " << f[0] << " " << f[0] + ss + 1ll * sz(b) * _s << endl;
    ans = f[0] + ss + 1ll * sz(b) * _s;
   // cout << ans << endl; 	
   	ll c = 0;
    for (int i = 0, j; i < sz(b); i = j)
    {
        j = min(i + m + 1, sz(b));
        ll tmp = now;
        rep(k, i, j - 1)
        {
            tmp += 1LL * b[k] * c;
            ans = max(ans, tmp + f[k + 1] + 1LL* g[k + 1] * (c - k) + (ss + (c + (sz(b) - k)) * _s));
            now += 1LL * b[k] * c;
        }
        c ++;
    }
    ans = max(ans, now + ss + 1LL * c * _s);
    printf("%lld\n", ans);
    return 0;
}