#include <bits/stdc++.h>
#include <ctime>
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
#define sz(x) (x).size()
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
using namespace std;
 

const int mod = 1e9 + 7;
const int N = 5e3 + 5;

int n, m, M, o, Len, Mx, ans, a[N], c[N], s[N], t[N];
vector<int> b[N], d[N];
void update(int k1, int k2)
{
	if(Mx < k1)
	{
		Mx = k1;
		ans = k2;
	}
	else if(Mx == k1)
	{
		ans += k2;
		if(ans >= mod) ans -= mod;
	}
}

void solve()
{
	int res = 0, tot = 1;
	rep(x, 1, n)
	{
	    if (x == c[o]) 
	    {
	        int r = 0;
	        for (auto i : d[x]) 
	        {
	            if (i == o) continue; 
	            if (t[i] > Len) r ++; 
	        }
	        if (!r) res ++;
	        else res += 2, tot = 1ll * tot * r % mod;
	        continue;
	    } 
	    int l = 0, r = 0, mid = 0;
	    for (auto i : d[x]) 
	    {
	        if (s[i] <= Len) l ++; 
	        if (t[i] > Len) r ++; 
	        if (s[i] <= Len && t[i] > Len) mid ++;
	    }
	    if (l == 0 && r == 0) continue;
	    if (l == 0 || r == 0) {res ++; tot = 1ll * tot * (l + r) % mod; continue;}
	    if (l == 1 && r == 1 && mid == 1)  {res ++, tot = 1ll * tot * 2 % mod; continue;}
	    if(l || r) {res += 2, tot = 1ll * tot * ((1ll * l * r - mid) % mod) % mod; continue;}
	}
	update(res, tot);
}

int main() 
{
    n = read(); 
	m = read();
    rep(i, 1, n) a[i] = read(), b[a[i]].pb(i);
    sort(a + 1, a + n + 1);
    rep0(i, m)
    {
        int x = read();
        int y = read();
        if (sz(b[x]) >= y) 
        {
            c[M] = x; 
            s[M] = b[x][y - 1]; 
            t[M] = b[x][b[x].size() - y];
            d[x].pb(M ++);
        }
    }
    Len = 0; o = M; 
    int res = 0, tot = 1;
	rep(x, 1, n)
	{
	    if (x == c[o]) 
	    {
	        int r = 0;
	        rep0(i, sz(d[x])) 
	        {
	            if (d[x][i] == o) continue; 
	            if (t[d[x][i]] > Len) r ++; 
	        }
	        if (!r) res ++;
	        else res += 2, tot = 1ll * tot * r % mod;
	        continue;
	    } 
	    int l = 0, r = 0, mid = 0;
	    rep0(i, sz(d[x])) 
	    {
	        if (s[d[x][i]] <= Len) l ++; 
	        if (t[d[x][i]] > Len) r ++; 
	        if (s[d[x][i]] <= Len && t[d[x][i]] > Len) mid ++;
	    }
	    if (!l && !r) continue;
	    if (!l || !r) {res ++; tot = 1ll * tot * (l + r) % mod; continue;}
	    if (l == 1 && r == 1 && mid == 1)  {res ++, tot = 1ll * tot * 2 % mod; continue;}
	    if(l || r) {res += 2, tot = 1ll * tot * ((1ll * l * r - mid) % mod) % mod; continue;}
	}
	update(res, tot);
    for (o = 0; o < M; o ++) 
    {
        Len = s[o];
	    solve();
    }
    printf("%d %d\n", Mx, ans);
    return 0;
}