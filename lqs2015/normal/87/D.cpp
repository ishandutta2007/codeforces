#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
long long n,pa[111111],sum[111111],par[111111],res[111111],pos,en,s,rx,ry,a[111111];
vector<long long> g[111111],v,p;
map<pair<long long,long long>,long long> mp;
struct edge
{
	long long x,y,w,id;
	bool operator < (const edge &a) const
	{
		return w<a.w;
	}
}e[111111];
long long root(long long x)
{
	if (pa[x]!=x) pa[x]=root(pa[x]);
	return pa[x];
}
void Union(long long x,long long y)
{
	long long rx=root(x),ry=root(y);
	if (rx==ry) return;
	pa[rx]=ry;
	sum[ry]+=sum[rx];
}
void dfs1(long long i,long long fa)
{
	s+=a[i];
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j];
		if (to!=fa) dfs1(to,i);
	}
}
void dfs2(long long i,long long fa)
{
	par[i]=a[i];
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j];
		if (to==fa) continue;
		dfs2(to,i);
		par[i]+=par[to];
		mp[make_pair(i,to)]=2*par[to]*(s-par[to]);
		mp[make_pair(to,i)]=2*par[to]*(s-par[to]);
	}
}
int main()
{
	scanf("%I64d",&n);
	for (long long i=1;i<=n;i++)
	{
		pa[i]=i;
		sum[i]=1;
	}
	for (long long i=1;i<n;i++)
	{
		scanf("%I64d%I64d%I64d",&e[i].x,&e[i].y,&e[i].w);
		e[i].id=i;
	}
	sort(e+1,e+n);
	for (pos=1;pos<n;)
	{
		for (en=pos;en<n;en++)
		{
			if (e[en].w!=e[pos].w) break;
		}
		v.clear();mp.clear();
		for (long long i=pos;i<en;i++)
		{
			rx=root(e[i].x);ry=root(e[i].y);
			v.push_back(rx);
			v.push_back(ry);
			g[rx].push_back(ry);
			g[ry].push_back(rx);
			a[rx]=sum[rx];
			a[ry]=sum[ry];
			par[rx]=par[ry]=-1;
		}
		for (long long i=0;i<v.size();i++)
		{
			if (par[v[i]]==-1)
			{
				s=0;
				dfs1(v[i],0);
				dfs2(v[i],0);
			}
		}
		for (long long i=pos;i<en;i++)
		{
			rx=root(e[i].x);ry=root(e[i].y);
			res[e[i].id]=mp[make_pair(rx,ry)];
		}
		for (long long i=pos;i<en;i++)
		{
			Union(e[i].x,e[i].y);
		}
		for (long long i=0;i<v.size();i++)
		{
			g[v[i]].clear();
		}
		pos=en;
	}
	long long mx=0,cnt=0;
	for (long long i=1;i<n;i++)
	{
		if (res[i]>mx) mx=res[i];
	}
	for (long long i=1;i<n;i++)
	{
		if (res[i]==mx) cnt++;
	}
	printf("%I64d %I64d\n",mx,cnt);
	for (long long i=1;i<n;i++)
	{
		if (res[i]==mx) printf("%I64d ",i);
	}
	return 0;
}