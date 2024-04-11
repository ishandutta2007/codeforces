#include <bits/stdc++.h>
#define FOR(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
#define db double
#define N 210
using namespace std;
db dp[N][N][N];
db p[N];
int a[N], n, l, k;

void Add(db &x, db y)
{
	x += y;
}

int main()
{
	cin >> n >> l >> k;
	FOR(i, 1, n) cin >> p[i];
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, n) p[i] /= 100;
	
	dp[1][1][1] = 1;
	FOR(i, 1, n)
		FOR(j, 1, i)
			FOR(k, 1, n + 1)
			{
				Add(dp[i + 1][j + 1][min(n,k + a[i]) + 1], dp[i][j][k] *p [i]);
				Add(dp[i + 1][j][k], dp[i][j][k] * (1 - p[i]));
			}
	db ans = 0;
	FOR(i, l + 1, n + 1)
		FOR(j, 1, n + 1)
			if (k >= i - j) 
				ans += dp[n + 1][i][j];
	printf("%.9lf\n",ans);
	return 0;
}