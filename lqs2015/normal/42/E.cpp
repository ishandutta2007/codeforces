#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
long long n,m,pa[111111],ans,dep[111111],an[111111][22],mx[111111][22],q,x,y,num;
pair<long long,pair<long long,long long> > ed[222222];
vector<pair<long long,long long> > g[111111];
long long root(long long x)
{
	if (pa[x]!=x) pa[x]=root(pa[x]);
	return pa[x];
}
bool Union(long long x,long long y)
{
	long long rx=root(x),ry=root(y);
	if (rx==ry) return 0;
	pa[rx]=ry;
	return 1;
}
void dfs(long long i,long long fa,long long vl)
{
	dep[i]=dep[fa]+1;
	an[i][0]=fa;mx[i][0]=vl;
	for (long long j=1;j<=18;j++) 
	{
		an[i][j]=an[an[i][j-1]][j-1];
		mx[i][j]=max(mx[i][j-1],mx[an[i][j-1]][j-1]);
	}
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j].first,val=g[i][j].second;
		if (to==fa) continue;
		dfs(to,i,val);
	}
}
long long get(long long x,long long y)
{
	if (dep[x]<dep[y]) swap(x,y);
	long long ans=0;
	for (long long i=18;i>=0;i--) 
	{
		if (dep[an[x][i]]>=dep[y])
		{
			ans=max(ans,mx[x][i]);
			x=an[x][i];
		}
	}
	if (x==y) return ans;
	for (long long i=18;i>=0;i--)
	{
		if (an[x][i]!=an[y][i])
		{
			ans=max(ans,max(mx[x][i],mx[y][i]));
			x=an[x][i];
			y=an[y][i];
		}
	}
	ans=max(ans,max(mx[x][0],mx[y][0]));
	return ans;
}
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for (long long i=1;i<=m;i++)
	{
		scanf("%I64d%I64d%I64d",&ed[i].second.first,&ed[i].second.second,&ed[i].first);
	}
	sort(ed+1,ed+m+1);
	for (long long i=1;i<=n;i++) pa[i]=i;
	for (long long i=1;i<=m;i++)
	{
		if (Union(ed[i].second.first,ed[i].second.second)) 
		{
			ans+=ed[i].first;
			g[ed[i].second.first].push_back(make_pair(ed[i].second.second,ed[i].first));
			g[ed[i].second.second].push_back(make_pair(ed[i].second.first,ed[i].first));
			num++; 
		}
	}
	dfs(1,0,0);
	scanf("%I64d",&q);
	while(q--)
	{
		scanf("%I64d%I64d",&x,&y);
		if (num<n-2 || (num==n-2 && root(x)==root(y))) printf("-1\n");
		else if (num==n-2) printf("%I64d\n",ans);
		else printf("%I64d\n",ans-get(x,y));
	}
	return 0;
}