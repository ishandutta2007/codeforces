#include<bits/stdc++.h>
#include<time.h>
using namespace std;
const int inf=1145141919;
int n,k,dist[88][88],col[88],dp[11][88],ans;
void upd(int &x,int y)
{
	if (x>y) x=y;
}
int main()
{
	double tt=clock();srand(time(0));
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			scanf("%d",&dist[i][j]);
		}
	}
	ans=inf;
	while((clock()-tt)/CLOCKS_PER_SEC<2.7)
	{
		for (int i=1;i<=n;i++)
		{
			col[i]=rand()%10;
			if (col[i]<5) col[i]=0;
			else col[i]=1;
		}
		for (int i=0;i<=k;i++)
		{
			for (int j=1;j<=n;j++)
			dp[i][j]=inf;
		}
		dp[0][1]=0;
		for (int i=1;i<=k;i++)
		{
			for (int j=1;j<=n;j++)
			{
				for (int h=1;h<=n;h++)
				{
					if (col[h]==col[j]) continue;
					upd(dp[i][h],dp[i-1][j]+dist[j][h]);
				}
			}
		}
		ans=min(ans,dp[k][1]);
	}
	printf("%d\n",ans);
	return 0;
}