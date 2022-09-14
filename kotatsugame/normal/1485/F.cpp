#include<cstdio>
#include<map>
using namespace std;
const long long mod=1e9+7;
int T,N;
int B[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&B[i]);
		map<long long,long long>mp;
		mp[0]=1;
		long long cumsum=0;
		long long mpsum=1;
		for(int i=0;i<N;i++)
		{
			long long t=mpsum-mp[cumsum];
			t=(t%mod+mod)%mod;
			(mp[cumsum]+=t)%=mod;
			cumsum+=B[i];
			(mpsum+=t)%=mod;
		}
		printf("%lld\n",mpsum);
	}
}