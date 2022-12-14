#include<bits/stdc++.h>
using namespace std;
int k1,k2,k3,x,cur,suf[222222],ans,n;
bool a[4][222222];
int main()
{
	scanf("%d%d%d",&k1,&k2,&k3);
	n=k1+k2+k3;
	for (int i=1;i<=k1;i++)
	{
		scanf("%d",&x);
		a[1][x]=1;
	}
	for (int i=1;i<=k2;i++)
	{
		scanf("%d",&x);
		a[2][x]=1;
	}
	for (int i=1;i<=k3;i++)
	{
		scanf("%d",&x);
		a[3][x]=1;
	}
	suf[n+1]=k3;
	cur=k3;
	for (int i=n;i>=1;i--)
	{
		if (a[3][i]) cur--;
		if (a[2][i]) cur++;
		suf[i]=min(suf[i+1],cur);
	}
	cur=k1;ans=cur+suf[1];
	for (int i=1;i<=n;i++)
	{
		if (a[1][i]) cur--;
		if (a[2][i]) cur++;
		ans=min(ans,cur+suf[i+1]);
	}
	printf("%d\n",ans);
	return 0;
}