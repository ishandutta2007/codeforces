#include<cstdio>
#include<algorithm>
using std::min;
using std::max;
const int N=3e5+5;
int n,ans;
int a[N],lp[N],rp[N];
signed main()
{
	int ml,mr;
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		rp[i]=0,lp[i]=n+1;
	for(i=1;i<=n;i++)
		rp[a[i]]=i;
	for(i=n;i>=1;i--)
		lp[a[i]]=i;
	ml=n+1;mr=0;
	for(i=1;i<=n;i++)
		if(rp[i]!=0)
		{
			ans=max(ans,rp[i]-ml);
			ans=max(ans,mr-lp[i]);
			ml=min(ml,lp[i]);
			mr=max(mr,rp[i]);
		}
	printf("%d\n",ans);
	return 0;
}