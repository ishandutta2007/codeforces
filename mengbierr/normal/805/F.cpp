#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#define ll long long
using namespace std;
vector<int> w[100005];
vector<int> s[100005];
map<pair<int,int>,double> ans;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
int n,m,q,father[100005];
int d[100005],dis[100005],maxx,pla;
int find(int x)
{
	return father[x]==x?x:father[x]=find(father[x]);
}
struct node
{
	int from;
	int to;
	int next;
}edge[200005];
int tot,head[100005];
void add(int u,int v)
{
	edge[tot].from=u;
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}
void dfs(int u,int fa,int d)
{
	dis[u]=d;
	if(d>maxx)
	{
		maxx=d;
		pla=u;
	}
	for(int i=head[u];i!=-1;i=edge[i].next)
	{
		if(edge[i].to==fa) continue;
		dfs(edge[i].to,u,d+1);
	}
}
void dfs2(int u,int fa,int d,int root)
{
	dis[u]=max(dis[u],d);
	w[root].push_back(dis[u]);
	for(int i=head[u];i!=-1;i=edge[i].next)
	{
		if(edge[i].to==fa) continue;
		dfs2(edge[i].to,u,d+1,root);
	}
}
void pre(int u)
{
	maxx=0;
	pla=u;
	dfs(u,-1,0);
	maxx=0;
	dfs(pla,-1,0);
	d[u]=maxx;
	dfs2(pla,-1,0,u);
	sort(w[u].begin(),w[u].end());
	s[u].push_back(w[u][0]);
	for(int i=1;i<w[u].size();i++)
	{
		s[u].push_back(s[u][i-1]+w[u][i]);
	}
}
int main()
{
	memset(head,-1,sizeof(head));
	n=read();m=read();q=read();
	for(int i=1;i<=n;i++) father[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		add(u,v);
		add(v,u);
		int fx=find(u),fy=find(v);
		father[fx]=fy;
	}
	for(int i=1;i<=n;i++)
	{
		if(i==find(i)) pre(i);
	}
	while(q--)
	{
		int u=read(),v=read();
		u=find(u);v=find(v);
		if(u==v)
		{
			puts("-1");
			continue;
		}
		if(w[u].size()>w[v].size()) swap(u,v);
		if(ans.find(make_pair(u,v))!=ans.end())
		{
			printf("%.10lf\n",ans[make_pair(u,v)]);
			continue;
		}
		int maxd=max(d[u],d[v]);
		double now=0;
		for(int i=0;i<w[u].size();i++)
		{
			ll num=upper_bound(w[v].begin(),w[v].end(),maxd-w[u][i]-1)-w[v].begin();
			now+=num*maxd;
			if(num<w[v].size())
			{
				now+=(w[v].size()-num)*(w[u][i]+1)+s[v].back()-(num?s[v][num-1]:0);
			}
		}
		now/=w[u].size()*w[v].size();
		ans[make_pair(u,v)]=now;
		printf("%.10lf\n",now);
	}
}