#include <bits/stdc++.h>
using namespace std;
bool in[300005];
int d[300005];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		for (int j=2*i;j<=n;j+=i)
		d[j]++;
	}
	for (int i=1;i<=n;i++)
	{
		k-=d[i];
		in[i]=1;
		if (k<=0)
		{
			n=i;
			break;
		}
	}
	if (k>0)
	{
		printf("No");
		return 0;
	}
	k*=-1;
	for (int i=1;i<=n;i++)
	{
		if (d[i]==1 && k>=n/i)
		{
			k-=n/i;
			in[i]=0;
		}
	}
	printf("Yes\n%d\n",count(in+1,in+n+1,1));
	for (int i=1;i<=n;i++)
	{
		if (in[i])
		printf("%d ",i);
	}
}