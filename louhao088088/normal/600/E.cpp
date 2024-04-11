#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+5;
inline int read()
{
	char ch=getchar();int x=0;bool f=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
struct node 
{
	int v,nex;
}e[maxn*2];
int n,m,a[maxn],b[maxn],head[maxn],s[maxn],son[maxn],x,y,ans[maxn],sum[maxn],Max=0,cnt,c[maxn];
void add(int x,int y){e[++cnt].v=y;e[cnt].nex=head[x];head[x]=cnt;}
void dfs(int x,int fa)
{
	int p=0;s[x]=1;
	for(int i=head[x];i;i=e[i].nex)
	{
		int v=e[i].v;if(v==fa)continue;
		dfs(v,x);s[x]+=s[v];if(s[v]>p)p=s[v],son[x]=v;
	}//cout<<son[x]<<" "<<x<<" "<<p<<endl;
}
void del(int x,int fa)
{
	sum[c[a[x]]]=0;c[a[x]]--;
	for(int i=head[x];i;i=e[i].nex)
	{
		int v=e[i].v;if(v==fa)continue;
		del(v,x);
	}
}
void dfs2(int x,int fa)
{
	sum[c[a[x]]]-=a[x];c[a[x]]++;sum[c[a[x]]]+=a[x];
	if(c[a[x]]>Max)Max=c[a[x]];
	for(int i=head[x];i;i=e[i].nex)
	{
		int v=e[i].v;if(v==fa)continue;
		dfs2(v,x);
	}
}
void dfs1(int x,int fa,int num)
{
	//cout<<x<<" "<<fa<<" "<<num<<endl;
	for(int i=head[x];i;i=e[i].nex)
	{
		int v=e[i].v;if(v==fa||son[x]==v)continue;
		dfs1(v,x,0);
	}
	if(son[x])dfs1(son[x],x,1);
//	cout<<x<<" "<<Max<<" "<<sum[Max]<<" "<<num<<endl;
	sum[c[a[x]]]-=a[x];c[a[x]]++;sum[c[a[x]]]+=a[x];
	if(c[a[x]]>Max)Max=c[a[x]];
	for(int i=head[x];i;i=e[i].nex)
	{
		int v=e[i].v;if(v==fa||son[x]==v)continue;
		dfs2(v,x); 
	}ans[x]=sum[Max];//cout<<x<<" "<<Max<<" "<<sum[Max]<<" "<<num<<endl;
	if(num==0)del(x,fa),Max=0;
	
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<n;i++)x=read(),y=read(),add(x,y),add(y,x);
	dfs(1,0);dfs1(1,0,1);
	for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
	return 0;
}