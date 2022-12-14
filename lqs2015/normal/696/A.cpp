#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int q,du,dv,tp;
long long u,v,w,ans;
map<long long,long long> mp;
int getdep(long long x)
{
	int res=0;long long p=1;
	while(p<=x)
	{
		p*=2;
		res++;
	}
	return res;
}
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&tp);
		if (tp==1)
		{
			scanf("%lld %lld %lld",&u,&v,&w);
			du=getdep(u);dv=getdep(v);
			if (du<dv) 
			{
				swap(du,dv);
				swap(u,v);
			}
			while(du>dv)
			{
				mp[u]+=w;
				u>>=1;du--;
			}
			while(u!=v)
			{
				mp[u]+=w;u>>=1;
				mp[v]+=w;v>>=1;
			}
		}
		else
		{
			scanf("%lld %lld",&u,&v);
			ans=0;
			du=getdep(u);dv=getdep(v);
			if (du<dv) 
			{
				swap(du,dv);
				swap(u,v);
			}
			while(du>dv)
			{
				ans+=mp[u];
				u>>=1;du--;
			}
			while(u!=v)
			{
				ans+=mp[u];u>>=1;
				ans+=mp[v];v>>=1;
			}
			printf("%lld\n",ans);
		}
	}
	return Accepted;
}