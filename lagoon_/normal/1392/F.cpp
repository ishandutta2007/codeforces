#include<bits/stdc++.h>
#define re register
long long h[1001000];
int main()
{
	re int n;
	re long long ans=0;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)
	{
		scanf("%lld",&h[i]);
		ans+=h[i];
	}
	re long long l=0,r=ans/n,mid;
	for(mid=(l+r+1)/2;l<r;mid=(l+r+1)/2)
	{
		if((2*mid+n-1)*n/2>ans)r=mid-1;
		else l=mid;
	}
	ans-=(2*mid+n-1)*n/2;
	for(re int i=1;i<=n;i++)h[i]=l+i-1;
	for(re int i=1;i<=ans;i++)h[i]++;
	for(re int i=1;i<=n;i++)printf("%lld ",h[i]);puts("");
}