#include<cstdio>
#include<algorithm>
#define int long long
using std::max;
using std::min;
using std::sort;
const int N=1005;
int n,h;
int a[N];
signed main()
{
	int res,cur;
	register int i,j;
	scanf("%lld%lld",&n,&h);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(i=1;i<=n;i++)
	{
		sort(a+1,a+i+1);res=0x3f3f3f3f3f3f3f3f;
		cur=0;
		for(j=2;j<=i;j+=2)
			cur+=max(a[j-1],a[j]);
		if(i&1)
			cur+=a[i];
		res=min(res,cur);
		cur=0;
		for(j=i;j>=2;j-=2)
			cur+=max(a[j-1],a[j]);
		if(i&1)
			cur+=a[1];
		res=min(res,cur);
		if(cur>h)
			return printf("%lld\n",i-1),0;
	}
	printf("%lld\n",n);
	return 0;
}