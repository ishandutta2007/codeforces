#include<cstdio>
#define int long long
int n,m,k;
signed main()
{
	int x,y;
	scanf("%lld%lld%lld",&n,&m,&k);
	if(k<n)
	{
		printf("%lld %lld\n",k+1,1ll);
		return 0;
	}
	k-=n;
	x=k/(m-1);
	y=k%(m-1);
	printf("%lld ",n-x);
	if(!(x&1))
		printf("%lld\n",y+2);
	else
		printf("%lld\n",m-y);
	return 0;
}