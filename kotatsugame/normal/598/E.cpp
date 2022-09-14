#include<cstdio>
#include<algorithm>
using namespace std;
int dp[31][31][51];
main()
{
	for(int h=1;h<=30;h++)for(int w=1;w<=30;w++)
	{
		for(int k=1;k<=50;k++)dp[h][w][k]=1e9;
		if(h*w<=50)dp[h][w][h*w]=0;
		for(int i=1;i<h;i++)
		{
			int L=i*w,R=(h-i)*w;
			int c=w*w;
			for(int k=0;k<=50;k++)
			{
				dp[h][w][k]=min(dp[h][w][k],dp[i][w][k]+c);
				if(k>=R)dp[h][w][k]=min(dp[h][w][k],dp[i][w][k-R]+c);
				dp[h][w][k]=min(dp[h][w][k],dp[h-i][w][k]+c);
				if(k>=L)dp[h][w][k]=min(dp[h][w][k],dp[h-i][w][k-L]+c);
			}
		}
		for(int j=1;j<w;j++)
		{
			int L=j*h,R=(w-j)*h;
			int c=h*h;
			for(int k=0;k<=50;k++)
			{
				dp[h][w][k]=min(dp[h][w][k],dp[h][j][k]+c);
				if(k>=R)dp[h][w][k]=min(dp[h][w][k],dp[h][j][k-R]+c);
				dp[h][w][k]=min(dp[h][w][k],dp[h][w-j][k]+c);
				if(k>=L)dp[h][w][k]=min(dp[h][w][k],dp[h][w-j][k-L]+c);
			}
		}
	}
	int T;scanf("%d",&T);
	for(;T--;)
	{
		int n,m,k;scanf("%d%d%d",&n,&m,&k);
		printf("%d\n",dp[n][m][k]);
	}
}