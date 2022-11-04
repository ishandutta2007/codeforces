#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <map>

using namespace std;

long long aa;
int x , y , ma;
int n , g , m , dp[201][5401];

void back1()
{
	x = 0;
	y = 0;
	while (aa%2 == 0)
	{
		x++;
		aa /= 2;
	}
	while (aa%5 == 0)
	{
		y++;
		aa /= 5;
	}
}

int main ()
{
	int i , j , k , p;
	cin >> n >> g;
	m = n*27;
	for (i = 0 ; i <= n ; i++)
	{
		for (j = 0 ; j <= m ; j++)
		{
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 0;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%I64d",&aa);
		back1();
		for (k = n ; k >= 1 ; k--)
		{
			for (j = m ; j >= y ; j--)
			{
				if (dp[k-1][j-y] >= 0)
				{
					dp[k][j] = max(dp[k-1][j-y]+x,dp[k][j]);
					if (k == g)
					{
						ma = max(ma,min(j,dp[k][j]));
					}
				}
			}
		}
	}
	cout << ma << "\n";
	//system("PAUSE");
	return 0;
}