#include<cstdio>
#include<algorithm>
#define int long long
using std::sort;
signed main()
{
	int t,a[4],p[4],a1,b1;
	register int i;
	for(i=1;i<=3;i++)
		scanf("%lld",&a[i]);
	puts("First");fflush(stdout);
	puts("10000000000");fflush(stdout);
	scanf("%lld",&t);
	if(t==0)
		return 0;
	a[t]+=10000000000ll;
	for(i=1;i<=3;i++)
		p[i]=i;
	sort(p+1,p+4,[&](int x,int y)->bool
	{
		return a[x]<a[y];
	});
	a1=a[p[2]]-a[p[1]];b1=a[p[3]]-a[p[2]];
	printf("%lld\n",a1+2*b1);fflush(stdout);
	scanf("%lld",&t);
	if(t==0)
		return 0;
	a[t]+=a1+2*b1;
	sort(p+1,p+4,[&](int x,int y)->bool
	{
		return a[x]<a[y];
	});
	a1=a[p[2]]-a[p[1]];b1=a[p[3]]-a[p[2]];
	printf("%lld\n",a1);fflush(stdout);
	scanf("%lld",&t);
	if(t==0)
		return 0;
	throw;
}