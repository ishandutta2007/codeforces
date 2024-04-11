#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#define ll long long
#define N 200010
using namespace std;
struct fck{int a,b,c;}s[N<<2];
int l,r,cnt,dfn[N],siz[N],vis[N],fir[N],nxt[N],to[N],rq[N],top;
ll a[N],f1[N],f2[N],e[N],s1[N],s2[N],dep[N],b[N],res,mx;
void add(int u,int v){nxt[++cnt]=fir[u];fir[u]=cnt;to[cnt]=v;}
void dfs(int x,int fa)
{
	s[top=1]=(fck){x,fa,0};
	while (top)
	{
		x=s[top].a;fa=s[top].b;int c=s[top].c;top--;
		if (!c)
		{
			dfn[x]=++cnt;siz[x]=1;dep[x]=dep[fa]+a[x];if (dep[x]>mx) mx=dep[x],l=x;s[++top]=(fck){x,fa,1};
			for (int i=fir[x];i;i=nxt[i]) if (!rq[to[i]] && to[i]!=fa) s[++top]=(fck){to[i],x,0};
		}
		else for (int i=fir[x];i;i=nxt[i]) if (!rq[to[i]] && to[i]!=fa) siz[x]+=siz[to[i]];
	}
}
int main()
{
	int n,i,u,v,pos,tot=0;ll ans=0;scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for (i=1;i<n;i++) scanf("%d%d",&u,&v),add(u,v),add(v,u);
	cnt=0;dfs(1,0);cnt=mx=0;r=l;dfs(l,0);pos=l;
	for (i=1;i<=n;i++) if (dfn[i]<=dfn[l] && dfn[l]<dfn[i]+siz[i]) rq[i]=1;
	while (pos!=r)
	{
		mx=cnt=0;dfs(pos,0);b[++tot]=mx-a[pos];vis[pos]=1;e[tot]=a[pos];
		for (i=fir[pos];i;i=nxt[i]) if (!rq[to[i]])
		{
			cnt=mx=0;dfs(to[i],0);cnt=mx=0;dfs(l,0);res=max(res,mx);
		}
		for (i=fir[pos];i;i=nxt[i]) {if (rq[to[i]] && !vis[to[i]]) {pos=to[i];break;}}
	}
	mx=cnt=0;dfs(pos,0);b[++tot]=mx-a[pos];vis[pos]=1;e[tot]=a[pos];
	for (i=1;i<=tot;i++) s1[i]=s1[i-1]+e[i],f1[i]=max(f1[i-1],s1[i]+b[i]);
	for (i=tot;i;i--) s2[i]=s2[i+1]+e[i],f2[i]=max(f2[i+1],s2[i]+b[i]);
	for (i=1;i<tot;i++) ans=max(ans,f1[i]+f2[i+1]);cout<<max(ans,s1[tot]+res);
}