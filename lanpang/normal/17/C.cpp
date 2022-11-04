#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
const int maxn = 1e6+10;
const int inf = 0x3f3f3f3f;
const LL mod = 51123987;

int n , dp[155][55][55][55] , jp[155][3] , la[3] , ans;
char a[155];

int main()
{
	int i , j , k , l;
	cin >> n;
	cin >> a+1;
	la[0] = la[1] = la[2] = n+1;
	for (i = n ; i >= 0 ; i--)
	{
		if (i > 0) la[a[i]-'a'] = i;
		jp[i][0] = la[0];
		jp[i][1] = la[1];
		jp[i][2] = la[2];
	}
	dp[0][0][0][0] = 1;
	for (i = 0 ; i <= n ; i++)
	{
		for (j = 0 ; j <= (n+2)/3 ; j++)
		{
			for (k = 0 ; k <= (n+2)/3 ; k++)
			{
				for (l = 0 ; l <= (n+2)/3 ; l++)
				{
					if (!dp[i][j][k][l]) continue;
					if (j < (n+2)/3 && jp[i][0] <= n) dp[jp[i][0]][j+1][k][l] = (dp[jp[i][0]][j+1][k][l]+dp[i][j][k][l])%mod;
					if (k < (n+2)/3 && jp[i][1] <= n) dp[jp[i][1]][j][k+1][l] = (dp[jp[i][1]][j][k+1][l]+dp[i][j][k][l])%mod;
					if (l < (n+2)/3 && jp[i][2] <= n) dp[jp[i][2]][j][k][l+1] = (dp[jp[i][2]][j][k][l+1]+dp[i][j][k][l])%mod;
				}
			}
		}
		if (n%3 == 0) ans = (ans+dp[i][n/3][n/3][n/3])%mod;
		if (n%3 == 1) ans = (ans+dp[i][n/3+1][n/3][n/3]+dp[i][n/3][n/3+1][n/3]+dp[i][n/3][n/3][n/3+1])%mod;
		if (n%3 == 2) ans = (ans+dp[i][n/3+1][n/3+1][n/3]+dp[i][n/3][n/3+1][n/3+1]+dp[i][n/3+1][n/3][n/3+1])%mod;
	}
	cout << ans << "\n";
	return 0;
}