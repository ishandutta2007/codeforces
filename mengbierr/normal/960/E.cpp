#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define inline  __attribute__((always_inline))
using namespace std;
const int mod=1000000007;
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
}edge[500005];
int tot,head[200005],n,val[200005];
int f[200005],size[200005],dep[200005];
ll ans;
void add(int u,int v)
{
	edge[tot].from=u;
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}
void dfs(int x,int fa)
{
	f[x]=1;dep[x]=dep[fa]+1;size[x]=1;
	for(int i=head[x];i!=-1;i=edge[i].next)
	{
		if(edge[i].to!=fa)
		{
			dfs(edge[i].to,x);
			f[x]-=f[edge[i].to];
			size[x]+=size[edge[i].to];
		}
	}
}
void dfs2(int x,int fa)
{
	for(int i=head[x];i!=-1;i=edge[i].next)
	{
		if(edge[i].to!=fa)
		{
			dfs2(edge[i].to,x);
			ans+=1LL*f[edge[i].to]*size[edge[i].to]%mod*val[x]%mod;
			ans+=mod;ans%=mod;
		}
	}
	if(fa)
	{
		ans+=1LL*(((dep[x]&1)?-f[1]:f[1])+f[x])*(n-size[x])%mod*val[x]%mod;
		ans+=mod;ans%=mod;
	}
}
int main()
{
	memset(head,-1,sizeof(head));
	n=read();
	for(int i=1;i<=n;i++) val[i]=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
	{
		if(dep[i]&1) ans+=1LL*f[1]*val[i];
		else ans-=1LL*f[1]*val[i];
	}//1-i
	
	ans=(ans%mod+mod)%mod;
	ans=ans*n%mod;
	dfs2(1,0);
	cout<<ans;
}