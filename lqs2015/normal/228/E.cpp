#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<vector>
using namespace std;
vector<int> g[1111];
bool z,ans[1111],used[1111];
int n,m,x,y,co,col[1111],cnt;
void dfs(int i,int co)
{
	col[i]=co;
	used[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (!used[to]) dfs(to,co);
	}
}
int main()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		if (z)
		{
			g[x].push_back(y);
			g[x+n].push_back(y+n);
			g[y+n].push_back(x+n);
			g[y].push_back(x);   
		}
		else
		{
			g[x].push_back(y+n);
			g[x+n].push_back(y);
			g[y+n].push_back(x);
			g[y].push_back(x+n); 
		}
	}
	for (int i=1;i<=n*2;i++)
	{
		if (!used[i]) dfs(i,co++);
	}
	for (int i=1;i<=n;i++)
	{
		if (col[i]==col[i+n])
		{
			cout<<"Impossible"<<endl;
			return 0;
		}
		if (col[i]<col[i+n])
		{
			ans[i]=1;
			cnt++;
		}
	}
	cout<<cnt<<endl;
	for (int i=1;i<=n;i++)
	{
		if (ans[i]) cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}