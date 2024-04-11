#include<bits/stdc++.h>
using namespace std;
int test,n,a[444444],l,r,mid;
long long ll,rr;
bool check()
{
	ll=0;rr=1e9;
	for (int i=1;i<=n;i++)
	{
		if (a[i]==-1)
		{
			if (i-1 && a[i-1]!=-1)
			{
				ll=max(ll,1ll*a[i-1]-mid);
				rr=min(rr,1ll*a[i-1]+mid);
			}
			if (i+1<=n && a[i+1]!=-1)
			{
				ll=max(ll,1ll*a[i+1]-mid);
				rr=min(rr,1ll*a[i+1]+mid);
			}
		}
		if (i-1 && a[i]!=-1 && a[i-1]!=-1)
		{
			if (abs(a[i]-a[i-1])>mid) return 0;
		}
	}
	return (ll<=rr);
}
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		l=0;r=2e9;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if (check()) r=mid-1;
			else l=mid+1;
		}
		mid=l;
		check();
		printf("%d %lld\n",l,ll);
	}
	return 0;
}