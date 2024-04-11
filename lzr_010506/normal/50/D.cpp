#include <bits/stdc++.h>
using namespace std;
const double E = 2.718281828459045235360287;
const double eps = 1e-8;
struct Point
{
	double x, y;
}a[110], p;
int n, k;
double dp[110][110];
double f;
int main()
{
	cin >> n >> k >> f;
	cin >> p.x >> p.y;
	for(int i = 1; i <= n; i ++)
		cin >> a[i].x >> a[i].y;
	double l = 0, r = 4000.0;
	while(r - l > eps)
	{
		double mid = (l + r) / 2.0;
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; i ++)
		{
			double Dis = (a[i].x - p.x) * (a[i].x - p.x) + (a[i].y - p.y) * (a[i].y - p.y);
			double pp;
			if(Dis <= mid * mid) pp = 1.0;
			else pp = pow(E, 1.0 - (Dis / (mid * mid)));
			if(i == 1)
			{
				dp[i][0] = 1.0 - pp;
				dp[i][1] = pp;
			}
			else
			{
				dp[i][0] = dp[i - 1][0] * (1.0 - pp);
				for(int j = 1; j <= k; j ++)
				{
					if(j == k) dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] * pp;
					else dp[i][j] = dp[i - 1][j] * (1 - pp) + dp[i - 1][j - 1] * pp;
				}
			}
		}
		if(dp[n][k] * 1000 < 1000 - f) l = mid;
			else r = mid;
	}
	printf("%.8lf", r);
	return 0;
}