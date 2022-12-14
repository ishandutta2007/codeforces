#include<bits/stdc++.h>
using namespace std;
int a[22][22],id[22][22],x,y,cnt;
pair<int,int> p[111];
double dp[111][2],cur;
int main()
{
	x=10;y=1;
	while(x!=1 || y!=1)
	{
		id[x][y]=++cnt;
		p[cnt]=make_pair(x,y);
		if (x&1)
		{
			if (y==1) 
			{
				x--;
			}
			else y--;
		}
		else
		{
			if (y==10) x--;
			else y++;
		}
	}
	cnt++;id[1][1]=cnt;p[cnt]=make_pair(1,1);
	for (int i=1;i<=10;i++)
	{
		for (int j=1;j<=10;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	dp[cnt][0]=dp[cnt][1]=0.00;
	for (int i=cnt-1;i>=1;i--)
	{
		if (cnt-i<6) 
		{
			for (int j=i+1;j<cnt;j++) dp[i][0]+=dp[j][0];
			dp[i][0]+=6.00;
			dp[i][0]=dp[i][0]/(double)(cnt-i);dp[i][1]=dp[i][0];
		}
		else
		{
			cur=0.00;
			for (int j=i+1;j<=i+6;j++) cur+=dp[j][0];
			cur/=6.00;cur+=1.00;dp[i][0]=dp[i][1]=cur;x=p[i].first;y=p[i].second;
			if (a[x][y]) 
			{
				dp[i][0]=fmin(dp[i][0],dp[id[x-a[x][y]][y]][1]);
			}
		}
	}
	printf("%.9lf\n",dp[1][0]);
	return 0;
}