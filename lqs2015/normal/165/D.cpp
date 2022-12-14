#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
using namespace std;
int n,m,x,y,tp,col[111111],dep[111111],a[111111],b[111111],r;
set<int> s[111111];
vector<int> g[111111];
void dfs(int i,int fa)
{
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dep[to]=dep[i]+1;
		col[to]=col[i];
		dfs(to,i);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);  
		a[i]=x;b[i]=y;
	}
	r=1;
	for (int i=2;i<=n;i++)
	{
		if (g[i].size()>2) r=i; 
	}
	for (int i=0;i<g[r].size();i++)
	{
		col[g[r][i]]=i;
		dep[g[r][i]]=1;
		dfs(g[r][i],r);
	}
	for (int i=1;i<n;i++)
	{
		if (dep[a[i]]>dep[b[i]]) 
		{
			swap(a[i],b[i]);
		}
	}
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d",&tp);
		if (tp==1) 
		{
			scanf("%d",&x);
			s[col[b[x]]].erase(s[col[b[x]]].find(dep[b[x]])); 
		}
		else if (tp==2)
		{
			scanf("%d",&x);
			s[col[b[x]]].insert(dep[b[x]]);
		}
		else
		{
			scanf("%d%d",&x,&y);
			if (col[x]==col[y])
			{
				if (dep[x]<dep[y]) swap(x,y);
				if (s[col[x]].empty()) 
				{
					printf("%d\n",dep[x]-dep[y]);
					continue;
				}
				set<int>::iterator it=s[col[x]].lower_bound(dep[x]);
				if (it!=s[col[x]].end() && *it<=dep[x])
				{
					if (*it<=dep[y]) printf("%d\n",dep[x]-dep[y]);
					else printf("-1\n");
				} 
				else
				{
					if (it==s[col[x]].begin()) printf("%d\n",dep[x]-dep[y]);
					else 
					{
						it--;
						if (*it<=dep[y]) printf("%d\n",dep[x]-dep[y]);
						else printf("-1\n");
					}
				}
			}
			else
			{
				if ((s[col[x]].empty() || *s[col[x]].begin()>dep[x]) && (s[col[y]].empty() || *s[col[y]].begin()>dep[y]))
				printf("%d\n",dep[x]+dep[y]);
				else printf("-1\n");
			}
		}
	}
	return 0;
}