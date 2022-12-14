#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
using namespace std;
int n,k,x,y;
set<int> g[111111];
vector<int> v,vv,gg[111111];
bool used[111111],f;
void dfs(int i,int fa,int dep)
{
	if (gg[i].size()==1)
	{
		if (dep!=k) f=1;
		return;
	}
	if (!fa)
	{
		if (gg[i].size()<3) 
		{
			f=1;
			return;
		}
	}
	else
	{
		if (gg[i].size()<4)
		{
			f=1;
			return;
		}
	}
	for (int j=0;j<gg[i].size();j++)
	{
		int to=gg[i][j];
		if (to==fa) continue;
		dfs(to,i,dep+1);
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].insert(y);
		g[y].insert(x);  
		gg[x].push_back(y);
		gg[y].push_back(x);  
	}
	for (int i=1;i<=n;i++)
	{
		if (g[i].size()==1) 
		{
			v.push_back(i);
			used[i]=1; 
		} 
	}
	for (int i=1;i<=k;i++)
	{
		vv.clear();
		for (int j=0;j<v.size();j++)
		{
			x=v[j];
			if (g[x].size()==0) 
			{
				printf("No\n");
				return 0;
			}
			if (g[x].size()==1)
			{
				if (used[*g[x].begin()])
				{
					g[*g[x].begin()].erase(g[*g[x].begin()].find(x));
				}
				else
				{
					used[*g[x].begin()]=1;
					vv.push_back(*g[x].begin()); 
					g[*g[x].begin()].erase(g[*g[x].begin()].find(x));
				}
			}
			else
			{
				printf("No\n");
				return 0;
			}
			g[x].clear();
		}
		if (vv.size()==0)
		{
			printf("No\n");
			return 0;
		} 
		v=vv;
	}
	if (vv.size()!=1)
	{
		printf("No\n");
		return 0;
	}
	dfs(vv[0],0,0);
	if (f)
	{
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	return 0;
}