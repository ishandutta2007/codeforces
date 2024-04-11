#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
struct node
{
	int from;
	int to;
	int next;
}edge[200005];
int head[100005],tot=0,num,n,dep[100005],fa[100005];double sum;double ex[100005];
void add(int u,int v)
{
	edge[tot].from=u;
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}
void dfs(int x)
{
	bool ac=0;int temp=0;
	for(int i=head[x];i!=-1;i=edge[i].next)
	{
		if(fa[x]!=edge[i].to)
		{
			temp++;
		}
	}
	for(int i=head[x];i!=-1;i=edge[i].next)
	{
		if(fa[x]!=edge[i].to)
		{
			fa[edge[i].to]=x;
			dep[edge[i].to]=dep[x]+1;
			ac=1;
			ex[edge[i].to]=ex[x]/(double)temp;
			dfs(edge[i].to);
		}
	}
	if(!ac)
	{
		num++;
		sum+=(double)dep[x]*ex[x];
	}
}
int main()
{
	memset(head,-1,sizeof(head));
	n=read();
	int x,y;
	for(int i=1;i<n;i++)
	{
		x=read(),y=read();
		add(x,y);
		add(y,x);
	}
	ex[1]=1;
	dfs(1);
	double xx=sum,yy=num;
	printf("%.16lf",sum);
}