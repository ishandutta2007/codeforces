#include<bits\stdc++.h>
using namespace std;
long long a[111111],b[111111];
long long n,p[111111],k,suma,sumb,cnt;
int main()
{
	scanf("%I64d",&n);
	k=n/2+1;
	for (int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		suma+=a[i];
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%I64d",&b[i]);
		sumb+=b[i];
	}
	for (int i=1;i<=n;i++) p[i]=i;
	for (int i=1;i<=1000;i++)
	{
		random_shuffle(p+1,p+n+1);
		bool f=0;cnt=0;
		for (int j=1;j<=k;j++)
		{
			cnt+=a[p[j]];
		}
		if (2*cnt<=suma) f=1;
		cnt=0;
		for (int j=1;j<=k;j++)
		{
			cnt+=b[p[j]];
		}
		if (2*cnt<=sumb) f=1;
		if (!f)
		{
			printf("%I64d\n",k);
			for (int j=1;j<=k;j++)
			{
				printf("%I64d ",p[j]);
			}
			printf("\n");
			return 0;
		}
	}
	return 0;
}