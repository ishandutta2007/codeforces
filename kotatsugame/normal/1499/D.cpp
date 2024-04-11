#include<cstdio>
using namespace std;
const int LIM=2e7;
int mp[LIM+1];
int cnt[LIM+1];
int T;
main()
{
	for(int i=2;i<=LIM;i++)if(mp[i]==0)
	{
		mp[i]=i;
		for(int j=i+i;j<=LIM;j+=i)mp[j]=i;
	}
	for(int i=2;i<=LIM;i++)
	{
		int k=mp[i];
		int u=i;
		while(u%k==0)u/=k;
		cnt[i]=cnt[u]+1;
	}
	scanf("%d",&T);
	for(;T--;)
	{
		int c,d,x;
		scanf("%d%d%d",&c,&d,&x);
		long long ans=0;
		for(int g=1;g*g<=x;g++)if(x%g==0)
		{
			if((x/g+d)%c==0)
			{
				ans+=1LL<<cnt[(x/g+d)/c];
			}
			if(g<x/g)
			{
				int h=x/g;
				if((x/h+d)%c==0)
				{
					ans+=1LL<<cnt[(x/h+d)/c];
				}
			}
		}
		printf("%lld\n",ans);
	}
}