#include<cstdio>
#include<algorithm>
typedef long long ll;
inline void solve()
{
	ll p,q,p2,x,ans=0;
	int k,k2;
	register int i,j;
	scanf("%lld%lld",&q,&p);p2=p;
	for(i=2;i*i<=p;i++)
		if(p2%i==0)
		{
			for(k=0;p2%i==0;p2/=i,k++);
			for(k2=0,x=q;x%i==0;x/=i,k2++);
			for(j=1;j<k&&j<=k2;j++)
				x*=i;
			ans=std::max(ans,x);
		}
	if(p2!=1)
	{
		i=p2;
		for(k=0;p2%i==0;p2/=i,k++);
		for(k2=0,x=q;x%i==0;x/=i,k2++);
		for(j=1;j<k&&j<=k2;j++)
			x*=i;
		ans=std::max(ans,x);
	}
	printf("%lld\n",ans);
	return;
}
signed main()
{
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}