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
#define pll pair<ll, ll>
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
#define All(x) (x).begin(), (x).end()
#define lowbit(x) ((x) & -(x))
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
const int N = 1e4 + 5, M = 1e3 + 5;

int n, m, kg, kr, a[N], f[N][M];
deque<pii> Q;
ll ans = 1e18;

int main() 
{
	n = read();
	m = read();
	rep(i, 1, m) a[i] = read();
    kg = read(); kr = read();
    sort(a + 1, a + m + 1);
    memset(f, 127, sizeof(f));
    f[1][0] = 0; 
    Q.push_back(mp(1, 0));
    while (!Q.empty()) 
    {
        pii now = Q.front(); 
        Q.pop_front();
        if (now.X == m) 
        {
            if (now.Y == 0) ans = min(ans, 1ll * f[now.X][now.Y] * (kg + kr) + now.Y - kr);
            else ans = min(ans, 1ll * f[now.X][now.Y] * (kg + kr) + now.Y);
            continue;
        }
        if (now.X < m) 
        {
            int d = a[now.X + 1] - a[now.X];
            if (now.Y + d > kg);
            else if (now.Y + d == kg) 
            {
                if (f[now.X + 1][0] > f[now.X][now.Y] + 1) f[now.X + 1][0] = f[now.X][now.Y] + 1, Q.push_back(mp(now.X + 1, 0));
                
            } 
            else 
            {
                if (f[now.X + 1][now.Y + d] > f[now.X][now.Y]) 
                {
                    f[now.X + 1][now.Y + d] = f[now.X][now.Y];
                    Q.push_front(mp(now.X + 1, now.Y + d));
                }
            }
        }
        if (now.X > 1) 
        {
            int d = a[now.X] - a[now.X - 1];
            if (now.Y + d > kg);
            else if (now.Y + d == kg) 
            {
                if (f[now.X - 1][0] > f[now.X][now.Y] + 1) 
                {
                    f[now.X - 1][0] = f[now.X][now.Y] + 1;
                    Q.pb(mp(now.X - 1, 0));
                }
            } 
            else if (f[now.X - 1][now.Y + d] > f[now.X][now.Y])  f[now.X - 1][now.Y + d] = f[now.X][now.Y], Q.push_front(mp(now.X - 1, now.Y + d));
            
        }
        
    }
    printf("%lld\n", ans > 1e12 ? -1ll : ans);
    return 0;
}