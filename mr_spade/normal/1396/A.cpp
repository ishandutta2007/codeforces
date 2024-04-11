#include<cstdio>
#define int long long
int exgcd(int &a,int &b,int x,int y)
{
	if(!x)
		return a=0,b=1,y;
	int g=exgcd(b,a,y%x,x);
	return a-=(y/x)*b,g;
}
const int N=1e5+5;
int n,x,y;
int a[N];
signed main()
{
	register int i;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	if(n==1)
	{
		printf("1 1\n0\n1 1\n0\n1 1\n%lld\n",-a[1]);
		return 0;
	}
	exgcd(x,y,n,n-1);
	//x*n+y*(n-1)=1
	printf("%lld %lld\n",1ll,n);
	for(i=1;i<n;i++)
		printf("%lld ",-x*n*a[i]);
	puts("0");
	printf("%lld %lld\n",1ll,n-1);
	for(i=1;i<n;i++)
		printf("%lld ",-y*(n-1)*a[i]);
	puts("");
	printf("%lld %lld\n",n,n);
	printf("%lld\n",-a[n]);
	return 0;
}