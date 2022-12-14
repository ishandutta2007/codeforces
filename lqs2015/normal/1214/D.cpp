#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,m,dfn[2222222],low[2222222],cnt,xx,en[2222222],rfn[2222222];
int dx[]={1,0},dy[]={0,1};
vector<int> g[2222222],rg[2222222];
bool f[2222222],gg[2222222],vis[2222222];
string s[1111111];
bool In(int x,int y)
{
	return (x>=0 && x<n && y>=0 && y<m);
}
int get(int x,int y)
{
	return x*m+y+1;
}
bool dfs(int i)
{
	if (i==get(n-1,m-1)) return 1;
	vis[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (vis[to]) continue;
		if (dfs(to))
		{
			gg[to]=1;
			return 1;
		}
	}
	return 0;
}
bool dft(int i)
{
	if (i==get(n-1,m-1)) return 1;
	vis[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (gg[to] || vis[to])continue;
		if (dft(to)) return 1;
	}
	return 0;
}
int main()
{
	cin>>n>>m;
	for (int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			if (s[i][j]=='#')
			{
				f[get(i,j)]=1;
				continue;
			}
			for (int k=0;k<2;k++)
			{
				int xx=i+dx[k],yy=j+dy[k];
				if (!In(xx,yy)) continue;
				if (s[xx][yy]=='#') continue;
				g[get(i,j)].push_back(get(xx,yy));
			}
		}
	}
	if (!dfs(1))
	{
		printf("0\n");
		return 0;
	}
	gg[get(n-1,m-1)]=0;
	memset(vis,0,sizeof(vis));
	if (!dft(1))
	{
		printf("1\n");
		return 0;
	}
	printf("2\n");
	return Accepted;
}