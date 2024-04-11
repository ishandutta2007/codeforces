#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#include<cassert>
using namespace std;
int n,sz,cnt,x,beg[444444],en[444444],ct,bit[888888],ctt,ans[444444],pos,fuck[444444];
pair<pair<int,int>,pair<int,int> > event[888888];
vector<pair<int,long long> > g[222222];
map<long long,int> mp;
long long dep[222222],s[888888],a[222222],y;
void dfs(int i)
{
	beg[i]=++ct;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first;long long val=g[i][j].second;
		dep[to]=dep[i]+val;
		dfs(to);
	}
	en[i]=ct;
}
void update(int p)
{
	while(p<=sz)
	{
		bit[p]++;
		p+=p&(-p);
	}
}
int query(int p)
{
	int res=0;
	while(p>=1)
	{
		res+=bit[p];
		p-=p&(-p);
	}
	return res;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for (int i=2;i<=n;i++)
	{
		scanf("%d%I64d",&x,&y);
		g[x].push_back(make_pair(i,y)); 
	}
	dfs(1);
	for (int i=1;i<=n;i++)
	{
		s[++cnt]=dep[i];
		s[++cnt]=dep[i]-a[i];
	}
	sz=1;
	while(sz<cnt) sz*=2;
	sort(s+1,s+cnt+1);
	cnt=unique(s+1,s+cnt+1)-s-1;
	for (int i=1;i<=cnt;i++)
	{
		mp[s[i]]=i;
	}
	for (int i=1;i<=n;i++)
	{
		fuck[beg[i]]=mp[dep[i]-a[i]];
		event[++ctt]=make_pair(make_pair(beg[i],mp[dep[i]]),make_pair(i,-1));
		event[++ctt]=make_pair(make_pair(en[i],mp[dep[i]]),make_pair(i,1));
	}
	sort(event+1,event+ctt+1);
	pos=1;
	for (int i=1;i<=ctt;i++)
	{
		while(pos<=event[i].first.first) 
		{
			update(fuck[pos]);
			pos++;
		}
		ans[event[i].second.first]+=event[i].second.second*query(event[i].first.second);
	}
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}