#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
const int maxn=500005;
int a[maxn],cnt=0,head[maxn],f[maxn],head1[maxn],tot=0,n,dis,ans;
struct edge{int v,nex;}e[maxn*2],ee[maxn];
void add(int u,int v){e[++cnt].v=v,e[cnt].nex=head[u],head[u]=cnt;}
void add1(int u,int v){ee[++cnt].v=v,ee[cnt].nex=head1[u],head1[u]=cnt;}
void dfs(int u,int fa)
{
	for(int i=head[u];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v!=fa)
		{
			if(a[v]==a[u])f[v]=f[u];
			else f[v]=++tot,add1(f[v],f[u]),add1(f[u],f[v]);
			dfs(v,u);
		}
	}
}
void dfs1(int u,int fa,int num)
{
	if(num>dis)dis=num,ans=u;
	for(int i=head1[u];i;i=ee[i].nex)
	{
		int v=ee[i].v;//cout<<v<<endl;
		if(v!=fa)dfs1(v,u,num+1);
	}
}
int main()
{
	n=read();tot=1;f[1]=tot;
	for(int i=1;i<=n;i++)a[i]=read();int x,y;
	for(int i=1;i<n;i++)x=read(),y=read(),add(x,y),add(y,x);
	cnt=0;dfs(1,0);dis=0,dfs1(1,0,0),dfs1(ans,0,0);cout<<(dis+1)/2<<endl;
	return 0; 
}