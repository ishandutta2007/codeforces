#include <bits/stdc++.h>
using namespace std;
const int N=500;
const int M=1023;
int n,m;
int a[N+5][N+5];
int dp[N+5][M+5],nxt[N+5][M+5];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	dp[0][0]=1;
	nxt[0][0]=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=M;j++)
		{
			for(int k=1;k<=m;k++)
			{
				if(dp[i-1][j^a[i][k]]) 
				{
					dp[i][j]=1;
					nxt[i][j]=k;
					break;
				}	
			}
		}
	}
	int id=-1;
	for(int i=1;i<=M;i++) 
	{
		if(dp[n][i])
		{
			id=i;
			break;
		}
	}
	if(id==-1)
	{
		printf("NIE\n");
		return 0;
	}
	vector<int> ans;
	for(int i=n;i>=1;i--)
	{
		ans.push_back(nxt[i][id]);
		id^=a[i][nxt[i][id]];
	}
	printf("TAK\n");
	for(int i=(int)ans.size()-1;i>=0;i--) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}