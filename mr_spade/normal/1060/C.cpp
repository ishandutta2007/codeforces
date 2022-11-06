#include<cstdio>
#define int long long
const int N=2005;
int n,m;
int a[N],b[N];
int mna[N],mnb[N];
int x,ans;
signed main()
{
	int cur;
	register int i,j;
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]),mna[i]=0x3f3f3f3f;
	for(i=1;i<=m;i++)
		scanf("%lld",&b[i]),mnb[i]=0x3f3f3f3f;
	scanf("%lld",&x);
	for(i=1;i<=n;i++)
	{
		cur=0;
		for(j=i;j<=n;j++)
		{
			cur+=a[j];
			if(cur<mna[j-i+1])
				mna[j-i+1]=cur;
		}
	}
	for(i=1;i<=m;i++)
	{
		cur=0;
		for(j=i;j<=m;j++)
		{
			cur+=b[j];
			if(cur<mnb[j-i+1])
				mnb[j-i+1]=cur;
		}
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(mna[i]*mnb[j]<=x)
				if(i*j>ans)
					ans=i*j;
	printf("%lld\n",ans);
	return 0;
}