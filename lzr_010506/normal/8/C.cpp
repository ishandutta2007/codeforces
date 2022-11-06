#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ls rt << 1
#define rs rt << 1 | 1
#define mod 1000000007
#define sz(x) (int)(x).size()
#define vi vector<int>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 24;
int dp[1 << N], pre[1 << N];
int d[N + 2][N + 2], x[N + 2], y[N + 2];
int n;
int dfs(int x)
{
    if(dp[x] != -1)return dp[x];
    dp[x] = 1e9;
    rep(i, 0, n - 1)
    {
        if(x & (1 << i))
        {
            int next = dfs(x ^ (1 << i));
            if(dp[x] > next + d[n][i] + d[i][n])
            {
                dp[x] = next + d[n][i] + d[i][n];
                pre[x] = x ^ (1 << i);
            }
            rep(k, i + 1, n - 1)
            {
            	if(x & (1 << k))
            	{
            		int to = dfs(x ^ (1 << i) ^ (1 << k));
            		if(dp[x] > to + d[n][i] + d[i][k] + d[k][n])
            		{
            			dp[x] = to + d[n][i] + d[i][k] + d[k][n];
            			pre[x] = x ^ (1 << i) ^ (1 << k);
            		}
            	}
            }
            goto L1;
        }
    }
    L1:;
    return dp[x];
}
void dfs2(int x)
{
    if(x)
    {
    	rep(i, 0, n - 1)
            if((x ^ pre[x]) & (1 << i))
                printf("%d ", i + 1);
        printf("0 ");
        dfs2(pre[x]);
    }
}
int main()
{
	x[0] = read();
	y[0] = read();
	n = read();
    x[n] = x[0], y[n] = y[0];
    rep(i, 0, n - 1)
    	x[i] = read(), y[i] = read();
   	rep(i, 0, n)
   		rep(j, 0, n)
   		    d[i][j] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    printf("%d\n", dfs((1 << n) - 1));
    printf("0 ");
    dfs2((1 << n) - 1);
    return 0;
}