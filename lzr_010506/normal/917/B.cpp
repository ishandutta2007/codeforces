#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 10010;

vector<int> ve[110],vv[110];
int m,n,a,b,d,dp[110][110][55][2],ans[111];
char c;
int Dp(int q,int w,int r,int t)
{
	if (dp[q][w][r][t] != -1) return dp[q][w][r][t];
	if (!t)
	{
		int nn = ve[q].size();
		rep(i, 0, nn - 1)
			if (vv[q][i] >= r && Dp(ve[q][i], w, vv[q][i], 1))
			{
				dp[q][w][r][t] = 1;
				return 1;
			}
		dp[q][w][r][t] = 0;
		return 0;
	}
	else
	{
		int nn = ve[w].size();
		rep(i, 0, nn - 1)
			if (vv[w][i] >= r && Dp(q, ve[w][i], vv[w][i], 0) == 0)
			{
				dp[q][w][r][t] = 0;
				return 0;
			}
		dp[q][w][r][t] = 1;
		return 1;
	}
}
int main()
{
	n = read();
	m = read();
	memset(dp, -1, sizeof(dp));
	rep(i, 1, m)
    {
    	a = read();
    	b = read();
   		c = getchar();
    	ve[a].pb(b);
    	vv[a].pb(c - 'a');
	}
	rep(i, 1, n)
		rep(j, 1, n)
	   		Dp(i,j,0,0);
	rep(i, 1, n)
	{
	  	rep(j, 1, n)
	  		if (dp[i][j][0][0]) printf("A");
	  		else printf("B");
	  	puts("");
 	}
	return 0;
}