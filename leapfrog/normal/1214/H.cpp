//{{{
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
const int N=200005;int dep[N],mxd,dw,rt,f[N];char ban[N];
struct edge{int to,nxt;}e[N<<1];int et,head[N],n,K,rs[N],dg[N];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et,dg[x]++;}
inline void dfs0(int x,int fa)
{
	dep[x]=dep[fa]+1,f[x]=fa;if(mxd<dep[x]) mxd=dep[x],dw=x;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs0(e[i].to,x);
}
struct $
{
	int fs,sc,mx;
	inline $ operator+(int b) {return($){fs+b,sc+b,mx};}
	inline $ operator+($ b)
	{
		int a[4]={fs,sc,b.fs,b.sc};sort(a,a+4);
		return ($){a[0],a[1],max(mx,b.mx)};
	}
}d[N];
inline void clor(int x,int fa,int dx)
{
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
		rs[e[i].to]=(rs[x]+dx-1)%K+1,clor(e[i].to,x,dx);
}
inline int fndmx(int x,int fa,int dep)
{
	int rs=0;for(int i=head[x];i;i=e[i].nxt)
		if(e[i].to!=fa&&!ban[e[i].to]) rs=max(rs,fndmx(e[i].to,x,dep+1));
	return max(rs,dep);
}
inline char get(int x,int fa)
{
	int sn=0,fg=0;for(int i=head[x];i;i=e[i].nxt)
		if(e[i].to!=fa) sn++,fg|=get(e[i].to,x);
	return sn>=2||fg;
}
int main()
{
	read(n,K);for(int i=1,x,y;i<n;i++) read(x,y),adde(x,y),adde(y,x);
	if(K==2)
	{
		rs[1]=1,clor(1,0,1),puts("Yes");
		for(int i=1;i<=n;i++) printf("%d%c",rs[i],i==n?'\n':' ');
		return 0;
	}
	mxd=dw=0,dfs0(1,0),rt=dw,mxd=dw=0,dfs0(rt,0);
	int dx=dw,md=(dep[dw]-1)>>1;for(int i=md;i;i--,dx=f[dx]);
	if(!(dep[dw]&1))
	{
		int d1,d2,f1=get(dx,f[dx]),f2=get(f[dx],dx);
		ban[f[dx]]=1,d1=fndmx(dw,0,1),ban[f[dx]]=0;
		ban[dx]=1,d2=fndmx(rt,0,1),ban[dx]=0;
		if((d1>=K&&f1)||(d2>=K&&f2)) return puts("No"),0;
		rs[dx]=1,rs[f[dx]]=K,clor(dx,f[dx],1),clor(f[dx],dx,K-1),puts("Yes");
		for(int i=1;i<=n;i++) printf("%d%c",rs[i],i==n?'\n':' ');
	}
	else
	{
		ban[f[dx]]=1;int d=fndmx(dw,0,1);if(d>=K&&get(dx,f[dx])) return puts("No"),0;
		rs[dx]=1,rs[f[dx]]=K,clor(dx,f[dx],1),clor(f[dx],dx,K-1),puts("Yes");
		for(int i=1;i<=n;i++) printf("%d%c",rs[i],i==n?'\n':' ');
	}return 0;
}