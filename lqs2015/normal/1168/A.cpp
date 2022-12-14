#include<bits/stdc++.h>
using namespace std;
int n,m,a[333333],l,r,mid,pre,fake;
bool check(int mid)
{
	pre=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]+mid<m)
		{
			if (a[i]>=pre)
			{
				pre=a[i];
				continue;
			}
			if (a[i]+mid<pre) return 0;
		}
		else
		{
			fake=(a[i]+mid)%m;
			if (a[i]>=pre)
			{
				if (fake>=pre) continue;
				pre=a[i];
				continue;
			}
			else 
			{
				continue;
			}
		}
	}
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	l=0;r=m;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if (check(mid)) r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}