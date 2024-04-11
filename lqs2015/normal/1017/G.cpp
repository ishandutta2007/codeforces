#include<bits/stdc++.h>
using namespace std;
int n,q,x,num,tp[111111],v[111111],godown[111111];
const int magic=350;
vector<int> g[111111];
bool black[111111];
struct edge
{
	int to,nwhite,len;
};
vector<edge> mini[111111];
bool used[111111],cleared[111111];
void dfs(int i,int pa,int nw,int ln)
{
	if (used[i])
	{
		if (pa)
		{
			mini[pa].push_back((edge){i,nw,ln}); 
		}
		for (int j=0;j<g[i].size();j++)
		{
			dfs(g[i][j],i,0,0);
		}
	}
	else
	{
		for (int j=0;j<g[i].size();j++)
		{
			if (black[i]) dfs(g[i][j],pa,nw,ln+1);
			else dfs(g[i][j],pa,nw+1,ln+1);
		}
	}
}
void doit1(int i)
{
	if (!black[i])
	{
		black[i]=1;
		return;
	}
	godown[i]++;
	for (int j=0;j<mini[i].size();j++)
	{
		edge e=mini[i][j];
		if (e.nwhite+1<=godown[i]) doit1(e.to);
	}
}
void doit2(int i)
{
	godown[i]=black[i]=0;
	cleared[i]=1;
	for (int j=0;j<mini[i].size();j++)
	{
		edge e=mini[i][j];
		mini[i][j].nwhite=mini[i][j].len;
		doit2(e.to);
	}
}
void dft(int i,int p,bool c)
{
	if (used[i])
	{
		p=godown[i];c|=cleared[i];
	}
	else
	{
		if (c) black[i]=0;
		if (!black[i] && p)
		{
			black[i]=1;
			p--;
		}
	}
	for (int j=0;j<g[i].size();j++)
	{
		dft(g[i][j],p,c);
	}
}
int main()
{
	scanf("%d%d",&n,&q);
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&x);
		g[x].push_back(i); 
	}
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d",&tp[i],&v[i]);
	}
	num=(q+magic-1)/magic;
	for (int i=0;i<num;i++)
	{
		for (int j=1;j<=n;j++) mini[j].clear();
		memset(used,0,sizeof(used));
		memset(godown,0,sizeof(godown));
		memset(cleared,0,sizeof(cleared));
		for (int j=i*magic+1;j<=q && j<=(i+1)*magic;j++)
		{
			used[v[j]]=1;
		}
		dfs(1,0,0,0);
		for (int j=i*magic+1;j<=q && j<=(i+1)*magic;j++)
		{
			if (tp[j]==1) doit1(v[j]);
			else if (tp[j]==2) doit2(v[j]);
			else 
			{
				if (black[v[j]]) printf("black\n");
				else printf("white\n");
			}
		}
		dft(1,0,0);
	}
	return 0;
}