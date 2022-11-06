#include<cstdio>
#include<algorithm>
using std::lower_bound;
typedef long long ll;
const int N=1e5+5;
int n,m,ans;
ll a[N],b[N];
signed main()
{
	register int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]),a[i]+=a[i-1];
	for(i=1;i<=m;i++)
		scanf("%lld",&b[i]),b[i]+=b[i-1];
	for(i=1;i<=n;i++)
		if(*lower_bound(b+1,b+m+1,a[i])==a[i])
			ans++;
	printf("%d\n",ans);
	return 0;
}