#include<iostream>
#include<cstdio>
using namespace std;
long long a[111111],n,mk,ans,mn[111111];
int main()
{
	scanf("%I64d",&n);
	for (long long i=1;i<=n;i++) scanf("%I64d",&a[i]);
	mn[n]=0;
	for (int i=n-1;i>=1;i--)
	{
		mn[i]=max(a[i+1],mn[i+1]-1);
	}
	mn[1]=max(1ll,mn[1]);
	for (long long i=1;i<=n;i++)
	{
		if (mk<mn[i])
		{
			ans+=(mk-a[i]);
			mk++;
		}
		else if (mk==a[i])
		{
			mk++;
		}
		else 
		{
			ans+=(mk-1-a[i]);
		}
	}
	printf("%I64d\n",ans);
	return 0;
}