#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5+10;
const LL mod = 1e9+7;

int n , dp[2][maxn] , s1 , s2 , ans;
LL a[maxn] , b[maxn];

void qmin(int &x , int y)
{
	if (y < x) x = y;
}

int main()
{
	int i , j;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%I64d",a+i);
		dp[0][i] = mod;
	}
	sort(a+1,a+n+1);
	for (i = 1 ; i <= n ; i++)
		a[i] = a[n]-a[i];
	dp[0][0] = 0;
	for (i = 0 ; i < 60 ; i++)
	{
		s1 = s2 = 0;
		for (j = 0 ; j <= n ; j++)
		{
			if ((a[j]>>i)&1) s1++;
			dp[1-i%2][j] = mod;
		}
		for (j = 0 ; j <= n ; j++)
		{
			if ((a[j]>>i)&1) s2++;
			if (dp[i%2][j] == mod) continue;
			qmin(dp[1-i%2][s2],dp[i%2][j]+j-s2+s1-s2);
			qmin(dp[1-i%2][j+s1-s2],dp[i%2][j]+n-(j-s2+s1-s2));
		}
		s1 = 0;
		for (j = 1 ; j <= n ; j++)
			if ((a[j]>>i)&1) b[++s1] = a[j];
			else b[++s2] = a[j];
		for (j = 1 ; j <= n ; j++)
			a[j] = b[j];
	}
	ans = mod;
	for (j = 0 ; j <= n ; j++)
		qmin(ans,dp[0][j]+j);
	cout << ans << "\n";
	return 0;
}