#include<cstdio>
#include<map>
using namespace std;
int T,N,K;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		map<int,long long>mp;
		long long mx=0;
		for(int i=0;i<N;i++)
		{
			int A;scanf("%d",&A);
			if(A%K==0)continue;
			int t=A/K*K+K-A;
			long long u=t;
			if(mp.find(t)!=mp.end())
			{
				u=mp[t]+K;
			}
			mp[t]=u;
			if(mx<u)mx=u;
		}
		if(mx==0)puts("0");
		else printf("%lld\n",mx+1);
	}
}