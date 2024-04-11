#include<cstdio>
#include<algorithm>
#define int long long
using std::min;
using std::max;
using std::sort;
const int N=2e5+5;
int n,a,b,ans,ans1;
int hp[N],dmg[N],v[N];
int p[N],rank[N];
inline bool cmp(int x,int y)
{
	return v[x]>v[y];
}
signed main()
{
	register int i;
	scanf("%lld%lld%lld",&n,&a,&b);
	b=min(b,n);
	for(i=1;i<=n;i++)
		p[i]=i,scanf("%lld%lld",&hp[i],&dmg[i]),v[i]=hp[i]-dmg[i];
	sort(p+1,p+n+1,cmp);
	for(i=1;i<=n;i++)
		rank[p[i]]=i;
	for(i=1;i<=n;i++)
		ans+=dmg[i];
	for(i=1;i<=min(n,b);i++)
	{
		if(v[p[i]]<=0)
			break;
		ans+=v[p[i]];
	}
	if(!b)
	{
		printf("%lld\n",ans);
		return 0;
	}
	ans1=ans;
	for(i=1;i<=n;i++)
		if(rank[i]<=b)
		{
			if(ans+(hp[i]*(1<<a)-dmg[i])-max(v[i],0ll)>ans1)
				ans1=ans+(hp[i]*(1<<a)-dmg[i])-max(v[i],0ll);
		}
		else
		{
			if(ans+(hp[i]*(1<<a)-dmg[i])-max(v[p[b]],0ll)>ans1)
				ans1=ans+(hp[i]*(1<<a)-dmg[i])-max(v[p[b]],0ll);
		}
	printf("%lld\n",ans1);
	return 0;
}