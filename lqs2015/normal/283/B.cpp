#include<iostream>
#include<cstdio>
using namespace std;
long long g[444444],n;
long long a[444444],val[444444];
long long used[444444];
void dfs(long long i)
{
	used[i]=1;
	if (g[i]==-1) 
	{
		used[i]=2;
		return;
	}
	if (used[g[i]]==1 || !g[i])
	{
		val[i]=-1;
		used[i]=2;
		return;
	}
	if (!used[g[i]]) dfs(g[i]);
	if (val[g[i]]==-1) val[i]=-1;
	else val[i]=val[g[i]]+(i>=n ? a[i-n+1] : a[i]);
	used[i]=2;
}
int main()
{
	scanf("%lld",&n);
	for (long long i=1;i<n;i++) scanf("%lld",&a[i]);
	for (long long i=1;i<n;i++)
	{
		if (i+a[i]<n) g[i]=i+a[i]+n-1;
		else
		{
			g[i]=-1;
			val[i]=a[i];
		}
		if (i-a[i]>=0) g[i+n-1]=i-a[i];  
		else 
		{
			g[i+n-1]=-1;
			val[i+n-1]=a[i];
		}
	}
	for (long long i=1;i<=n*2-2;i++)
	{
		if (!used[i]) dfs(i);
	}
	for (long long i=1;i<n;i++)
	{
		if (val[i+n-1]==-1) printf("-1\n");
		else printf("%lld\n",i+val[i+n-1]);
	}
	return 0;
}