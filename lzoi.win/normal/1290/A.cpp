#include<cstdio>
#include<algorithm>
using namespace std;
int t;
int n,m,k;
int a[3510];
int can_pick(int lpick)
{
	return max(a[lpick+1],a[n-m+lpick+1]);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&n,&m,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		int ans=-1;
		if(k>=m)
		{
			ans=0;
			for(int i=0;i<=m-1;i++)
				ans=max(ans,can_pick(i));
		}
		else
		{
			for(int i=0;i<=k;i++)
			{
				int ans1=0x3f3f3f3f;
				for(int j=0;j<=m-k-1;j++)
					ans1=min(can_pick(i+j),ans1);
				ans=max(ans,ans1);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}