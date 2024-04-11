#include<bits/stdc++.h>
using namespace std;

int n;
int f[10010];

int main()
{
	scanf("%d",&n);
	memset(f,-1,sizeof(f));
	f[0]=0;
	for (int i=4;i<=10000;i++)
	{
		if (i>=4)	f[i]=f[i-4];
		if (i>=9 && f[i-9]!=-1)
		{
			if (f[i]==-1 || f[i-9]<f[i])	f[i]=f[i-9];
		}
		if (i>=49 && f[i-49]!=-1)
		{
			if (f[i]==-1 || f[i-49]<f[i])	f[i]=f[i-49];
		}
		if (f[i]!=-1)	f[i]++;
	}
	long long ans=0;
	for (int i=0;i<49;i++)
	{
		if (f[10000-i]!=-1 && f[10000-i]<n)	ans+=n-f[10000-i];
	}
	for (int i=0;i<=10000;i++)
	if (f[i]<=n && f[i]!=-1)
		ans++;
	printf("%lld\n",ans);
	return 0;
}