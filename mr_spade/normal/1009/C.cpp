#include<cstdio>
#define int long long
int n,m,ans;
int x,d;
signed main()
{
	int i;
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&x,&d);
		if(d>=0)
			ans+=x*n+(n-1)*n/2*d;
		else
			ans+=x*n+((n>>1)*((n>>1)+1)/2+((n-1)>>1)*(((n-1)>>1)+1)/2)*d;
	}
	printf("%.8lf\n",(double)ans/n);
	return 0;
}