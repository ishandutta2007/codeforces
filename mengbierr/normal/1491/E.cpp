#include<iostream>
#include<cstdio>
#include<cmath>
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
	bool vis;
}edge[500005];
int n,tot;
int fib[500005],head[500005];
void add(int u,int v)
{
	edge[tot].from=u;
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}
bool ok=1;
int size[500005],f[500005];
void dfs(int x,int fa)
{
	size[x]=1;
	for(int i=head[x];i!=-1;i=edge[i].next)
	{
		if(edge[i].vis||edge[i].to==fa) continue;
		dfs(edge[i].to,x);
		size[x]+=size[edge[i].to];
	}
	//cout<<x<<" "<<size[x]<<endl;
}
int getroot(int x,int fa,int s,int pre,int maxx)
{
	if(s==size[x])
	{
		f[x]=fa;
		edge[pre].vis=1;
		edge[pre^1].vis=1;
		return x;
	}
	else if(s==maxx-size[x])
	{
		f[fa]=x;
		edge[pre].vis=1;
		edge[pre^1].vis=1;
		return fa;
	}
	for(int i=head[x];i!=-1;i=edge[i].next)
	{
		if(edge[i].vis||edge[i].to==fa) continue;
		int tmp=getroot(edge[i].to,x,s,i,maxx);
		if(tmp) return tmp;
	}
	return 0;
}
void solve(int x,int now)
{
	
	if(now==1||now==0||now<0) return;
	dfs(x,0);
	int rt=0;
	rt=getroot(x,0,fib[now-1],0,size[x]);
	//cout<<x<<" "<<size[x]<<" "<<fib[now-1]<<" "<<rt<<endl;
	if(!rt)
	{
		ok=0;return;
	}
	int tmp=f[rt];
	solve(rt,now-1);
	if(!ok) return;
	solve(tmp,now-2);
}
int main()
{
	memset(head,-1,sizeof(head));
	n=read();
	if(n==1)
	{
		puts("YES");
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	fib[0]=fib[1]=1;
	int now=1;
	for(int i=2;;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
		if(fib[i]==n)
		{
			now=i;
			break;
		}
		if(fib[i]>n)
		{
			puts("NO");
			return 0;
		}
	}
	solve(1,now);
	if(ok) puts("YES");
	else puts("NO");
}
/*
8
4 2
2 3
2 1
1 5
1 6
6 7
6 8
*/