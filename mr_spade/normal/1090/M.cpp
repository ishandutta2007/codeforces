#include<cstdio>
#include<algorithm>
using std::max;
const int N=1e6+5;
int n;
int a[N];
signed main()
{
	register int i;
	scanf("%d%*d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int r=1,ans=1;
	for(i=1;i<=n;i++)
	{
		r=max(r,i);
		while(r<n&&a[r+1]!=a[r])
			r++;
		ans=max(ans,r-i+1);
	}
	printf("%d\n",ans);
	return 0;
}