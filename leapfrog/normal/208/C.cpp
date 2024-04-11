#include<bits/stdc++.h>
using namespace std;
int n,m;double dis[105][105],num[105][105],ans=0;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=2147483647;
	for(int i=1;i<=n;i++) num[i][i]=1,dis[i][i]=0;
	for(int i=1,x,y;i<=m;i++) scanf("%d%d",&x,&y),dis[x][y]=dis[y][x]=1,num[x][y]=num[y][x]=1;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j&&j!=k&&i!=k)
				{
					if(dis[i][j]>dis[i][k]+dis[k][j]) dis[i][j]=dis[i][k]+dis[k][j],num[i][j]=num[i][k]*num[k][j];
					else if(dis[i][j]==dis[i][k]+dis[k][j]) num[i][j]+=num[i][k]*num[k][j];
				}
	for(int i=1;i<=n;i++)
	{
		double t=0;
		for(int j=1;j<=n;j++)
			if(dis[i][j]==1)
			{
				if(dis[1][i]+1+dis[j][n]==dis[1][n]) t+=num[1][i]*num[j][n];
				else if(dis[1][j]+1+dis[i][n]==dis[1][n]) t+=num[1][j]*num[i][n];
			}
		ans=max(ans,t);
	}
	return printf("%.6lf\n",ans/num[1][n]),0;
}