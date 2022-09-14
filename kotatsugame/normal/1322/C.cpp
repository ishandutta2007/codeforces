#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
int T,N,M;
long long C[5<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++)scanf("%lld",&C[i]);
		vector<pair<vector<int>,int> >E(N);
		for(int i=0;i<N;i++)E[i].second=i;
		for(int i=0;i<M;i++)
		{
			int u,v;scanf("%d%d",&u,&v);
			u--,v--;
			E[v].first.push_back(u);
		}
		for(int i=0;i<N;i++)
		{
			sort(E[i].first.begin(),E[i].first.end());
		}
		sort(E.begin(),E.end());
		long long ans=0;
		for(int i=0;i<N;)
		{
			if(E[i].first.empty())
			{
				i++;
				continue;
			}
			long long sum=C[E[i].second];
			i++;
			while(i<N&&E[i-1].first==E[i].first)
			{
				sum+=C[E[i].second];
				i++;
			}
			ans=gcd(ans,sum);
		}
		printf("%lld\n",ans);
	}
}