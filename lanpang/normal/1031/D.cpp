#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , m , dp[2010][2010] , f[2010][2010] , mi;
char a[2010][2010] , s[4010] , mc;

int main()
{
	int i , j , k;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
		scanf("%s",a[i]+1);
	dp[1][1] = (a[1][1]=='a'?0:1);
	for (k = 2 ; k <= n*2 ; k++)
	{
		mi = m+1;
		for (i = max(1,k-n) ; i <= min(k-1,n) ; i++)
		{
			j = k-i;
			mi = min(mi,dp[i][j]);
			if (i+1 <= n) dp[i+1][j] = m+1;
			if (j+1 <= n) dp[i][j+1] = m+1;
		}
		if (mi > m) break;
		s[k-1] = 'a';
		for (i = max(1,k-n) ; i <= min(k-1,n) ; i++)
		{
			j = k-i;
			if (i+1 <= n) dp[i+1][j] = min(dp[i+1][j],dp[i][j]+(a[i+1][j]=='a'?0:1));
			if (j+1 <= n) dp[i][j+1] = min(dp[i][j+1],dp[i][j]+(a[i][j+1]=='a'?0:1));
		}
	}
	k--;
	for (i = max(1,k-n) ; i <= min(k-1,n) ; i++)
	{
		j = k-i;
		if (dp[i][j] > m) continue;
		if (i+1 <= n) f[i+1][j] = 1;
		if (j+1 <= n) f[i][j+1] = 1;
	}
	f[1][1] = 1;
	for (k++ ; k <= n*2 ; k++)
	{
		mc = 'z'+1;
		for (i = max(1,k-n) ; i <= min(k-1,n) ; i++)
		{
			j = k-i;
			if (!f[i][j]) continue;
			mc = min(mc,a[i][j]);
		}
		s[k-1] = mc;
		for (i = max(1,k-n) ; i <= min(k-1,n) ; i++)
		{
			j = k-i;
			if (!f[i][j] || a[i][j] > mc) continue;
			if (i+1 <= n) f[i+1][j] = 1;
			if (j+1 <= n) f[i][j+1] = 1;
		}
	}
	s[n*2] = '\0';
	cout << s+1 << "\n";
	return 0;
}