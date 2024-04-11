//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
const int N=500005;int n,m,Q,fa[N<<1],fr[N],tw[N],w[N],vl[N];
struct node{int vl,wh;}T[N<<2];int rt;char op[N],vs[N];
struct edge{int to,nxt;}e[N<<1];int et,head[N],dfn[N],sz[N],dt;
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline void mrg(int x,int y) {x=getf(x),y=getf(y);if(x^y) ++rt,fa[x]=fa[y]=fa[rt]=rt,adde(rt,x),adde(rt,y);}
inline void dfs(int x) {sz[x]=1,dfn[x]=++dt;for(int i=head[x];i;i=e[i].nxt) dfs(e[i].to),sz[x]+=sz[e[i].to];}
inline node operator+(node a,node b) {return a.vl>b.vl?a:b;}
inline void modif(int x,int l,int r,int dw,int dc)
{
	if(l==r) return T[x]=(node){dc,l},void();
	if(dw<=((l+r)>>1)) modif(x<<1,l,(l+r)>>1,dw,dc),T[x]=T[x<<1]+T[x<<1|1];
	else modif(x<<1|1,((l+r)>>1)+1,r,dw,dc),T[x]=T[x<<1]+T[x<<1|1];
}
inline node query(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return(node){0,0};else if(dl<=l&&r<=dr) return T[x];
	return query(x<<1,l,(l+r)>>1,dl,dr)+query(x<<1|1,((l+r)>>1)+1,r,dl,dr);
}
int main()
{
	read(n),read(m),read(Q),rt=n;for(int i=1;i<=n;i++) read(w[i]),fa[i]=i;
	for(int i=1;i<=m;i++) read(fr[i]),read(tw[i]);
	for(int i=1;i<=Q;i++) read(op[i]),read(vl[i]),op[i]&1?0:vs[vl[i]]=1;
	for(int i=1;i<=m;i++) if(!vs[i]) mrg(fr[i],tw[i]);
	for(int i=Q;i;i--) if(op[i]&1) vl[i]=getf(vl[i]);else mrg(fr[vl[i]],tw[vl[i]]);
	rt++;for(int i=1;i<=rt-1;i++) if(getf(i)==i) adde(rt,i);
	dfs(rt);for(int i=1;i<=rt;i++) modif(1,1,rt,dfn[i],w[i]);
	for(int i=1;i<=Q;i++) if(op[i]&1) {node x=query(1,1,rt,dfn[vl[i]],dfn[vl[i]]+sz[vl[i]]-1);printf("%d\n",x.vl),modif(1,1,rt,x.wh,0);}
	return 0;
}