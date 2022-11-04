#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , dp[76][1<<20] , t , ans;
char a[76];

int main()
{
	int i , j , k;
	cin >> n >> a+1;
	for (i = 0 ; i <= n ; i++)
		dp[i][0] = 1;
	for (i = 1 ; i <= n ; i++)
	{
		for (j = 0 ; j < (1<<20) ; j++)
		{
			if (!dp[i-1][j]) continue;
			t = 0;
			for (k = i ; k <= n ; k++)
			{
				t = t*2+a[k]-'0';
				if (!t) continue;
				if (t > 20) break;
				dp[k][j|(1<<(t-1))] = (dp[k][j|(1<<(t-1))]+dp[i-1][j])%mod;
			}
		}
	}
	for (i = 1 ; i <= n ; i++)
	{
		t = 0;
		for (j = 0 ; j < 20 ; j++)
		{
			t = t*2+1;
			ans = (ans+dp[i][t])%mod;
		}
	}
	cout << ans << "\n";
	return 0;
}