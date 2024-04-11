#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,m,x,cur,ans[222222],a[222222],b[222222],lst;
long long sum;
int main()
{
	scanf("%d%d",&n,&m);cur=n;
	for (int i=1;i<=m;i++) 
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if (sum<n)
	{
		printf("-1\n");
		return 0;
	}
	lst=n;
	for (int i=1;i<=m;i++)
	{
		if (lst<a[i])
		{
			printf("-1\n");
			return 0;
		}
		b[i]=min((long long)a[i],max(1ll,lst-(sum-a[i])));
		lst-=b[i];sum-=a[i];
		if (lst<0 || lst>sum)
		{
			printf("-1\n");
			return 0;
		}
	}
	lst=n;
	for (int i=1;i<=m;i++)
	{
		ans[i]=lst-a[i]+1;
		lst-=b[i];
	}
	for (int i=1;i<=m;i++) printf("%d ",ans[i]);
	printf("\n");
	return Accepted;
}