#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
vector<int> g[1111111];
int n,m,j,t,i,r,l;
int a[555555],u[555555],s[555555];
int vis[555555];
bool dfs(int i)
{
	vis[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (vis[to]==1) return 1;
		if (!vis[to] && dfs(to)) return 1;
	}
	vis[i]=2;
	s[++r]=i;
	return 0;
}
bool cmp(int i,int j)
{
	return a[i]<a[j];
}
int main()
{
	cin>>n>>m;
	t=m;
	for (i=1;i<=n;i++)
	{
		for (j=0;j<m;j++) cin>>a[j];
		for (j=0;j<m;j++)
		{
			u[j]=j;
		}		
		sort(u,u+m,cmp);
		for (j=0;a[u[j]]==-1 && j<m;j++);
		for (t++;j<m;t++,j+=l)
		{
			for (l=0;j+l<m && a[u[j]]==a[u[j+l]];l++)
			{
				g[t-1].push_back(u[j+l]);
				g[u[j+l]].push_back(t); 
			}
		}
	}
	for (i=0;i<t;i++)
	{
		if (!vis[i] && dfs(i)) break;
	}
	if (i<t)
	{
		cout<<-1<<endl;
		return 0;
	}
	else
	{
		for (int i=r;i>=1;i--)
		{
			if (s[i]<m) cout<<s[i]+1<<" ";
		}
		cout<<endl;
	}
	return 0;
}