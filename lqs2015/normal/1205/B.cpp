#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,dist[222][222],ans,mp[222][222];
long long a[111111],b[111111],cnt;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if (a[i]) b[++cnt]=a[i];
	}
	n=cnt;
	if (n>120)
	{
		printf("3\n");
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		dist[i][j]=mp[i][j]=1e8;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			if ((b[i]&b[j])) dist[i][j]=dist[j][i]=1;
			if ((b[i]&b[j])) mp[i][j]=mp[j][i]=1;
		}
	}
	ans=1e8;
	for (int k=1;k<=n;k++)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				ans=min(ans,dist[i][j]+mp[i][k]+mp[k][j]);
			}
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	if (ans>1e7) printf("-1\n");
	else printf("%d\n",ans);
	return Accepted;
}