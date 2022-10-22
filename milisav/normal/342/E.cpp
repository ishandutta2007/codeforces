#include <bits/stdc++.h>
using namespace std;
int n,m;
int d;
vector<int> a[200000];
int vl[200000];
bool centroid[200000];
bool vis[200000];
int ch[200000];
int de[100005][20];
vector<pair<int,int> > c[200000];
int p[200000];
int nr[200000];
int ds[200000];
int rt;
void dfs(int u,int ld)
{
	int v;
	vis[u]=true;
	ch[u]=1;
	for(int i=0;i<a[u].size();i++)
	{
		v=a[u][i];
		if(!centroid[v] && !vis[v])
		{
			de[v][ld]=de[u][ld]+1;
			dfs(v,ld);
			ch[u]+=ch[v];
		}
	}
	vis[u]=false;
}
int cent(int u)
{
	vis[u]=true;
	int v;
	//cout<<u<<" "<<ch[u]<<endl;
	for(int i=0;i<a[u].size();i++)
	{
		v=a[u][i];
		//cout<<ch[v]<<endl;
		if(ch[v]>d/2 && !vis[v] && !centroid[v])
		{
			return cent(v);
		}
	}
	//cout<<u<<endl;
	vis[u]=false;
	return u;
}
int decompose(int u,int ld)
{
	de[u][ld]=0;
	dfs(u,ld);
	d=ch[u];
	int centro=cent(u);
	int v=u,w;
	bool pr;
	pr=true;
	//cout<<u<<endl;
	while(pr)
	{
		//cout<<v<<endl;
		pr=false;
		for(int i=0;i<a[v].size();i++)
		{
			if(vis[a[v][i]])
			{
				w=v;
				vis[w]=false;
				pr=true;
				v=a[v][i];
				i=a[v].size();
			}
		}
	}
	//cout<<u<<endl;
	vis[v]=false;
	u=centro;
	//cout<<u<<endl;
	de[u][ld]=0;
	vl[u]=ld;
	dfs(u,ld);
	centroid[u]=true;
	//ds[u]=de[u][ld]+1;
	for(int i=0;i<a[u].size();i++)
	{
		v=a[u][i];
		if(!centroid[v])
		{
			w=decompose(v,ld+1);
			p[w]=u;
		}
	}
	return u;
}
void update(int u)
{
	nr[u]=0;
	int v=u;
	int rs=0;
	while(v!=rt)
	{
		v=p[v];
		rs=de[u][vl[v]];
		nr[v]=min(nr[v],rs);
	}
}
int query(int u)
{
	int v=u;
	int rs=0;
	int mr=nr[u];
	while(v!=rt)
	{
		v=p[v];
		rs=de[u][vl[v]];
		mr=min(mr,rs+nr[v]);
	}
	return mr;
}
int main()
{
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) nr[i]=m+10;
	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d",&u,&v);
		u--;
		v--;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	rt=decompose(0,0);
	update(0);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&u,&v);
		v--;
		if(u==1) update(v);
		else printf("%d\n",query(v));
	}
	return 0;
}