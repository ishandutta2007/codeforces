#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		map<pair<int,int>,int>mp;
		long long ans=0;
		for(;N--;)
		{
			int x,y,u,v;scanf("%d%d%d%d",&x,&y,&u,&v);
			u-=x;
			v-=y;
			int g=abs(gcd(u,v));
			u/=g;
			v/=g;
			ans+=mp[make_pair(u,v)];
			mp[make_pair(-u,-v)]++;
		}
		printf("%lld\n",ans);
	}
}