#include<bits/stdc++.h>
using namespace std;
long long col[111111],n,x,y,sub[111111],cnt,wson[111111],ans[111111],sum[111111],nw,mx;
vector<long long> g[111111];
bool used[111111];
void Init(long long i,long long fa)
{
	sub[i]=1;
	long long mx=0,mxi=0;
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j];
		if (to==fa) continue;
		Init(to,i);
		if (mx<sub[to])
		{
			mx=sub[to];
			mxi=to;
		}
		sub[i]+=sub[to];
	}
	wson[i]=mxi;
}
void get(long long i,long long fa,long long x)
{
	sum[col[i]]+=x;
	if (sum[col[i]]>mx) 
	{
		nw=col[i];
		mx=sum[col[i]];
	}
	else if (sum[col[i]]==mx) nw+=col[i];
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j];
		if (to==fa || used[to]) continue;
		get(to,i,x);
	}
}
void dfs(long long i,long long fa,bool f)
{
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j];
		if (to==fa || to==wson[i]) continue;
		dfs(to,i,0);
	}
	if (wson[i])
	{
		dfs(wson[i],i,1);
		used[wson[i]]=1;
	}
	get(i,fa,1);
	ans[i]=nw;
	if (wson[i]) used[wson[i]]=0;
	if (!f)
	{
		get(i,fa,-1);
		nw=mx=0;
	}	
}
int main()
{
	scanf("%I64d",&n);
	for (long long i=1;i<=n;i++) scanf("%I64d",&col[i]);
	for (long long i=1;i<n;i++)
	{
		scanf("%I64d%I64d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);  
	}
	Init(1,0);
	dfs(1,0,1);
	for (long long i=1;i<=n;i++) printf("%I64d ",ans[i]);
	return 0;
}