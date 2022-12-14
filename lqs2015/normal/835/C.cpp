#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,q,c,x,y,z,kk,t,x1,y1,x2,y2;
int dp[111][111][13];
vector<int> v[111][111];
int main()
{
	scanf("%d%d%d",&n,&q,&c);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		v[x][y].push_back(z); 
	}
	for (int i=1;i<=100;i++)
	{
		for (int j=1;j<=100;j++)
		{
			for (int k=0;k<=c;k++)
			{
				kk=0;
				for (int h=0;h<v[i][j].size();h++)
				{
					kk+=((v[i][j][h]+k)%(c+1));
				}
				dp[i][j][k]=dp[i][j-1][k]+dp[i-1][j][k]-dp[i-1][j-1][k]+kk;
			}
		}
	}
	while(q--)
	{
		scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
		printf("%d\n",dp[x2][y2][t%(c+1)]-dp[x1-1][y2][t%(c+1)]-dp[x2][y1-1][t%(c+1)]+dp[x1-1][y1-1][t%(c+1)]);
	}
	return 0;
}