#include<cstdio>
#include<algorithm>
#define int long long
using std::sort;
inline int abs(int x)
{
	return x<0?-x:x;
}
const int N=1005;
int n,k1,k2;
int ans;
int a[N],b[N],c[N];
inline bool cmp(int x,int y)
{
	return abs(x)>abs(y);
}
signed main()
{
	scanf("%lld%lld%lld",&n,&k1,&k2);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++)
		c[i]=abs(a[i]-b[i]),ans+=c[i]*c[i];
	for(int i=1;i<=k1+k2;i++)
	{
		sort(c+1,c+n+1,cmp);
		ans-=c[1]*c[1];
		c[1]=abs(c[1]-1);
		ans+=c[1]*c[1];
	}
	printf("%lld\n",ans);
	return 0;
}