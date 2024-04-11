#include<cstdio>
#include<map>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		long long ans=0;
		map<int,int>mp;
		for(int i=0;i<N;i++)
		{
			int A;scanf("%d",&A);
			A-=i;
			ans+=mp[A]++;
		}
		printf("%lld\n",ans);
	}
}