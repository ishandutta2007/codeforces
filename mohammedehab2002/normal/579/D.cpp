#include <iostream>
using namespace std;
int cnt[61];
long long arr[200005],cur,ans;
int main()
{
	int n,k,x;
	scanf("%d%d%d",&n,&k,&x);
	for (int i=0;i<n;i++)
	{
		scanf("%I64d",&arr[i]);
		for (int j=0;j<=60;j++)
		{
			if (arr[i]&(1LL<<j))
			cnt[j]++;
		}
		cur|=arr[i];
	}
	int p=1;
	for (int i=0;i<k;i++)
	p*=x;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<=60;j++)
		{
			if (arr[i]&(1LL<<j))
			{
				cnt[j]--;
				if (!cnt[j])
				cur^=(1LL<<j);
			}
		}
		ans=max(ans,cur|(arr[i]*p));
		for (int j=0;j<=60;j++)
		{
			if (arr[i]&(1LL<<j))
			{
				cnt[j]++;
				if (cnt[j]==1)
				cur^=(1LL<<j);
			}
		}
	}
	printf("%I64d",ans);
}