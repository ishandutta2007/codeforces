#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 998244353;

int n , m , a[1010] , dp[2][1010] , s[2][1010] , ss[100010] , h[1010] , ans;

int main()
{
	int i , j , k , ii , tp , ct;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (k = 0 ; k <= a[n]-a[1] ; k++)
	{
		for (ct = 1 , tp = 1 , i = 2 ; i <= n ; i++)
		{
			if (a[i]-a[tp] >= k)
			{
				h[++ct] = i;
				tp = i;
			}
		}
		if (ct < m) break;
		for (i = 1 ; i <= n ; i++)
		{
			dp[1][i] = 1;
			s[1][i] = i;
		}
		for (j = 2 ; j <= m ; j++)
		{
			for (s[j%2][h[j]-1] = 0 , ii = 0 , i = h[j] ; i <= n ; i++)
			{
				while (ii+1 <= i && a[i]-a[ii+1] >= k) ii++;
				if (ii >= h[j-1] && a[i]-a[ii] >= k) dp[j%2][i] = s[1-j%2][ii];
				else dp[j%2][i] = 0;
				s[j%2][i] = (s[j%2][i-1]+dp[j%2][i])%mod;
			}
		}
		for (i = h[m] ; i <= n ; i++)
			ss[k] = (ss[k]+dp[m%2][i])%mod;
	}
	for (i = k-1 ; i >= 0 ; i--)
		ans = (ans+(ss[i]+mod-ss[i+1])*i)%mod;
	cout << ans << "\n";
	return 0;
}