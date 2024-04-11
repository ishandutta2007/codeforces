#include<bits/stdc++.h>
using namespace std;
int n,x[111111],d[111111],st[111111],top,l,r,mid;
long long dp1[111111],dp2[111111],val[111111],v1[111111],v2[111111],ans;
double res;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n+2;i++) scanf("%d",&x[i]);
	d[1]=d[n+2]=1e9;
	for (int i=2;i<=n+1;i++) scanf("%d",&d[i]);
	dp1[1]=1e18;
	st[top=1]=1;val[1]=4e18;
	for (int i=2;i<=n+2;i++)
	{
		l=1;r=top;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if (val[mid]<x[i]) r=mid-1;
			else l=mid+1;
		}
		if (!r) dp1[i]=-1e18;
		else
		{
			dp1[i]=x[st[r]];
		}
		while(top && val[top]<=dp1[i]+2ll*d[i]) top--;
		top++;st[top]=i;val[top]=dp1[i]+2ll*d[i];
	}
	st[top=1]=n+2;val[1]=-4e18;dp2[n+2]=-1e18;
	for (int i=n+1;i>=1;i--)
	{
		l=1;r=top;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if (val[mid]>x[i]) r=mid-1;
			else l=mid+1;
		}
		if (!r) dp2[i]=1e18;
		else dp2[i]=x[st[r]];
		while(top && val[top]>=dp2[i]-2ll*d[i]) top--;
		top++;st[top]=i;val[top]=dp2[i]-2ll*d[i];
	}
	for (int i=1;i<=n+2;i++)
	{
		v1[i]=2ll*d[i]-(x[i]-dp1[i]);
		v2[i]=2ll*d[i]-(dp2[i]-x[i]);
		if (v1[i]<=0) v1[i]=-1e18;
		if (v2[i]<=0) v2[i]=-1e18;
	}
	st[top=1]=1;val[1]=x[1]+v1[1];
	ans=1e18;
	for (int i=2;i<=n+2;i++)
	{
		l=1;r=top;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if (1ll*x[i]-v2[i]<=val[mid]) l=mid+1;
			else r=mid-1; 
		}
		if (r && v2[i]>0) ans=min(ans,(long long)x[i]-x[st[r]]);
		if (v1[i]>0)
		{
			while(top && v1[i]+x[i]>=val[top]) top--;
			top++;st[top]=i;val[top]=v1[i]+x[i]; 
		}
	}
	for (int i=2;i<=n+1;i++)
	{
		if (dp2[i]-dp1[i]<=2*d[i]) ans=0;
	}
	if (ans&1) printf("%lld.5\n",ans/2);
	else printf("%lld\n",ans/2);
	return 0;
}