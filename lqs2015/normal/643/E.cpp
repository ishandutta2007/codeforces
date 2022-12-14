#include<iostream>
#include<cstdio>
using namespace std;
const int threshold=100;
int n,tp,x,cnt,pa[555555],pos;
double dp[555555][111],ans,pre,nw,pp; 
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=threshold;j++) 
		dp[i][j]=1.00;
	}
	cnt=1;
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&tp,&x);
		if (tp==1)
		{
			cnt++;
			pa[cnt]=x;
			pre=dp[x][0];
			dp[x][0]*=0.50;
			nw=dp[x][0];
			pos=pa[x];
			for (int i=1;i<=threshold;i++)
			{
				if (!pos) break;
				pp=dp[pos][i];
				dp[pos][i]=dp[pos][i]/(0.50+0.50*pre)*(0.50+0.50*nw);
				pre=pp;nw=dp[pos][i];
				pos=pa[pos];
			}
		}
		else
		{
			ans=0.00;
			for (int i=1;i<=threshold;i++)
			{
				ans+=(i*(dp[x][i]-dp[x][i-1]));
			}
			printf("%.9lf\n",ans);
		}
	} 
	return 0;
}