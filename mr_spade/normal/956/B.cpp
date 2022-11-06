#include<cstdio>
#include<algorithm>
#define int long long
using std::upper_bound;
const int N=2e5+5;
const double eps=1e-12;
int n,u;
double ans=-1;
int e[N];
signed main()
{
	register int i,k;
	scanf("%lld%lld",&n,&u);
	for(i=1;i<=n;i++)
		scanf("%lld",&e[i]);
	for(i=1;i<=n;i++)
	{
		k=upper_bound(e+1,e+n+1,u+e[i])-e;k--;
		if(k<i+2)
			continue;
		if((double)(e[k]-e[i+1])/(e[k]-e[i])>ans)
			ans=(double)(e[k]-e[i+1])/(e[k]-e[i]);
	}
	if(ans==-1)
		return puts("-1"),0;
	printf("%.12lf\n",ans);
	return 0;
}