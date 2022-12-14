#include<iostream>
#include<cstdio>
using namespace std;
int n,sum[111111],pos[111111];
long long ans;
int a[111111];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=n;i>=1;i--)
	{
		if (!pos[a[i]])
		{
			pos[a[i]]=i;
			sum[i]=sum[i+1]+1;
		}
		else
		{
			pos[a[i]]=i;
			sum[i]=sum[i+1];
		}
	}
	for (int i=1;i<=100000;i++)
	{
		if (pos[i]) ans+=(long long)sum[pos[i]+1];
	}
	printf("%I64d\n",ans);
	return 0;
}