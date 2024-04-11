#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
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
typedef pair <int,int> II;
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

LL n , m , a[51] , s[51][51] , dp[51][51] , ans;

int main()
{
	LL i , j , k , l;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++) cin >> a[i];
	for (i = 1 ; i <= n ; i++)
		for (j = i ; j <= n ; j++)
			s[i][j] = s[i][j-1]+a[j];
	ans = 0;
	for (l = 56 ; l >= 1 ; l--)
	{
		dp[0][0] = 1;
		for (i = 1 ; i <= n ; i++)
			for (k = 1 ; k <= min(i,m) ; k++)
				dp[i][k] = 0;
		ans += (LL)1<<(l-1);
		for (i = 1 ; i <= n ; i++)
		{
			for (k = 1 ; k <= min(i,m) ; k++)
			{
				for (j = 0 ; j < i ; j++)
				{
					if (dp[j][k-1] && ans == (ans&s[j+1][i]))
					{
						dp[i][k] = 1;
						break;
					}
				}
			}
		}
		if (!dp[n][m]) ans -= (LL)1<<(l-1);
	}
	cout << ans << "\n";
	return 0;
}