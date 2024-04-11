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
const int N=200005;
struct edge{int to,nxt;}e[N<<1];int n,et,head[N];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
int dep[N],sz[N],sn[N],f[N],dfn[N],nfd[N],tp[N],dt,bt[N],st[N][20];
inline void dfs0(int x,int fa)
{
	sz[x]=1,dep[x]=dep[fa]+1,f[x]=fa,st[x][0]=fa;
	for(int i=1;i<20;i++) st[x][i]=st[st[x][i-1]][i-1];
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
	{
		dfs0(e[i].to,x),sz[x]+=sz[e[i].to];
		if(sz[e[i].to]>=sz[sn[x]]) sn[x]=e[i].to;
	}
}
inline void dfs1(int x,int top)
{
	dfn[x]=++dt,nfd[dt]=x,tp[x]=top,bt[top]=x;if(sn[x]) dfs1(sn[x],top);
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to^f[x]&&e[i].to^sn[x]) dfs1(e[i].to,e[i].to);
}
inline int askd(int x) {printf("d %d\n",x),fflush(stdout);int w;read(w);return w;}
inline int asks(int x) {printf("s %d\n",x),fflush(stdout);int w;read(w);return w;}
inline void answer(int x) {printf("! %d\n",x),fflush(stdout);}
inline int getk(int x,int k) {for(int i=19;~i;i--) if((k>>i)&1) x=st[x][i];return x;}
int main()
{
	read(n);for(int i=1,x,y;i<n;i++) read(x,y),adde(x,y),adde(y,x);
	dfs0(1,0),dfs1(1,1);int nw=1,ls=askd(1);if(!ls) return answer(1),0;
	while(1)
	{
		if(bt[nw]==nw) return answer(nw),0;
		int w=askd(bt[nw]),len=dep[bt[nw]]-dep[nw];
		int d1=(len+w-ls)/2,dk=w-d1,ps=getk(bt[nw],d1);
		if(!dk) return answer(ps),0;else nw=asks(ps),ls=dk-1;
	}
}