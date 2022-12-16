#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
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
}edge[200005];
int tot,head[100005];
void add(int u,int v)
{
	edge[tot].from=u;
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}
int c[100005],q[100005],num;
int main()
{
	memset(head,-1,sizeof(head));
	int n=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add(u,v);
	}
	for(int i=1;i<=n;i++)
	{
		c[i]=read();
	}
	for(int i=0;i<tot;i++)
	{
		if(c[edge[i].from]!=c[edge[i].to])
		{
			q[++num]=i;
		}
	}
	if(!num)
	{
		printf("YES\n1");
		return 0;
	}
	bool ac=1;
	for(int i=1;i<=num;i++)
	{
		if(edge[q[i]].from!=edge[q[1]].from&&edge[q[i]].to!=edge[q[1]].from)
		{
			ac=0;
			break;
		}
	}
	if(ac)
	{
		printf("YES\n%d",edge[q[1]].from);
		return 0;
	}
	ac=1;
	for(int i=1;i<=num;i++)
	{
		if(edge[q[i]].from!=edge[q[1]].to&&edge[q[i]].to!=edge[q[1]].to)
		{
			ac=0;
			break;
		}
	}
	if(ac)
	{
		printf("YES\n%d",edge[q[1]].to);
		return 0;
	}
	else
	{
		printf("NO");
	}
}