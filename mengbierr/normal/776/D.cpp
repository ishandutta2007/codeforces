#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
stack<int> s;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f;
}
struct node
{
	int from;
	int to;
	int next;
}edge[500005];
int tot,head[200005],belong[200005],a[200005],b[200005][3];
int dfn[200005],low[200005];bool vis[200005];int n,m;
void add(int u,int v)
{
	edge[tot].from=u;
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}
int tim,cnt;
void tarjan(int x)
{
	dfn[x]=low[x]=++tim;
	s.push(x);
	vis[x]=1;
	for(int i=head[x];i!=-1;i=edge[i].next)
	{
		if(!dfn[edge[i].to])
		{
			tarjan(edge[i].to);
			low[x]=min(low[x],low[edge[i].to]);
		}
		else
		low[x]=min(low[x],dfn[edge[i].to]);
	}
	if(low[x]==dfn[x])
	{
		cnt++;
		while(s.top()!=x)
		{
			int now=s.top();
			s.pop();
			vis[now]=0;
			belong[now]=cnt;
		}
		if(s.top()==x)
		{
			s.pop();
			vis[x]=0;
			belong[x]=cnt;
		}
	}
}
int main()
{
	memset(head,-1,sizeof(head));
	n=read();m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(int i=1;i<=m;i++)
	{
		int x=read();
		for(int j=1;j<=x;j++)
		{
			int y=read();
			if(b[y][1]) b[y][2]=i;
			else b[y][1]=i;
		}
		//cout<<"ok";
	}
	for(int i=1;i<=n;i++)
	{
		int u=b[i][1],v=b[i][2];
		if(a[i])
		{
			add(u+m,v+m);add(v+m,u+m);
			add(u,v);add(v,u);
		}
		else
		{
			add(u+m,v);add(v,u+m);
			add(u,v+m);add(v+m,u);
		}
	}
	
	for(int i=1;i<=2*m;i++)
	{
		if(!dfn[i])
		tarjan(i);
	}//cout<<"ok";
	for(int i=1;i<=m;i++)
	{
		if(belong[i]==belong[i+m])
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
}