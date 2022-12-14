#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
vector<int> g[111111];
int n,col[111111],x,y,dep[111111],cnt,cur;
bool can[111111];
void dfs(int i,int fa,int dept)
{
	can[i]=1;
	dep[i]=dept;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		if (col[i]!=col[to]) can[i]=0;
		dfs(to,i,dept+1);
		can[i]=can[i] && can[to];
	}
}
int check(int i,int fa)
{
	bool ff=0;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
        if (to==fa) continue;
		if (!can[to]) ff=1;
	}
	if (!ff) return i;
	if (fa && col[i]!=col[fa]) return 0;
	cnt=0;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
        if (to==fa) continue; 
		if (!can[to] || col[to]!=col[i]) 
		{
			cnt++;
			cur=to;
		}
	}
	if (cnt>1) return 0;
	return check(cur,i);	
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n-1;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x); 
	}
	for (int i=1;i<=n;i++) scanf("%d",&col[i]);
	dfs(1,0,0);
	//for (int i=1;i<=n;i++) cout<<can[i]<<" ";
	int ch=check(1,0);
	if (ch)
	{
		printf("YES\n");
		printf("%d\n",ch);
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}