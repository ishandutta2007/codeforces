#include <iostream>
using namespace std;
int arr[200005],last[200005];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
		if (arr[i]>1)
		last[i]=i;
		else
		last[i]=last[i-1];
	}
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		long long p=1,s=0;
		int cur=i;
		while (cur)
		{
			if ((1LL<<61)/arr[cur]<p)
			break;
			p*=arr[cur];
			s+=arr[cur];
			if (p%k==0)
			{
				long long ns=p/k;
				if (cur-last[cur-1]-1>=ns-s && s<=ns)
				ans++;
			}
			s+=cur-last[cur-1]-1;
			cur=last[cur-1];
		}
	}
	printf("%d",ans);
}