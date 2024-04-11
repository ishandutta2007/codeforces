#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;
struct dat{
	map<int,int>cnt;
	map<int,pair<long long,set<int> > >inv;
	dat(){}
	dat(int c)
	{
		cnt[c]=1;
		inv[1]=make_pair(c,set<int>{c});
	}
	void swap(dat&rhs)
	{
		cnt.swap(rhs.cnt);
		inv.swap(rhs.inv);
	}
	void add(dat&rhs)
	{
		if(cnt.size()<rhs.cnt.size())swap(rhs);
		for(pair<int,int>p:rhs.cnt)
		{
			if(cnt.find(p.first)==cnt.end())
			{
				cnt[p.first]=p.second;
				inv[p.second].first+=p.first;
				inv[p.second].second.insert(p.first);
			}
			else
			{
				int prv=cnt[p.first];
				cnt[p.first]+=p.second;
				inv[prv].first-=p.first;
				inv[prv].second.erase(p.first);
				int now=prv+p.second;
				inv[now].first+=p.first;
				inv[now].second.insert(p.first);
			}
		}
	}
};
vector<int>G[1<<17];
int c[1<<17];
long long ans[1<<17];
dat tmp;
void dfs(int u,int p)
{
	dat now(c[u]);
	for(int v:G[u])if(v!=p)
	{
		dfs(v,u);
		now.add(tmp);
	}
	ans[u]=now.inv.rbegin()->second.first;
	tmp.swap(now);
}
main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&c[i]);
	for(int i=1;i<N;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(0,-1);
	for(int i=0;i<N;i++)printf("%lld%c",ans[i],i+1==N?10:32);
}