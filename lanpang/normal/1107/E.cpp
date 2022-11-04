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
const LL mod = 1e9+7;

int n;
LL b[110] , dp[110][110][110];
char a[110];

int main()
{
	int i , j , k , l , h;
	cin >> n;
	cin >> a+1;
	for (i = 1 ; i <= n ; i++)
	{
		cin >> b[i];
		for (j = 1 ; j < i ; j++)
			b[i] = max(b[i],b[j]+b[i-j]);
	}
	for (i = 1 ; i <= n ; i++)
		for (j = 0 ; j < n ; j++)
			dp[i][i][j] = b[j+1];
	for (l = 2 ; l <= n ; l++)
	{
		for (i = 1 ; (i+l-1) <= n ; i++)
		{
			j = i+l-1;
			for (k = 0 ; (k+l) <= n ; k++)
			{
				dp[i][j][k] = b[k+1]+dp[i+1][j][0];
				for (h = i+1 ; h <= j ; h++)
					if (a[h] == a[i])
						dp[i][j][k] = max(dp[i][j][k],dp[i+1][h-1][0]+dp[h][j][k+1]);
			}
		}
	}
	cout << dp[1][n][0] << "\n";
	return 0;
}