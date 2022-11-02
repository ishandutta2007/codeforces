//
//!
//
//
//!
//
//
//
//
//
#include<bits/stdc++.h>
using namespace std;
struct edge{int to,nxt;}e[1000005];
struct node{int max,fl;}t[2000005];
int n,m,et,dt,head[500005],dep[500005],siz[500005],f[500005],top[500005],wsn[500005],dfn[500005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs1(int x,int fa=0)
{
	dep[x]=dep[fa]+1,siz[x]=1,wsn[x]=0,f[x]=fa;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
	{
		dfs1(e[i].to,x),siz[x]+=siz[e[i].to];
		if(siz[wsn[x]]<siz[e[i].to]) wsn[x]=e[i].to;
	}
}
inline void dfs2(int x,int tp=1)
{
	dfn[x]=++dt,top[x]=tp;
	if(wsn[x]) dfs2(wsn[x],tp);else return;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=f[x]&&e[i].to!=wsn[x]) dfs2(e[i].to,e[i].to);
}
inline void allc(int x,int c) {if(c!=-1) t[x].max=t[x].fl=c;}
inline void down(int x) {allc(x<<1,t[x].fl),allc(x<<1|1,t[x].fl),t[x].fl=-1;}
inline void build(int x,int l,int r) {if(l==r) t[x].max=0,t[x].fl=-1;else build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r);}
inline void chang(int x,int l,int r,int dl,int dr,int dc)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allc(x,dc);else down(x);
	chang(x<<1,l,(l+r)>>1,dl,dr,dc),chang(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc),t[x].max=max(t[x<<1].max,t[x<<1|1].max);
}
inline int query(int x,int l,int r,int dw)
{
	if(l==r) return t[x].max;else down(x);
	if(dw<=((l+r)>>1)) return query(x<<1,l,(l+r)>>1,dw);
	else return query(x<<1|1,((l+r)>>1)+1,r,dw);
}
inline int qry(int x) {return query(1,1,n,dfn[x]);}
inline void ch1(int x) {chang(1,1,n,dfn[x],dfn[x]+siz[x]-1,1);}
inline void ch2(int x,int y=1)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		chang(1,1,n,dfn[top[x]],dfn[x],0),x=f[top[x]];
	}
	if(dfn[x]>dfn[y]) swap(x,y);
	chang(1,1,n,dfn[x],dfn[y],0);
}
int main()
{
	scanf("%d",&n),et=0,memset(head,0,sizeof(head)),dep[0]=siz[0]=0;
	for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),adde(x,y),adde(y,x);
	dfs1(1),dfs2(1),build(1,1,n);int f,x;
	for(scanf("%d",&m);m--;)
	{
		scanf("%d%d",&f,&x);
		if(f==1) ch1(x);else if(f==2) ch2(x);else printf("%d\n",qry(x));
	}
	return 0;
}