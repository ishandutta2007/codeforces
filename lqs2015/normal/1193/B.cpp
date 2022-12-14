#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z,t[111111],val[111111],cur,lst,pos;
vector<int> g[111111];
multiset<pair<int,int> > s[111111];
multiset<pair<int,int> >::iterator it,itt;
long long ans;
void dfs(int i)
{
	int mxp=-1,mx=0;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		dfs(to);
		if (s[to].size()>mx)
		{
			mx=s[to].size();
			mxp=to;
		}
	}
	if (!~mxp)
	{
		if (t[i]<=1000000000) s[i].insert(make_pair(t[i],val[i]));
		return;
	}
	swap(s[i],s[mxp]);
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==mxp) continue;
		for (it=s[to].begin();it!=s[to].end();it++)
		{
			s[i].insert(*it);
		}
	}
	if (t[i]>1000000000) return;
	cur=val[i];
	s[i].insert(make_pair(t[i],val[i]));
	it=s[i].lower_bound(make_pair(t[i]+1,0));itt=it;lst=0;
	for (;itt!=s[i].end();itt++)
	{
		int cp=itt->second;
		if (cp>=cur)
		{
			lst=cp-cur;pos=itt->first;itt++;
			break;
		}
		else cur-=cp;
	}
	s[i].erase(it,itt);
	if (lst) s[i].insert(make_pair(pos,lst));
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&x);
		g[x].push_back(i);
	} 
	for (int i=1;i<=n;i++) t[i]=2e9;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		t[x]=y;val[x]=z;
	}
	dfs(1);
	for (it=s[1].begin();it!=s[1].end();it++) 
	{
		ans+=(it->second);
	}
	printf("%lld\n",ans);
	return 0;
}