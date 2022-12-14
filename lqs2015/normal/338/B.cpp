#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,m,d,p[111111],x,y,dep[111111],mx[111111],ans;
bool is[111111];
vector<int> g[111111];
void dfs1(int i,int fa,int de)
{
	dep[i]=de;
	if (is[i] && i!=p[1]) mx[i]=dep[i];
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dep[to]=dep[i]+1;
		dfs1(to,i,de+1);
		mx[i]=max(mx[i],mx[to]);
	}
}
void dfs2(int i,int fa,int dist,bool f)
{
	if (dep[i]>d+1 || dist>d) return;
	if (mx[i]-dep[i]<=d) 
	{
		ans++;
	}
	int mm=0,mk=0,cnt=0,pres=dist;
	bool was=f;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		if (mx[to]-dep[i]>mm)
		{
			mk=mm;
			mm=mx[to]-dep[i];
		}
		else if (mx[to]-dep[i]>mk) mk=mx[to]-dep[i];
	}
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		if (mx[to]-dep[i]==mm) cnt++;
	}
	if (is[i] && i!=p[1]) was=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j],curres=pres;
		if (to==fa) continue;
		if (cnt==1 && mx[to]-dep[i]==mm)
		{
			curres=max(curres,mk);
		}
		else curres=max(curres,mm);
		if (!curres && !was) dfs2(to,i,curres,0);
		else dfs2(to,i,curres+1,1);
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&d);
	for (int i=1;i<=m;i++) 
	{
		scanf("%d",&p[i]);
		is[p[i]]=1;
	}
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x); 
	}
	dfs1(p[1],0,1);
	dfs2(p[1],0,0,0);
	printf("%d\n",ans);
	return 0;
}