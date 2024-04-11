#include<bits/stdc++.h>
using namespace std;
long long g[44],pw[44],t,n,k,ans,pw2[44],gg,ind;
int main()
{
	pw[0]=pw2[0]=1;
	for (int i=1;i<=31;i++) pw[i]=pw[i-1]*4ll;
	for (int i=1;i<=31;i++) pw2[i]=pw2[i-1]*2ll;
	for (int i=1;i<=31;i++) 
	{
		g[i]=g[i-1]+pw[i-1];
	}
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		ans=-1;
		for (long long i=1;i<=30 && i<=n;i++)
		{
			if (pw2[i+1]-2-i>k) break;
			gg=k-g[i];ind=(pw2[i]-1)*(pw2[i]-1);
			if (n-i>30 || gg<0 || g[n-i]>=(gg+ind-1)/ind) 
			{
				ans=n-i;
				break;
			}
		}
		if (!~ans) printf("NO\n");
		else printf("YES %d\n",ans);
	}
	return 0;
}