#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
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
}edge[100005];
int n,head[5005],tot,size[5005];
ll b,f[5005][5005][2],c[5005],d[5005];
void add(int u,int v)
{
	edge[tot].from=u;
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}
void dfs(int x)
{
	size[x]=1;
	f[x][0][0]=0;
	f[x][1][0]=c[x];
	f[x][1][1]=c[x]-d[x];
	for(int i=head[x];i!=-1;i=edge[i].next)
	{
		dfs(edge[i].to);
		for(int j=size[x];j>=0;j--)
		{
			for(int k=0;k<=size[edge[i].to];k++)
			{
				f[x][j+k][0]=min(f[x][j+k][0],f[x][j][0]+f[edge[i].to][k][0]);
				f[x][j+k][1]=min(f[x][j+k][1],f[x][j][1]+f[edge[i].to][k][1]);
				f[x][j+k][1]=min(f[x][j+k][1],f[x][j][1]+f[edge[i].to][k][0]);
			}
		}
		size[x]+=size[edge[i].to];
	}
}
int main()
{
	memset(head,-1,sizeof(head));
	memset(f,0x3f3f3f3f,sizeof(f));
	n=read();b=read();
	c[1]=read();d[1]=read();
	for(int i=2;i<=n;i++)
	{
		c[i]=read();d[i]=read();
		int x=read();
		add(x,i);
	}
	dfs(1);
	int ans=0;
	for(int i=n;i;i--)
	{
		if(f[1][i][0]<=b||f[1][i][1]<=b)
		{
			ans=i;
			break;
		}
	}
	cout<<ans;
}