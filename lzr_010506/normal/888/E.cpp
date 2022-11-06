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
#define py pair<char, char>
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
const int N = 2e6 + 10;

vector<ll> a;
ll v[N];
 
int main()
{
	int n = read();
	int m = read();
	rep(i, 1, n) v[i] = read();
    ll rem = n / 2 + (n % 2);
    ll mid = n / 2;
    a.pb(0);
    rep0(mask, (1 << mid))
    {
        ll sum = 0;
        rep0(i, mid)
        	if( mask & (1 << i) ) 
                sum = (sum + v[rem + i + 1]) % m;
        a.pb(sum);
    }
    sort(ALL(a));
    ll ans = 0;
    rep0(mask, (1 << rem))
    {
        ll sum = 0;
        rep0(i, rem)
            if(mask & (1 << i))
                sum = (sum + v[i + 1]) % m;
        auto it = lower_bound(a.begin(), a.end(), m - sum);
        -- it;
        ans = max(ans, sum + (*it));
    }
    cout << ans;
    return 0;
}