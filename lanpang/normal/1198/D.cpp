#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , s[55][55] , dp[55][55][55][55];
char a[55][55];

int dfs(int x , int y , int xx , int yy)
{
	if (s[y][yy]-s[x-1][yy]-s[y][xx-1]+s[x-1][xx-1] == 0) dp[x][y][xx][yy] = 0;
	else if (x == y && xx == yy) dp[x][y][xx][yy] = 1;
	if (dp[x][y][xx][yy] != 100) return dp[x][y][xx][yy];
	dp[x][y][xx][yy] = max(y-x+1,yy-xx+1);
	for (int i = x ; i < y ; i++)
		dp[x][y][xx][yy] = min(dp[x][y][xx][yy],dfs(x,i,xx,yy)+dfs(i+1,y,xx,yy));
	for (int i = xx ; i < yy ; i++)
		dp[x][y][xx][yy] = min(dp[x][y][xx][yy],dfs(x,y,xx,i)+dfs(x,y,i+1,yy));
	//cout << x << " " << y << " " << xx << " " << yy << " : " << dp[x][y][xx][yy] << "\n";
	return dp[x][y][xx][yy];
}

int main()
{
	int i , j , k , ii , jj;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		cin >> a[i]+1;
		for (j = 1 ; j <= n ; j++)
		{
			if (a[i][j] == '.') k = 0;
			else k = 1;
			s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+k;
			for (ii = 1 ; ii <= n ; ii++)
				for (jj = 1 ; jj <= n ; jj++)
					dp[i][j][ii][jj] = 100;
		}
	}
	cout << dfs(1,n,1,n) << "\n";
	return 0;
}