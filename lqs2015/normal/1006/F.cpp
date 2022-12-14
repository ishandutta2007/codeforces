#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
long long n,m,k,a[22][22],ans;
map<pair<long long,long long>,long long> mp;
void dfs1(long long i,long long j,long long sum)
{
	if (i+j==n+1)
	{
		mp[make_pair(i,sum)]++;
		
		return;
	}
	if (i<n) dfs1(i+1,j,sum^a[i+1][j]);
	if (j<m) dfs1(i,j+1,sum^a[i][j+1]); 
}
void dfs2(long long i,long long j,long long sum)
{
	if (i+j==n+1)
	{
		ans+=mp[make_pair(i,k^sum^a[i][j])];
		return;
	}
	if (i>1) dfs2(i-1,j,sum^a[i-1][j]);
	if (j>1) dfs2(i,j-1,sum^a[i][j-1]);
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	for (long long i=1;i<=n;i++)
	{
		for (long long j=1;j<=m;j++)
		{
			scanf("%I64d",&a[i][j]);
		}
	}
	dfs1(1,1,a[1][1]);
	dfs2(n,m,a[n][m]);
	printf("%I64d\n",ans);
	return 0;
}