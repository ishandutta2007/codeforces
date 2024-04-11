#include <bits/stdc++.h>
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define ll long long
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
#define all(x) (x).begin(), (x).end()
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

int n;
ll p[110], k[110], V, ans, aa, bb, now;
ll c[110][110];
int Tm[110];
ll S(ll a)
{
	return (V / a + 2.0 * sqrt(a) * sqrt(V));
}

void dfs2(int t, ll la, ll x)
{
    if (t > n)
    {
        ll nw = la * (x + V / la / x) + V / la;
        if (nw < ans) ans = nw, aa = la, bb = x;
        return;
    }

    rrep(i, Tm[t], 0)
        dfs2(t + 1, la, x * c[t][i]);
}

void dfs(ll x, ll t)
{
	if(x * x * x > V) return;
	if(t == n + 1)
	{
		ll pp = S(x);
		if(pp > ans) return;
		dfs2(1, x, 1);
		return;
	}

	rrep(i, k[t], 0)
    {
        Tm[t] = k[t] - i;
        dfs(x * c[t][i], t + 1);
    }
}

int main()
{
	int T = read();
	while(T --)
	{
		ans = 3e18;
	    V = 1;
		n = read();
		rep(i, 1, n) p[i] = read1(), k[i] = read1();
		rep(i, 1, n)
		{
			ll now = 1;
			rep(j, 1, k[i])
				V *= p[i], now *= p[i], c[i][j] = now;
			c[i][0] = 1;
		}
		dfs(1, 1);
		ll cc = V / aa / bb;
		cout << 2 * (aa * bb + bb * cc + aa * cc) << " " << aa << " " << bb << " " << cc << endl;
	}
	return 0;
}