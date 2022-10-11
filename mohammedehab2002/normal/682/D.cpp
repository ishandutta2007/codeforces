#include <iostream>
#include <string.h>
using namespace std;
int dp[1005][1005][15][2];
string a,b;
int main()
{
	int n,m,k;
	cin >> n >> m >> k >> a >> b;
	a='a'+a;
	b='b'+b;
	for (int i=1;i<=n;i++)
	{
		for (int x=1;x<=m;x++)
		{
			for (int j=1;j<=k;j++)
			{
				for (int l=0;l<2;l++)
				dp[i][x][j][0]=max(max(dp[i-1][x][j][l],dp[i][x-1][j][l]),max(dp[i][x][j][0],dp[i-1][x-1][j][l]));
				dp[i][x][j][1]=-(1<<30);
				if (a[i]==b[x])
				{
					dp[i][x][j][1]=max(dp[i-1][x-1][j-1][0],dp[i-1][x-1][j-1][1])+1;
					if (a[i-1]==b[x-1])
					dp[i][x][j][1]=max(dp[i][x][j][1],dp[i-1][x-1][j][1]+1);
				}
			}
		}
	}
	cout << max(dp[n][m][k][0],dp[n][m][k][1]);
}