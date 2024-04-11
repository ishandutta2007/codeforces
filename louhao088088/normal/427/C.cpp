#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+5,mod=1e9+7;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
struct edge{int v,nex;}e[maxn];
int n,m,head[maxn],st[maxn],top=0,dfn[maxn],idx=0,low[maxn],c[maxn],num[maxn],op,tot=0,Max=0,cnt=0,x,y,ans,a[maxn],Min[maxn];
void tarjan(int x)
{
	dfn[x]=low[x]=++idx;st[++top]=x;
	for(int i=head[x];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(!dfn[v])tarjan(v),low[x]=min(low[x],low[v]);
		else if(!c[v])low[x]=min(low[x],dfn[v]); 
	}
	if(dfn[x]==low[x])
	{
		tot++;
		while(st[top]!=x&&top>0)
		{
			c[st[top]]=tot;
			if(Min[tot]>a[st[top]])Min[tot]=a[st[top]],num[tot]=0;
			if(Min[tot]==a[st[top]])num[tot]++;//cout<<st[top]<<" "<<a[st[top]]<<" "<<Min[tot]<<endl;
			top--;
		}
		if(Min[tot]>a[x])Min[tot]=a[x],num[tot]=0;
		if(Min[tot]==a[x])num[tot]++;
		c[x]=tot;top--;
	}
}
void add(int x,int y){e[++cnt].v=y,e[cnt].nex=head[x],head[x]=cnt;}
signed main()
{
	n=read(),memset(Min,0x3f,sizeof Min);
	for(int i=1;i<=n;i++)a[i]=read();m=read();
	for(int i=1;i<=m;i++)x=read(),y=read(),add(x,y);
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);ans=0;
	for(int i=1;i<=tot;i++)ans+=Min[i];cout<<ans<<" ";ans=1;
	for(int i=1;i<=tot;i++)ans=ans*num[i]%mod;cout<<ans<<endl;
	return 0;
}