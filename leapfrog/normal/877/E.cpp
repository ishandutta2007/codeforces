//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename t>inline void read(t &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct node{int ln,sm;char tg;}t[800005];int n,m,a[200005],sz[200005];
struct edge{int to,nxt;}e[200005];int et,head[200005],dt,dfn[200005],nfd[200005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void allc(int x) {t[x].tg^=1,t[x].sm=t[x].ln-t[x].sm;}
inline void pushdw(int x) {if(t[x].tg) allc(x<<1),allc(x<<1|1),t[x].tg=0;}
inline void build(int x,int l,int r)
{
	t[x].ln=r-l+1;if(l==r) return t[x].sm=a[nfd[l]],void();
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),t[x].sm=t[x<<1].sm+t[x<<1|1].sm;
}
inline void modif(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allc(x);else pushdw(x);
	modif(x<<1,l,(l+r)>>1,dl,dr),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr),t[x].sm=t[x<<1].sm+t[x<<1|1].sm;
}
inline int query(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return 0;else if(dl<=l&&r<=dr) return t[x].sm;else pushdw(x);
	return query(x<<1,l,(l+r)>>1,dl,dr)+query(x<<1|1,((l+r)>>1)+1,r,dl,dr);
}
inline void dfs(int x) {sz[x]=1,dfn[x]=++dt,nfd[dt]=x;for(int i=head[x];i;i=e[i].nxt) dfs(e[i].to),sz[x]+=sz[e[i].to];}
int main()
{
	read(n);for(int i=2,f;i<=n;i++) read(f),adde(f,i);
	for(int i=1;i<=n;i++) read(a[i]);
	for(read(m),dfs(1),build(1,1,n);m--;)
	{
		char ch[5];int x;scanf("%s",ch),read(x);
		if(*ch=='p') modif(1,1,n,dfn[x],dfn[x]+sz[x]-1);else printf("%d\n",query(1,1,n,dfn[x],dfn[x]+sz[x]-1));
	}
	return 0;
}