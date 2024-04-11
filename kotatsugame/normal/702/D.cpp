#include<cstdio>
#include<algorithm>
using namespace std;
long long d,k,a,b,t;
main()
{
	scanf("%lld%lld%lld%lld%lld",&d,&k,&a,&b,&t);
	long long ans=min(min(d,k)*a+max(d-k,0LL)*b,d*a+d/k*t);
	long long r=d/k-1;
	if(r>=0&&t+(a-b)*k<0)ans=min(ans,d*b+k*(a-b)+r*(t+(a-b)*k));
	printf("%lld\n",ans);
}