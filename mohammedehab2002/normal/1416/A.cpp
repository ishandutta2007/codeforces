#include <bits/stdc++.h>
using namespace std;
int l[300005],ll[300005],ans[300005];
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n;
		scanf("%d",&n);
		for (int i=0;i<=n;i++)
		{
			l[i]=-1;
			ll[i]=0;
			ans[i]=1e9;
		}
		for (int i=0;i<n;i++)
		{
			int a;
			scanf("%d",&a);
			ll[a]=max(ll[a],i-l[a]-1);
			l[a]=i;
		}
		for (int i=1;i<=n;i++)
		ll[i]=max(ll[i],n-l[i]-1);
		for (int i=1;i<=n;i++)
		ans[ll[i]+1]=min(ans[ll[i]+1],i);
		for (int i=1;i<=n;i++)
		{
			ans[i]=min(ans[i],ans[i-1]);
			if (ans[i]==1e9)
			printf("-1 ");
			else
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
}