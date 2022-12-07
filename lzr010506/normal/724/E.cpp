#include <bits/stdc++.h>
#define dfor(i, x, y) for(int (i) = (x); (i) >= (y); (i) --)
#define For(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f3fll
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
ll dp[2][30010];
int n, c, A[30010], B[30010];
int main()
{
	n = read();
	c = read(); 
	dfor(i, n, 1) A[i] = read();
	dfor(i, n, 1) B[i] = read();
	For(i, 1, n) 
	{
		dp[i & 1][0] = dp[i - 1 & 1][0] + B[i];
		dp[i - 1 & 1][i] = inf;
		For(j, 1, i) dp[i & 1][j] = min(dp[i - 1 & 1][j - 1] + A[i], dp[i - 1 & 1][j] + B[i] + (ll)c * j);
	}
	ll ans = inf;
	For(j, 0, n) ans = min(ans, dp[n & 1][j]);
	printf("%I64d",ans);
	return 0;
}