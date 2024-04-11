//Coded by Kamiyama_Shiki on 2021.11.09 {{{
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
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=300005;const ll INF=1e18;
struct mat
{
	ll a[2][2];ll*operator[](int x){return a[x];}
	mat(ll x=0,ll t=INF,ll b=INF,ll l=0) {a[0][0]=x,a[0][1]=t,a[1][0]=b,a[1][1]=l;}
	mat operator*(mat b)
	{
		mat r;
		r[0][0]=min(a[0][0]+b[0][0],a[0][1]+b[1][0]);
		r[0][1]=min(a[0][0]+b[0][1],a[0][1]+b[1][1]);
		r[1][0]=min(a[1][0]+b[0][0],a[1][1]+b[1][0]);
		r[1][1]=min(a[1][0]+b[0][1],a[1][1]+b[1][1]);
		return r;
	}
}a[N],az[N],af[N],sz[N][19],sf[N][19];ll w[N];
struct edge{int to,nxt;mat w;}e[N<<1];int et,head[N],n,m,f[N][19],dep[N];
inline void Adde(int x,int y,mat w) {e[++et]=(edge){y,head[x],w},head[x]=et;}
inline void adde(int x,int y,mat w) {Adde(x,y,w),Adde(y,x,w);}
inline void dfs0(int x,int fa)
{
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
		w[e[i].to]=min(w[x]+e[i].w[0][0]+e[i].w[1][1],w[e[i].to]),dfs0(e[i].to,x);
}
inline void dfs1(int x,int fa)
{
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
		dfs1(e[i].to,x),w[x]=min(w[e[i].to]+e[i].w[0][0]+e[i].w[1][1],w[x]);
}
inline void dfs2(int x,int fa)
{
	for(int i=head[x],y;i;i=e[i].nxt) if((y=e[i].to)!=fa)
		az[y]=a[y]*e[i].w,af[y]=e[i].w*a[y],dfs2(y,x);
}
inline void dfs3(int x,int fa)
{
	dep[x]=dep[fa]+1,f[x][0]=fa,sz[x][0]=az[x],sf[x][0]=af[x];
	for(int i=1;i<19;i++)
	{
		f[x][i]=f[f[x][i-1]][i-1];
		sz[x][i]=sz[x][i-1]*sz[f[x][i-1]][i-1];
		sf[x][i]=sf[f[x][i-1]][i-1]*sf[x][i-1];
	}
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs3(e[i].to,x);
}
inline mat solve(int x,int y)
{
	mat rx,ry;
	for(int i=18;~i;i--) if(dep[f[x][i]]>=dep[y]) rx=rx*sz[x][i],x=f[x][i];
	for(int i=18;~i;i--) if(dep[f[y][i]]>=dep[x]) ry=sf[y][i]*ry,y=f[y][i];
	if(x==y) return rx*a[x]*ry;
	for(int i=18;~i;i--) if(f[x][i]^f[y][i])
		rx=rx*sz[x][i],ry=sf[y][i]*ry,x=f[x][i],y=f[y][i];
	return rx=rx*sz[x][0],ry=sf[y][0]*ry,rx*a[f[x][0]]*ry;
}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(w[i]);
	for(int i=1,x,y;i<n;i++) {ll w1,w2;read(x,y,w1,w2),adde(x,y,mat(w1,INF,INF,w2));}
	dfs1(1,0),dfs0(1,0);for(int i=1;i<=n;i++) a[i]=mat(0,w[i],w[i],0);
	dfs2(1,0),dfs3(1,0),read(m);for(int x,y;m--;)
		read(x,y),x++,y++,printf("%lld\n",solve(x>>1,y>>1)[x&1][y&1]);
	return 0;
}