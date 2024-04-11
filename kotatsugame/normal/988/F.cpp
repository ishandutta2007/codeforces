#include<cstdio>
#include<algorithm>
using namespace std;
int A,M,N;
bool rain[2020];
int umb[2020];
int dp[2020];
main()
{
	scanf("%d%d%d",&A,&N,&M);
	for(int i=0;i<N;i++)
	{
		int l,r;scanf("%d%d",&l,&r);
		for(int j=l;j<r;j++)rain[j]=true;
	}
	for(int i=0;i<M;i++)
	{
		int x,p;scanf("%d%d",&x,&p);
		if(umb[x]==0)umb[x]=p;
		else umb[x]=min(umb[x],p);
	}
	for(int i=0;i<A;i++)
	{
		if(!rain[i])dp[i+1]=dp[i];
		else
		{
			dp[i+1]=1e9;
			for(int j=0;j<=i;j++)if(umb[j])
			{
				dp[i+1]=min(dp[i+1],dp[j]+(i+1-j)*umb[j]);
			}
		}
	}
	int ans=dp[A];
	printf("%d\n",ans<(int)1e9?ans:-1);
}