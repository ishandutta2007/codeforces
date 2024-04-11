#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
const int N=100005;int n,m,fa[N],ls[N];ll rs[N],vl[N];
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline char mrg(int x,int y) {x=getf(x),y=getf(y);return x^y?fa[x]=y,1:0;}
struct edge{int to,id,nxt;}e[N<<1];int et=1,head[N];
struct ${int x,y,id;}a[N];int at,f[N],dep[N];
inline void adde(int x,int y,int id) {e[++et]=(edge){y,id,head[x]},head[x]=et;}
inline void dfs(int x,int fa)
{
	f[x]=fa,dep[x]=dep[fa]+1;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs(e[i].to,x);
}
inline ll solve(int x,int fa)
{
	ll ret=0;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
		ret+=(rs[e[i].id]=solve(e[i].to,x)),ls[e[i].to]=e[i].id;
	return vl[x]-ret;
}
int main()
{
	read(n,m);for(int i=1;i<=n;i++) fa[i]=i,read(vl[i]);
	for(int i=1,x,y;i<=m;i++)
	{
		read(x,y);
		if(mrg(x,y)) adde(x,y,i),adde(y,x,i);
		else a[++at]=($){x,y,i};
	}
	dfs(1,0);int id=-1;for(int i=1;i<=at;i++) if((dep[a[i].x]+dep[a[i].y])%2==0) id=i;
	if(~id)
	{
		ll vl=solve(a[id].x,0),fg=vl>>1;rs[a[id].id]+=fg;fg=-fg,dfs(a[id].x,0);
		for(int y=a[id].y;y!=a[id].x;y=f[y]) rs[ls[y]]+=fg,fg=-fg;
		puts("YES");for(int i=1;i<=m;i++) printf("%lld\n",rs[i]);
	}else if(solve(1,0)) return puts("NO"),0;
	else {puts("YES");for(int i=1;i<=m;i++) printf("%lld\n",rs[i]);}
	return 0;
}