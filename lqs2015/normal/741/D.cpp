#include<bits/stdc++.h>
using namespace std;
int n,x,mxdep[4444444],dep[1111111],rt[1111111],wson[1111111],sub[1111111],ans[1111111];
char c;
vector<pair<int,int> > g[1111111],nv;
vector<int> v;
void Init(int i,int fa)
{
	sub[i]=1;dep[i]=dep[fa]+1;
	int mx=0,mxi=0;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first,val=g[i][j].second;
		rt[to]=rt[i]^val;
		Init(to,i);
		if (sub[to]>mx)
		{
			mx=sub[to];
			mxi=to;
		}
		sub[i]+=sub[to];
	}
	wson[i]=mxi; 
}
void get(int i,int fa,int id)
{
	if (mxdep[rt[i]]) ans[id]=max(ans[id],mxdep[rt[i]]+dep[i]-2*dep[id]);
	for (int j=0;j<22;j++)
	{
		if (mxdep[rt[i]^(1<<j)]) ans[id]=max(ans[id],mxdep[rt[i]^(1<<j)]+dep[i]-2*dep[id]);
	}
	nv.push_back(make_pair(rt[i],dep[i]));
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first;
		if (to==fa) continue;
		get(to,i,id);
	}
}
void dfs(int i,int fa,bool f)
{
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first;
		if (to==fa || to==wson[i]) continue;
		dfs(to,i,0);
		ans[i]=max(ans[i],ans[to]);
	}
	if (wson[i]) 
	{
		dfs(wson[i],i,1);
		ans[i]=max(ans[i],ans[wson[i]]);
	}
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first;
		if (to==fa || to==wson[i]) continue;
		nv.clear();
		get(to,i,i); 
		for (int k=0;k<nv.size();k++)
		{
			v.push_back(nv[k].first);
			mxdep[nv[k].first]=max(mxdep[nv[k].first],nv[k].second); 
		}
	}
	if (mxdep[rt[i]]) ans[i]=max(ans[i],mxdep[rt[i]]-dep[i]);
	for (int j=0;j<22;j++) 
	{
		if (mxdep[rt[i]^(1<<j)]) ans[i]=max(ans[i],mxdep[rt[i]^(1<<j)]-dep[i]);
	}
	v.push_back(rt[i]);
	mxdep[rt[i]]=max(mxdep[rt[i]],dep[i]); 
	if (!f)
	{
		for (int j=0;j<v.size();j++) mxdep[v[j]]=0;
		v.clear();
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
	{
		scanf("%d %c",&x,&c);
		g[x].push_back(make_pair(i,(1<<(c-'a'))));
	}
	Init(1,0);
	dfs(1,0,1);
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}