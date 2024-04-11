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
#define sz(x) (x).size()
#define All(x) (x).begin(), (x).end()
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
const int N = 510;
int n, m, k;
ll dp[N][N][11];
int u[N][N], l[N][N], r[N][N], d[N][N];
int main()
{
	n = read();
	m = read();
	k = read();
	rep(i, 1, n)
		rep(j, 1, m - 1)
		{
			int x = read();
            r[i][j] = l[i][j + 1] = x;
        }
    rep(i, 1, n - 1)
    	rep(j, 1, m)
    	{
    		int x = read();
            d[i][j] = u[i + 1][j] = x;
        }
    
    if(k & 1)
    {
    	rep(i, 1, n)
    	{
    		rep(j, 1, m)
    			printf("-1 ");
    		puts("");
        }
        return 0;
    }
    rep(c, 1, k / 2)
    	rep(i, 1, n)
    		rep(j, 1, m)
    		{
				dp[i][j][c] = 1e18;
				if (i > 1) dp[i][j][c] = min(dp[i][j][c], dp[i - 1][j][c - 1] + u[i][j]);
				if (i < n) dp[i][j][c] = min(dp[i][j][c], dp[i + 1][j][c - 1] + d[i][j]);
				if (j > 1) dp[i][j][c] = min(dp[i][j][c], dp[i][j - 1][c - 1] + l[i][j]);
				if (j < m) dp[i][j][c] = min(dp[i][j][c], dp[i][j + 1][c - 1] + r[i][j]);
            }
    rep(i, 1, n)
    {
    	rep(j, 1, m)
    		printf("%lld ",dp[i][j][k / 2] * 2);
    	puts("");
    }

    return 0;
}