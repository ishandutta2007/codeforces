#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
char buffer[maxn],*S,*T;
inline char Get_Char()
{
    if(S==T)
    {
        T=(S=buffer)+fread(buffer,1,maxn,stdin);
        if(S==T) return EOF;
    }
    return *S++;
}
int read()
{
    char c;
    int re=0,f=0;
    for(c=Get_Char();c<'0'||c>'9';c=Get_Char())
    {
    	if (c=='-') f=1;
	}
    while(c>='0'&&c<='9')
           re=re*10+(c&15),c=Get_Char();
    if (f) return -re;
    return re;
}
int n,m,x,y,z,pa[222222],sdom[222222],idom[222222],val[222222],dfn[222222],cnt,fa[222222],id[222222],s,idx;
int sub[222222],ans,crt;
vector<int> g[222222],rg[222222],v[222222];
vector<pair<int,int> > fake[222222];
long long dist[222222];
int root(int x)
{
	if (pa[x]==x) return x;
	int rt=root(pa[x]);
	if (dfn[sdom[val[x]]]>dfn[sdom[val[pa[x]]]]) val[x]=val[pa[x]];
	pa[x]=rt;
	return rt;
}
void dfs(int i,int f)
{
	dfn[i]=++cnt;id[cnt]=i;fa[i]=f;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (dfn[to]) continue;
		dfs(to,i);
	}
}
void dominated_tree()
{
	for (int i=1;i<=n;i++)
	{
		val[i]=i;
		pa[i]=i;sdom[i]=i;
	}
	for (int i=cnt;i>=2;i--)
	{
		idx=id[i];
		for (int j=0;j<rg[idx].size();j++)
		{
			int to=rg[idx][j];
			if (dfn[to]<dfn[idx])
			{
				if (dfn[to]<dfn[sdom[idx]])
				{
					sdom[idx]=to;
				}
			} 
			else
			{
				root(to);
				if (dfn[sdom[val[to]]]<dfn[sdom[idx]])
				{
					sdom[idx]=sdom[val[to]];
				}
			}
		}
		v[sdom[idx]].push_back(idx);
		pa[idx]=fa[idx];idx=fa[idx];
		for (int j=0;j<v[idx].size();j++)
		{
			int to=v[idx][j];root(to);
			if (sdom[to]==sdom[val[to]]) idom[to]=sdom[to];
			else idom[to]=val[to];
		}
		v[idx].clear();
	}
	for (int i=2;i<=cnt;i++)
	{
		if (idom[id[i]]!=sdom[id[i]]) idom[id[i]]=idom[idom[id[i]]];
	}
}
void dijk()
{
	priority_queue<pair<long long,int> > pq;
	for (int i=1;i<=n;i++) dist[i]=1e18;
	dist[s]=0;
	pq.push(make_pair(0,s));
	while(!pq.empty())
	{
		int x=pq.top().second;long long y=-pq.top().first;
		pq.pop();
		if (dist[x]!=y) continue;
		for (int i=0;i<fake[x].size();i++)
		{
			int to=fake[x][i].first,val=fake[x][i].second;
			if (dist[to]>dist[x]+val)
			{
				dist[to]=dist[x]+val;
				pq.push(make_pair(-dist[to],to));
			}
		}
	}
}
int main()
{
	n=read();m=read();s=read();
	for (int i=1;i<=m;i++)
	{
		x=read();y=read();z=read();
		fake[x].push_back(make_pair(y,z));
		fake[y].push_back(make_pair(x,z));
	}
	dijk();
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<fake[i].size();j++)
		{
			int to=fake[i][j].first,val=fake[i][j].second;
			if (dist[i]+val==dist[to]) 
			{
				g[i].push_back(to);
				rg[to].push_back(i);
			}
		}
	}
	dfs(s,0);
	dominated_tree();
	for (int i=1;i<=n;i++) sub[i]=1;
	for (int i=cnt;i>=2;i--)
	{
		ans=max(ans,sub[id[i]]);
		sub[idom[id[i]]]+=sub[id[i]];
	}
	printf("%d\n",ans);
	return 0;
}