#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
long long n,x,y,a,b,sub[333333],sy,ans;
vector<long long> g[333333];
bool dfs(long long i,long long fa)
{
	bool f=0;
	sub[i]=1;
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j];
		if (to==fa) continue;
		if (i==y) 
		{
			if (dfs(to,i)) sy=sub[to];
		}
		else 
		{
			f|=dfs(to,i);
			sub[i]+=sub[to];
		}
	}
	if (i==x) return 1;
	return f;
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&x,&y);
	for (long long i=1;i<n;i++)
	{
		scanf("%I64d%I64d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);  
	}
	dfs(y,0);
	ans=n*(n-1)-sub[x]*(n-sy);
	printf("%I64d\n",ans);
	return 0;
}