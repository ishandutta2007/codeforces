#include<bits/stdc++.h>
using namespace std;
int n,x,y,len[1111111],wson[1111111],ans[1111111];
int *f[1111111],tmp[1111111],*id=tmp;
vector<int> g[1111111];
void dfs(int i,int fa)
{
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dfs(to,i);
		if (len[to]>=len[wson[i]]) wson[i]=to;
	}
	len[i]=len[wson[i]]+1;
}
void dft(int i,int fa)
{
	if (wson[i])
	{
		f[wson[i]]=f[i]+1;
		dft(wson[i],i);
		ans[i]=ans[wson[i]]+1;
	}
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa || to==wson[i]) continue;
		f[to]=id;id+=len[to];
		dft(to,i);
		for (int k=0;k<len[to];k++)
		{
			f[i][k+1]+=f[to][k];
			if (((k+1>=ans[i]) && f[i][k+1]>f[i][ans[i]]) || (k+1<ans[i] && f[i][k+1]>=f[i][ans[i]])) ans[i]=k+1;
		}
	}
	if (f[i][ans[i]]==1) ans[i]=0;
	f[i][0]=1;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	f[1]=id;id+=len[1];
	dft(1,0);
	for (int i=1;i<=n;i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}