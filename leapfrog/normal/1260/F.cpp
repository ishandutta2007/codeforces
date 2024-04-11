//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}
template<typename T,typename...L>
inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
//dep[x]+dep[y]-dep[LCA(x,y)]*2
// DSU
const int P=1e9+7,N=100005;int n,L[N],R[N],ln[N],w[N];
struct edge{int to,nxt;}e[N<<1];int et,head[N],iv[N],tt;
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
struct seg{int sm,tg,ln;}T[N<<2];int rs=0,sz[N],dep[N],sn[N];
inline void allc(int x,int d) {T[x].sm=(T[x].sm+1ll*T[x].ln*d)%P,(T[x].tg+=d)%=P;}
inline void pushdw(int x) {if(T[x].tg) allc(x<<1,T[x].tg),allc(x<<1|1,T[x].tg),T[x].tg=0;}
inline void pushup(int x) {T[x].sm=(T[x<<1].sm+T[x<<1|1].sm)%P;}
inline void build(int x,int l,int r)
{
	T[x].ln=r-l+1,T[x].sm=T[x].tg=0;if(l==r) return;
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),pushup(x);
}
inline void modif(int x,int l,int r,int dl,int dr,int dc)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allc(x,dc);else pushdw(x);
	modif(x<<1,l,(l+r)>>1,dl,dr,dc),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc),pushup(x);
}
inline int query(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return 0;else if(dl<=l&&r<=dr) return T[x].sm;else pushdw(x);
	return (query(x<<1,l,(l+r)>>1,dl,dr)+query(x<<1|1,((l+r)>>1)+1,r,dl,dr))%P;
}
inline void dfs0(int x,int fa)
{
	sz[x]=1,dep[x]=dep[fa]+1;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
	{
		dfs0(e[i].to,x),sz[x]+=sz[e[i].to];
		if(sz[e[i].to]>sz[sn[x]]) sn[x]=e[i].to;
	}
}
inline void clean(int x,int fa)
{
	modif(1,1,100000,L[x],R[x],P-w[x]);
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) clean(e[i].to,x);
}
inline void insrt(int x,int fa)
{
	modif(1,1,100000,L[x],R[x],w[x]);
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) insrt(e[i].to,x);
}
inline void add(int x,int rt) {rs=(rs+P-2ll*query(1,1,100000,L[x],R[x])*dep[rt]%P*iv[ln[x]]%P)%P;}
inline void calc(int x,int fa,int rt)
	{add(x,rt);for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) calc(e[i].to,x,rt);}
inline void solve(int x,int fa)
{
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa&&e[i].to!=sn[x]) solve(e[i].to,x),clean(e[i].to,x);
	{if(sn[x]) solve(sn[x],x);add(x,x),modif(1,1,100000,L[x],R[x],w[x]);}
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa&&e[i].to!=sn[x]) calc(e[i].to,x,x),insrt(e[i].to,x);
}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(L[i],R[i]),ln[i]=R[i]-L[i]+1;
	for(int i=1,x,y;i<n;i++) read(x,y),adde(x,y),adde(y,x);
	dfs0(1,0),iv[1]=1;for(int i=2;i<=100000;i++) iv[i]=1ll*iv[P%i]*(P-P/i)%P;
	tt=1,build(1,1,100000);for(int i=1;i<=n;i++) tt=1ll*tt*ln[i]%P;
	for(int i=1;i<=n;i++) modif(1,1,100000,L[i],R[i],w[i]=1ll*tt*iv[ln[i]]%P);
	for(int i=1;i<=n;i++) rs=(rs+1ll*(query(1,1,100000,L[i],R[i])-tt+P)*iv[ln[i]]%P*dep[i])%P;
	return build(1,1,100000),solve(1,0),printf("%d\n",rs),0;
}