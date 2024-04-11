#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int arr[200005],cnt[65];
int main()
{
	int n;
	scanf("%d",&n);
	pair<int,int> mx(0,0);
	for (int i=0;i<n;i++)
	{
		scanf("%I64d",&a[i]);
		for (int j=0;;j++)
		{
			if (a[i]&(1LL<<j))
			{
				arr[i]=j;
				cnt[j]++;
				mx=max(mx,{cnt[j],j});
				break;
			}
		}
	}
	printf("%d\n",n-mx.first);
	for (int i=0;i<n;i++)
	{
		if (arr[i]!=mx.second)
		printf("%I64d ",a[i]);
	}
}