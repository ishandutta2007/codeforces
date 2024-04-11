#include<cstdio>
#include<algorithm>
using std::max;
using std::sort;
using std::upper_bound;
const int N=105;
int n,d;
int a[N];
signed main()
{
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,upper_bound(a+1,a+n+1,a[i]+d)-(a+i));
	printf("%d\n",n-ans);
	return 0;
}