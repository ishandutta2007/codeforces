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
#define All(x) (x).begin(), (x).end()
#define lowbit(x) ((x) & -(x))
#define int long long
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
const int N = 2e5 + 10;
const int M = 40;
const int K = 18;
const int mod = 998244353;
char s[N], t[N];

ll Ans = 1, ans[M];

ll a[N], b[N];
int n, m, vis[N];
ll dp[2][M][1 << K], sz[1 << K];

void add(ll &a, ll b)
{
	a += b;
	if(a >= mod) a -= mod;
}

signed main() 
{
	n = read();
	m = read();
	int k = 18;
	rep(i, 1, n) a[i] = read();
	rep(i, 1, n)
	{
		rrep(j, m - 1, 0)
			if ((a[i] >> j) & 1) 
			{
				if (vis[j]) a[i] ^= b[j];
				else 
				{
					vis[j] = 1;
					b[j] = a[i];
					goto L1;
				}
			}
		Ans = Ans * 2LL % mod;
		L1:;
	}
	if(m < k) k = m;
	rep(i, 1, (1 << 18) - 1)
		sz[i] = sz[i ^ lowbit(i)] + 1;
	int pp = 1 << (m - k);
	rep0(mask, (1 << k))
	{
		int flag = 1;
		ll w = 0;
		rep0(i, k)
		{
			if ((mask >> i) & 1) 
			{
				if (!vis[m - 1 - i]) { flag = 0; break; }
				w ^= b[m - 1 - i];
			}
		}
		if (flag) dp[0][sz[w >> (m - k)]][w & (pp - 1)] ++;
	}
	if(m - k)
	{
		rep0(i, m - k)
			if (vis[i]) 
			{
				rep0(c, k + 1)
					rep0(j, pp)
						dp[1][c][j] = dp[0][c][j];
				
				rep0(c, k + 1) 
					rep0(j, pp)
						add(dp[1][c][j ^ b[i]] , dp[0][c][j]);
				rep0(c, k + 1) 
					rep0(j, pp)
						dp[0][c][j] = dp[1][c][j];
				
			}
		
	}
	rep0(i, k + 1)
		rep0(j, pp)
			add(ans[sz[j] + i], dp[0][i][j]);
	rep0(i, m + 1) printf("%lld ", 1LL * ans[i] * Ans % mod);
	return 0;
}