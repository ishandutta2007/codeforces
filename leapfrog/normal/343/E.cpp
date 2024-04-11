//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),F=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) F=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	F?x=-x:0;
}
template<typename wet,int N>struct My_Flow
{
	struct edge{int to;wet w;int nxt;}e[200005];int et,head[N],d[N],cur[N];
	static const wet INF=(wet)0x3f3f3f3f3f3f3f3f;const int inf=(int)0x3f3f3f3f3f3f3f3f;
	inline void init() {et=1,memset(head,0,sizeof(head));}
	inline void ADDE(int x,int y,wet w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
	inline void adde(int x,int y,wet w) {ADDE(x,y,w),ADDE(y,x,0);}
	inline char bfs(int s,int t)
	{
		int l=1,r=0;cur[++r]=s,memset(d,0x3f,sizeof(d)),d[s]=1;
		for(int x=s;l<=r;x=cur[++l]) for(int i=head[x];i;i=e[i].nxt)
			if(d[e[i].to]>=inf&&e[i].w) d[e[i].to]=d[x]+1,cur[++r]=e[i].to;
		return d[t]<inf;
	}
	inline wet dfs(int x,int t,wet lim)
	{
		wet F=lim;if(x==t) return lim;
		for(int &i=cur[x];i;i=e[i].nxt) if(e[i].w&&d[e[i].to]==d[x]+1)
			{wet g=dfs(e[i].to,t,min(F,e[i].w));e[i].w-=g,e[i^1].w+=g,F-=g;if(!F) break;}
		return lim-F;
	}
	inline wet dinic(int s,int t) {wet r=0;while(bfs(s,t)) memcpy(cur,head,sizeof(cur)),r+=dfs(s,t,INF);return r;}
	inline void reset() {for(int i=2;i<=et;++++i) e[i].w+=e[i^1].w,e[i^1].w=0;}
};My_Flow<int,205>F;int n,m,Q,T,K,id[205],ans=0,tot,fa[205];vector<int>v[205];
struct edge{int x,y,w;bool operator<(edge b) const {return w>b.w;}}e[205];
inline char cmp(int x,int y) {return F.d[x]<F.d[y];}
inline void solve(int l,int r)
{
	if(l==r) return;else e[++tot]=(edge){id[l],id[r],F.dinic(id[l],id[r])};
	sort(id+l,id+r+1,cmp);int wh=-1;for(int i=l;i<=r;i++) if(F.d[id[i]]<F.inf) wh=i;else break;
	F.reset(),solve(l,wh),solve(wh+1,r);
}
inline void vmrg(vector<int>&a,vector<int>&b)
{
	if(a.size()>b.size()) swap(a,b);
	for(int i=0;i<(int)a.size();i++) b.push_back(a[i]);
}
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline void mrg(int x,int y) {x=getf(x),y=getf(y);if(x^y) vmrg(v[x],v[y]),fa[x]=y;}
int main()
{
	read(n),read(m),F.init();for(int i=1;i<=n;i++) id[i]=i;
	for(int i=1,x,y,w;i<=m;i++) read(x),read(y),read(w),F.adde(x,y,w),F.adde(y,x,w);
	solve(1,n),sort(e+1,e+tot+1);for(int i=1;i<=n;i++) fa[i]=i,v[i].push_back(i);
	int res=0;for(int i=1;i<=tot;i++) res+=e[i].w,mrg(e[i].x,e[i].y);printf("%d\n",res);
	int wh=getf(1);for(int i=0;i<n;i++) printf("%d%c",v[wh][i],i==n-1?'\n':' ');
	return 0;
}