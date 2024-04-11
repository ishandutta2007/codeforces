#include<cstdio>
#include<map>
using namespace std;
long long n,p,k,a,ans;
main()
{
	scanf("%lld%lld%lld",&n,&p,&k);
	map<long long,int>M;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a);
		ans+=M[(a*a%p*a%p*a%p-k*a%p+p)%p]++;
	}
	printf("%lld\n",ans);
}