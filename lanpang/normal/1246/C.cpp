#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , m , dp[2010][2010][2] , s[2010][2010][2];
char a[2010][2010];

void add(int &x , int y)
{
	x = (x+y)%mod;
}

void sub(int &x , int y)
{
	x = (x+mod-y)%mod;
}

int main()
{
	int i , j;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
		scanf("%s",a[i]+1);
	if (n == 1 && m == 1)
	{
		cout << "1\n";
		return 0;
	}
	for (i = 1 ; i <= n ; i++)
		for (j = m ; j >= 1 ; j--)
			s[i][j][0] = s[i][j+1][0]+(a[i][j] == 'R');
	for (j = 1 ; j <= m ; j++)
		for (i = n ; i >= 1 ; i--)
			s[i][j][1] = s[i+1][j][1]+(a[i][j] == 'R');
	dp[1][1][0] = dp[1][1][1] = 1;
	dp[1][2][0] = dp[2][1][1] = -1;
	for (i = 1 ; i <= n ; i++)
	{
		for (j = 1 ; j <= m ; j++)
		{
			add(dp[i][j][0],dp[i][j-1][0]);
			add(dp[i][j][1],dp[i-1][j][1]);
			add(dp[i+1][j][1],dp[i][j][0]);
			sub(dp[n-s[i+1][j][1]+1][j][1],dp[i][j][0]);
			add(dp[i][j+1][0],dp[i][j][1]);
			sub(dp[i][m-s[i][j+1][0]+1][0],dp[i][j][1]);
		}
	}
	add(dp[n][m][0],dp[n][m][1]);
	cout << dp[n][m][0] << "\n";
	return 0;
}