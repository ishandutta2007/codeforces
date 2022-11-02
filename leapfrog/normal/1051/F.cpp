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
const int N=100055;int n,m,dep[N],f[N][20],gf[N];ll ds[N];
struct edge{int to,w,nxt;}e[N<<1];int et,head[N],tt=0;
int tn[45],ut,id[N],fr[N],tw[N],we[N];ll di[43][N];char cg[N<<1];
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline void dfs(int x,int fa,int ls)
{
	dep[x]=dep[fa]+1,f[x][0]=fa,ds[x]=ds[fa]+ls;
	for(int i=1;i<20;i++) f[x][i]=f[f[x][i-1]][i-1];
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa&&!cg[i]) dfs(e[i].to,x,e[i].w);
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;~i;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	for(int i=19;~i;i--) if(f[x][i]^f[y][i]) x=f[x][i],y=f[y][i];
	return x^y?f[x][0]:x;
}
inline ll dis(int x,int y) {return ds[x]+ds[y]-(ds[LCA(x,y)]<<1);}
inline void dijk(int s,ll *d)
{
	priority_queue<pair<ll,int> >q;for(int i=1;i<=n;i++) d[i]=1e18;
	for(q.push(make_pair(d[s]=0,s));!q.empty();)
	{
		int x=q.top().second;ll w=-q.top().first;q.pop();if(w!=d[x]) continue;
		for(int i=head[x];i;i=e[i].nxt) if(d[e[i].to]>w+e[i].w)
			q.push(make_pair(-(d[e[i].to]=w+e[i].w),e[i].to));
	}
}
inline int getf(int x) {return gf[x]==x?x:gf[x]=getf(gf[x]);}
inline char mrg(int x,int y) {x=getf(x),y=getf(y);return x^y?gf[x]=y,1:0;}
int main()
{
	read(n,m);for(int i=1,x,y,w;i<=m;i++) read(x,y,w),adde(x,y,w),adde(y,x,w);
	for(int i=1;i<=n;i++) gf[i]=i;
	for(int i=1,u,v;i<=et;i+=2) if(!mrg(u=e[i].to,v=e[i+1].to))
		++tt,fr[tt]=u,tw[tt]=v,we[tt]=e[i].w,cg[i]=cg[i+1]=1;
	dfs(1,0,0);for(int i=1;i<=tt;i++) tn[++ut]=fr[i],tn[++ut]=tw[i];
	sort(tn+1,tn+ut+1),ut=unique(tn+1,tn+ut+1)-tn-1,read(m);
	for(int i=1;i<=ut;i++) id[tn[i]]=i,dijk(tn[i],di[i]);
	for(int x,y;m--;)
	{
		read(x,y);ll rs=dis(x,y);
		for(int i=1;i<=ut;i++) rs=min(rs,di[i][x]+di[i][y]);
		printf("%lld\n",rs);
	}return 0;
}