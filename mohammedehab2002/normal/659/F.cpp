#include <iostream>
#include <algorithm>
using namespace std;
pair<int,int> arr[1000005];
int par[1000005],sz[1000005];
int find(int x)
{
	if (par[x]!=x)
	par[x]=find(par[x]);
	return par[x];
}
void Union(int a,int b)
{
	a=find(a);
	b=find(b);
	if (a!=b)
	{
		par[a]=b;
		sz[b]+=sz[a];
		sz[a]=0;
	}
}
int ans[1005][1005],n,m;
bool vis[1005][1005],add[1000005];
long long k;
void dfs(int x,int y)
{
	vis[x][y]=1;
	if (!k)
	return;
	ans[x][y]=1;
	k--;
	for (int dx=-1;dx<=1;dx++)
	{
		for (int dy=-1;dy<=1;dy++)
		{
			if (abs(dx)+abs(dy)==1 && x+dx>=0 && x+dx<n && y+dy>=0 && y+dy<m && !vis[x+dx][y+dy] && add[(x+dx)*m+y+dy])
			dfs(x+dx,y+dy);
		}
	}
}
int main()
{
	scanf("%d%d%I64d",&n,&m,&k);
	for (int i=0;i<n*m;i++)
	{
		scanf("%d",&arr[i].first);
		arr[i].second=i;
		par[i]=i;
		sz[i]=1;
	}
	sort(arr,arr+n*m);
	for (int i=n*m-1;i>=0;i--)
	{
		int idx=arr[i].second;
		if (idx>=m && add[idx-m])
		Union(idx,idx-m);
		if (idx<(n-1)*m && add[idx+m])
		Union(idx,idx+m);
		if (idx%m && add[idx-1])
		Union(idx,idx-1);
		if (idx%m!=m-1 && add[idx+1])
		Union(idx,idx+1);
		if (k%arr[i].first==0 && sz[find(idx)]>=k/arr[i].first)
		{
			k/=arr[i].first;
			dfs(idx/m,idx%m);
			printf("YES\n");
			for (int x=0;x<n;x++)
			{
				for (int j=0;j<m;j++)
				printf("%d ",ans[x][j]*arr[i].first);
				printf("\n");
			}
			return 0;
		}
		add[idx]=1;
	}
	printf("NO");
}