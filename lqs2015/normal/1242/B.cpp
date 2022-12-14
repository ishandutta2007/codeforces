#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,deg[111111],id[111111],cnt,p[111111],ans;
bool used[111111],f[111111];
vector<int> g[111111],ng[111111];
pair<int,int> a[111111];
map<pair<int,int>,int> mp;
void dfs(int i)
{
	used[i]=1;
	for (int j=0;j<ng[i].size();j++)
	{
		int to=ng[i][j];
		if (!used[to]) dfs(to);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
		deg[x]++;deg[y]++;
		mp[make_pair(x,y)]=mp[make_pair(y,x)]=1;
	}
	for (int i=1;i<=n;i++) a[i]=make_pair(deg[i],i);
	sort(a+1,a+n+1);
	x=a[1].second;
	for (int i=0;i<g[x].size();i++)
	{
		f[g[x][i]]=1;
	}
	cnt=1;
	for (int i=1;i<=n;i++)
	{
		if (f[i]) 
		{
			id[i]=++cnt;
			p[cnt]=i;
		}
	}
	for (int i=2;i<=cnt;i++)
	{
		for (int j=i+1;j<=cnt;j++)
		{
			if (mp.find(make_pair(p[i],p[j]))==mp.end()) 
			{
				ng[i].push_back(j);
				ng[j].push_back(i);
			}
		}
	}
	for (int i=2;i<=cnt;i++)
	{
		bool flg=0;
		for (int j=1;j<=n;j++)
		{
			if (!f[j])
			{
				if (mp.find(make_pair(j,p[i]))==mp.end()) 
				{
					flg=1;
					break;
				}
			}
		}
		if (flg)
		{
			ng[1].push_back(i);
			ng[i].push_back(1);
		}
	}
	for (int i=1;i<=cnt;i++)
	{
		if (!used[i]) 
		{
			ans++;
			dfs(i);
		}
	}
	printf("%d\n",ans-1);
	return 0;
}