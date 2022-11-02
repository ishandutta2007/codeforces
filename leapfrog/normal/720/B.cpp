//Coded by leapfrog on 2021.11.11 {{{
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
namespace Flow/*{{{*/
{
	struct edge{int to,w,nxt;}e[1000005];int et=1,head[N],d[N],cur[N];
	inline void ADDE(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
	inline void adde(int x,int y,int w) {ADDE(x,y,w),ADDE(y,x,0);}
	inline char bfs(int s,int t)
	{
		int hd=1,tl=1;cur[1]=s,memset(d,0,sizeof(d)),d[s]=1;
		for(int x=s;hd<=tl;x=cur[++hd]) for(int i=head[x];i;i=e[i].nxt)
			if(!d[e[i].to]&&e[i].w) d[cur[++tl]=e[i].to]=d[x]+1;
		return !!d[t];
	}
	inline int dfs(int x,int t,int lim=1e9)
	{
		int f=lim;if(x==t) return lim;
		for(int &i=cur[x];i;i=e[i].nxt) if(d[e[i].to]==d[x]+1&&e[i].w)
			{int g=dfs(e[i].to,t,min(f,e[i].w));e[i].w-=g,e[i^1].w+=g,f-=g;if(!f) break;}
		return lim-f;
	}
	inline int dinic(int s,int t) {int r=0;while(bfs(s,t)) memcpy(cur,head,sizeof(cur)),r+=dfs(s,t);return r;}
}/*}}}*/
int n,m,a[N],s,t,ls[N],idt,dep[N],fg[N];
struct edge{int to,w,nxt;}e[N];int et=1,head[N];
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline void circ(int id)
{
	int x=e[id^1].to,cnt=0;Flow::adde(++idt,e[id].w+m,1),fg[id]=fg[id^1]=1;
	for(;x^e[id].to;x=e[ls[x]^1].to) Flow::adde(idt,e[ls[x]].w+m,1),cnt++,fg[ls[x]]=fg[ls[x]^1]=1;
	Flow::adde(s,idt,cnt);
}
inline void dfs(int x)
{
	dep[x]=dep[e[ls[x]^1].to]+1;
	for(int i=head[x];i;i=e[i].nxt)
		if(!dep[e[i].to]) ls[e[i].to]=i,dfs(e[i].to);
		else if(dep[e[i].to]<dep[x]&&(i^ls[x]^1)) circ(i);
}
int main()
{
	read(n,m),s=m*2+1,t=s+1;for(int i=m+1;i<=m+m;i++) Flow::adde(i,t,1);
	for(int i=1,x,y,w;i<=m;i++) read(x,y,w),adde(x,y,w),adde(y,x,w);
	dfs(1);for(int i=2;i<=et;i+=2) if(!fg[i]) Flow::adde(s,++idt,1),Flow::adde(idt,e[i].w+m,1);
	return printf("%d\n",Flow::dinic(s,t)),0;
}