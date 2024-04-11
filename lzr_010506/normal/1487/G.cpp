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
#define Alsls(x) (x).begin(), (x).end()
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
const ll mod = 998244353;
const int N = 410;
int f[N][N][3][3], g[N][N][3][3], p[N][2][2], q[N][2][2], a[N];
ll s[N], sum[N][N];

void add(int &x,int y) 
{
	x += y; 
	if (x >= mod) x -= mod;
}
int main() 
{
	int n = read();
	f[0][0][0][0] = 1;
	rep(i, 1, n)
	{
		rep0(x, 400)
			rep0(y, 400)
				rep0(f1, 3)
					rep0(f2, 3)
						if (f[x][y][f1][f2]) 
						{
							if (f1 != 1) add(g[x + 1][y][f2][1], f[x][y][f1][f2]);
							if (f1 != 2) add(g[x][y + 1][f2][2], f[x][y][f1][f2]);
							if (f1 > 0 || i <= 2) add(g[x][y][f2][0], 1LL * f[x][y][f1][f2] * 24LL % mod);
							else add(g[x][y][f2][0], 1LL * f[x][y][f1][f2] * 23LL % mod);
						}
				
		rep0(x, 400)
			rep0(y, 400)
				rep0(f1, 3)
					rep0(f2, 3)
						f[x][y][f1][f2] = g[x][y][f1][f2], g[x][y][f1][f2] = 0;
		
	}
 
	p[0][0][0] = 1;
	rep(i, 1, n)
	{
		rep0(x, i)
			rep0(f1, 2)
				rep0(f2, 2)
					if (p[x][f1][f2]) 
					{
						if (f1 != 1) add(q[x + 1][f2][1], p[x][f1][f2]);
						if (f1 > 0 || i <= 2) add(q[x][f2][0], 1LL * p[x][f1][f2] * 25LL % mod);
						else add(q[x][f2][0], 1LL * p[x][f1][f2] * 24LL % mod);
					}
		rep0(x, i + 1)
			rep0(f1, 2)
				rep0(f2, 2)
					p[x][f1][f2] = q[x][f1][f2], q[x][f1][f2] = 0;
	}
 
 	rep0(i, 26) a[i] = read();
	ll ans = 26 * 26;
	rep(i, 1, n - 2) ans = ans * 25 % mod;
	rrep(i, 400, 0)
	{
		rep0(x, 2)
			rep0(y, 2)
				(s[i] += p[i][x][y]) %= mod;
		s[i] += s[i + 1]; 
		s[i] %= mod;
	}
	rrep(i, 400, 0)
		rrep(j, 400, 0)
			rep0(x, 3)
				rep0(y, 3)
					(sum[i][j] += f[i][j][x][y]) %= mod;	
	
	rrep(i, 400, 0)
		rrep(j, 400, 0)
		{
			sum[i][j] = (sum[i + 1][j] + sum[i][j + 1] + sum[i][j] - sum[i + 1][j + 1]) % mod;
			sum[i][j] = (sum[i][j] % mod + mod) % mod;
		}
	rep0(i, 26)
	{
		ans = ans - s[a[i] + 1]; 
		ans = (ans % mod + mod) % mod;
	}
	rep0(i, 26)
		rep(j, i + 1, 25) 
		{
			ans = ans + sum[a[i] + 1][a[j] + 1]; 
			ans = (ans % mod + mod) % mod;
		}
	cout << ans << endl;
	return 0;
}