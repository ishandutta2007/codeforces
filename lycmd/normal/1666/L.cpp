#include<bits/stdc++.h>
using namespace std;
#define N 200005
struct node
{
	int next,to;
}e[N];
stack<int>sta;
bool bo[N],vis[N];
int head[N],fa[N],s,g;
int read()
{
	int A;
	bool K;
	char C;
	C=A=K=0;
	while(C<'0'||C>'9')K|=C=='-',C=getchar();
	while(C>'/'&&C<':')A=(A<<3)+(A<<1)+(C^48),C=getchar();
	return(K?-A:A);
}
void write(int X)
{
	if(X<0)putchar('-'),X=-X;
	if(X>9)write(X/10);
	putchar(X%10|48);
}
void add(int u,int v)
{
	e[++g].to=v;
	e[g].next=head[u];
	head[u]=g;
}
void print(int u,int k)
{
	if(u!=s)
	{
		print(fa[u],k+1);
		write(u);
		putchar(' ');
	}
	else
	{
		write(k);
		putchar('\n');
		write(s);
		putchar(' ');
	}
}
void dfs(int u)
{
	int i,v;
	vis[u]=bo[u]=1;
	sta.push(u);
	for(i=head[u];i;i=e[i].next)
	{
		v=e[i].to;
		if(u==s)
		{
			while(!sta.empty())bo[sta.top()]=0,sta.pop();
			bo[u]=1;
		}
		if(vis[v])if(bo[v])continue;
		else
		{
			puts("Possible");
			print(v,1);
			putchar('\n');
			print(u,2);
			write(v);
			exit(0);
		}
		else fa[v]=u,dfs(v);
	}
}
int main()
{
	int n,m,u,v;
	n=read(),m=read(),s=read();
	while(m--)
	{
		u=read(),v=read();
		add(u,v);
	}
	dfs(s);
	puts("Impossible");
	return 0;
}