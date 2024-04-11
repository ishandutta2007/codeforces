#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
vector<int> c; 
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
struct node
{
	int from;
	int to;
	int next;
	int w;
}edge[200005];
int tot,head[100005];
bool vis[100005];
int dis[100005];
int n,m;
void add(int u,int v,int w)
{
	edge[tot].from=u;
	edge[tot].to=v;
	edge[tot].next=head[u];
	edge[tot].w=w;
	head[u]=tot++;
}
void add(int x)
{
	for(int i=0;i<c.size();i++)
	x=min(x,x^c[i]);
	if(x) c.push_back(x);
}
void dfs(int x)
{
	vis[x]=1;
	for(int i=head[x];i!=-1;i=edge[i].next)
	{
		if(!vis[edge[i].to])
		{
			dis[edge[i].to]=dis[x]^edge[i].w;
			dfs(edge[i].to);
		}
		else add(dis[edge[i].to]^dis[x]^edge[i].w);
	}
}
int main()
{
	memset(head,-1,sizeof(head));
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		add(u,v,w);
		add(v,u,w);
	}
	dfs(1);
	for(int i=0;i<c.size();i++)
	dis[n]=min(dis[n],dis[n]^c[i]);
	cout<<dis[n];
}