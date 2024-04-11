#include<cstdio>
#include<map>
using namespace std;
int N,M;
map<pair<int,int>,char>mp;
int c0,c1;
main()
{
	scanf("%d%d",&N,&M);
	for(;M--;)
	{
		char c;scanf(" %c",&c);
		if(c=='+')
		{
			int u,v;
			scanf("%d%d %c",&u,&v,&c);
			mp[make_pair(u,v)]=c;
			if(mp.find(make_pair(v,u))!=mp.end())
			{
				if(mp[make_pair(v,u)]==c)c0++;
				else c1++;
			}
		}
		else if(c=='-')
		{
			int u,v;
			scanf("%d%d",&u,&v);
			c=mp[make_pair(u,v)];
			mp.erase(make_pair(u,v));
			if(mp.find(make_pair(v,u))!=mp.end())
			{
				if(mp[make_pair(v,u)]==c)c0--;
				else c1--;
			}
		}
		else
		{
			int k;scanf("%d",&k);
			puts(c0?"YES":c1&&k&1?"YES":"NO");
		}
	}
}