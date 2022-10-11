#include <iostream>
using namespace std;
int idx[1000005];
bool b[1000005];
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	while (m--)
	{
		int a;
		scanf("%d",&a);
		b[a]=1;
	}
	if (b[0])
	{
		printf("-1");
		return 0;
	}
	for (int i=0;i<=n;i++)
	{
		if (b[i])
		idx[i]=idx[i-1];
		else
		idx[i]=i;
	}
	long long res=(1LL<<60);
	for (int i=1;i<=k;i++)
	{
		int c;
		scanf("%d",&c);
		int cur=0;
		long long ans=0;
		while (cur<n)
		{
			if (cur+i<n && cur==idx[cur+i])
			{
				ans=(1LL<<60);
				break;
			}
			if (cur+i<n)
			cur=idx[cur+i];
			else
			cur+=i;
			ans+=c;
		}
		res=min(res,ans);
	}
	if (res==(1LL<<60))
	res=-1;
	printf("%I64d",res);
}