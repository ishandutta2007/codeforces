#include<iostream>
#include<cstdio>
using namespace std;
int a[1000000],b[1000000];
long long ans=1ll*(1ll<<60);
int main()
{
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
	{
		long long Ans=-1ll*(1ll<<60);
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			for(int k=1;k<=m;k++)
			{
				Ans=max(Ans,(long long)a[j]*(long long)b[k]);
			}
		}
		ans=min(ans,Ans);
	}
	printf("%lld\n",ans);
	return 0;
}