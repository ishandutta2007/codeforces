#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
queue<int> q;
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
	int w;
}edge[200005];
int tot,head[1005],n,a[1005],s,t,dis[1005];bool vis[1005];
void add(int u,int v,int w)
{
	edge[tot].from=u;
	edge[tot].to=v;
	edge[tot].w=w;
	edge[tot].next=head[u];
	head[u]=tot++;
}
void spfa()
{
	q.push(s);
	memset(dis,0x7f7f7f7f,sizeof(dis));
	dis[s]=0;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		vis[x]=0;
		for(int i=head[x];i!=-1;i=edge[i].next)
		{
			if(dis[edge[i].to]>dis[x]+edge[i].w)
			{
				dis[edge[i].to]=dis[x]+edge[i].w;
				if(!vis[edge[i].to])
				{
					vis[edge[i].to]=1;
					q.push(edge[i].to);
				}
			}
		}
	}
}
int main()
{
	memset(head,-1,sizeof(head));
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
			add(0,1,1);
			if(a[i]>1)
			{
				add(0,2,0);
			}
			if((a[i]&1))
			{
				add(0,3,0);
			}
		}
		else
		{
			for(int j=1;j<=3;j++)
			{
				add((i-2)*3+j,(i-1)*3+1,1);
			}
			if(a[i]>1)
			{
				for(int j=1;j<=3;j++)
				{
					if(j!=2)
					add((i-2)*3+j,(i-1)*3+2,0);
				}
			}
			if((a[i]&1))
			{
				for(int j=1;j<=3;j++)
				{
					if(j!=3)
					add((i-2)*3+j,(i-1)*3+3,0);
				}
			}
		}
	}
	t=n*3+1;
	add(n*3,t,0);
	add(n*3-2,t,0);
	add(n*3-1,t,0);
	spfa();
	cout<<dis[t];
}