//Coded by leapfrog on 2021.10.29 {{{
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
int n,m,K,Q,fr[15],tw[15],et=1,head[10005];
int d[10005],cur[10005],q[10005],hd,tl;
struct EDGE
{
	struct edge{int to,w,nxt;}e[20005];
	inline void ADDE(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
	inline void adde(int x,int y,int w) {ADDE(x,y,w),ADDE(y,x,0);}
	inline char bfs(int s,int t)
	{
		memset(d,0,sizeof(d)),q[hd=tl=1]=s,d[s]=1;
		for(int x=s;hd<=tl;x=q[++hd]) if(d[t]) break;else for(int i=head[x];i;i=e[i].nxt)
			if(e[i].w&&!d[e[i].to]) q[++tl]=e[i].to,d[e[i].to]=d[x]+1;
		return !!d[t];
	}
	inline int dfs(int x,int t,int lim=1e9)
	{
		int f=lim;if(x==t) return lim;
		for(int &i=cur[x];i;i=e[i].nxt) if(e[i].w&&d[e[i].to]==d[x]+1)
			{int g=dfs(e[i].to,t,min(f,e[i].w));e[i].w-=g,e[i^1].w+=g,f-=g;if(!f) break;}
		return lim-f;
	}
	inline int dinic(int s,int t) {int r=0;while(bfs(s,t)) memcpy(cur,head,sizeof(cur)),r+=dfs(s,t);return r;}
	inline int ffbfs(int s,int t)
	{
		memset(d,0,sizeof(d)),d[s]=1,q[hd=tl=1]=s;
		for(int x=q[hd];hd<=tl;x=q[++hd]) if(d[t]) break;else for(int i=head[x];i;i=e[i].nxt)
			if(e[i].w&&!d[e[i].to]) {d[e[i].to]=d[x]+1,cur[e[i].to]=i,q[++tl]=e[i].to;if(d[t]) break;}
		int mn=25;if(!d[t]) return 0;else for(int i=t;i!=s;i=e[cur[i]^1].to) mn=min(mn,e[cur[i]].w);
		for(int i=t;i!=s;i=e[cur[i]^1].to) e[cur[i]].w-=mn,e[cur[i]^1].w+=mn;
		return mn;
	}
	inline int ff(int s,int t) {int v=0,r=0;while((v=ffbfs(s,t))) r+=v;return r;}
}E[1025];int vl[1025],lg[1025],we[1025];
inline int maxbit(int w) {for(int i=0;;i++) if(!(w>>i)) return 1<<(i-1);}
int main()
{
	read(n,m,K,Q);for(int i=1,x,y,w;i<=m;i++) read(x,y,w),E[0].adde(x,y,w);
	vl[0]=E[0].dinic(1,n),srand(19260817);for(int i=0;i<K;i++) lg[1<<i]=i;
	for(int i=1;i<(1<<K);i++)
	{
		int ls=rand()%2?i&(-i):maxbit(i),k=lg[ls];E[i]=E[i^ls],vl[i]=vl[i^ls];
		E[i].e[(k+1)<<1].w=25,vl[i]+=E[i].ff(1,n);
	}
	for(int zkak=1;zkak<=Q;zkak++)
	{
		int rs=1e9;for(int i=0;i<K;i++) read(we[1<<i]);
		for(int i=0;i<(1<<K);i++) we[i]=we[i^(i&(-i))]+we[i&(-i)];
		for(int i=0;i<(1<<K);i++) rs=min(rs,vl[i]+we[((1<<K)-1)^i]);
		printf("%d\n",rs);
	}return 0;
}