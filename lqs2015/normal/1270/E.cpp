#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,x[1111],y[1111],cnt,a[1111],b[1111];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
	}
	for (int i=1;i<=n;i++)
	{
		if ((x[i]+y[i])%2==0) cnt++;
	}
	if (cnt!=0 && cnt!=n)
	{
		printf("%d\n",cnt);
		for (int i=1;i<=n;i++)
		{
			if ((x[i]+y[i])%2==0) printf("%d ",i);
		}
		printf("\n");
		return 0;
	}
	while(1)
	{
		cnt=0;
		for (int i=1;i<=n;i++)
		{
			if ((x[i]+y[i])%2==0)
			{
				a[i]=(x[i]+y[i])/2;
				b[i]=(x[i]-y[i])/2;
			}
			else
			{
				a[i]=(x[i]+y[i]+1)/2;
				b[i]=(x[i]-y[i]+1)/2;
			}
		}
		for (int i=1;i<=n;i++)
		{
			if ((a[i]+b[i])%2==0) cnt++;
		}
		for (int i=1;i<=n;i++) 
		{
			x[i]=a[i];y[i]=b[i];
		}
		if (cnt!=0 && cnt!=n) break;
	}
	printf("%d\n",cnt);
	for (int i=1;i<=n;i++)
	{
		if ((a[i]+b[i])%2==0) printf("%d ",i);
	}
	printf("\n");
	return Accepted;
}