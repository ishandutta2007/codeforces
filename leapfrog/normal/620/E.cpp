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
int n,Q,et,head[400005];struct edge{int to,nxt;}e[800005];
int dt,dfn[400005],nfd[400005],sz[400005],a[400005],fg[1600005];ll T[1600005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void allc(int x,int c) {T[x]=1ll<<c,fg[x]=c;}
inline void pushdw(int x) {if(~fg[x]) allc(x<<1,fg[x]),allc(x<<1|1,fg[x]),fg[x]=-1;}
inline void build(int x,int l,int r)
{
	fg[x]=-1;if(l==r) return T[x]=1ll<<a[nfd[l]],void();
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),T[x]=T[x<<1]|T[x<<1|1];
}
inline ll query(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return 0;else if(dl<=l&&r<=dr) return T[x];else pushdw(x);
	return query(x<<1,l,(l+r)>>1,dl,dr)|query(x<<1|1,((l+r)>>1)+1,r,dl,dr);
}
inline void chang(int x,int l,int r,int dl,int dr,int dc)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allc(x,dc);else pushdw(x);
	chang(x<<1,l,(l+r)>>1,dl,dr,dc),chang(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc),T[x]=T[x<<1]|T[x<<1|1];
}
inline void dfs(int x,int fa)
{
	dfn[x]=++dt,nfd[dt]=x,sz[x]=1;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs(e[i].to,x),sz[x]+=sz[e[i].to];
}
inline int count(ll x) {int r=0;for(;x;x-=x&(-x),r++);return r;}
signed main()
{
	read(n),read(Q);for(int i=1;i<=n;i++) read(a[i]),a[i]--;
	for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	for(dfs(1,0),build(1,1,n);Q--;)
	{
		int fg,x,y;read(fg),read(x);
		if(fg&1) read(y),chang(1,1,n,dfn[x],dfn[x]+sz[x]-1,y-1);
		else printf("%d\n",count(query(1,1,n,dfn[x],dfn[x]+sz[x]-1)));
	}
	return 0;
}