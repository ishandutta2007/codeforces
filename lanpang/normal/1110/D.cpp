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

int n , m , a[maxn] , b[maxn] , dp[maxn][3][3] , ma , bf;

int main()
{
	int i , j , k , x , y , xx , yy;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		b[a[i]]++;
	}
	dp[0][0][0] = 1;
	for (i = 1 ; i <= m ; i++)
	{
		for (j = 0 ; j < 9 ; j++)
		{
			x = j/3;
			y = j%3;
			if (dp[i-1][x][y] == 0) continue;
			for (k = 0 ; k < 9 ; k++)
			{
				xx = k/3;
				yy = k%3;
				if (b[i] < xx+yy || xx > x+y) continue;
				bf = min(min(x,x+y-xx),b[i]-xx-yy);
				dp[i][xx][yy] = max(dp[i][xx][yy],dp[i-1][x][y]+bf+(b[i]-xx-yy-bf)/3);
			}
		}
	}
	for (j = 0 ; j < 3 ; j++)
		for (k = 0 ; k < 3 ; k++)
			ma = max(ma,dp[m][j][k]);
	cout << ma-1 << "\n";
	return 0;
}