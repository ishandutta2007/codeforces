#include<bits/stdc++.h>//{{{
#define debug(...) fprintf(stderr,__VA_ARGS__),fflush(stderr)
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
namespace Flow//{{{
{
	struct edge{int to;ll w;int nxt;}e[2000005];int et=1,head[55];
	int n,m,s,t,d[55],cur[55];
	inline void init() {et=1,memset(head,0,sizeof(head));}
	inline void ADDE(int x,int y,ll w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
	inline void adde(int x,int y,ll w) {ADDE(x,y,w),ADDE(y,x,0);}
	inline char bfs(int s,int t)
	{
		int hd,tl;cur[hd=tl=1]=s,memset(d,0,sizeof(d)),d[s]=1;
		for(int x=s;hd<=tl;x=cur[++hd]) for(int i=head[x];i;i=e[i].nxt)
			if(e[i].w&&!d[e[i].to]) cur[++tl]=e[i].to,d[e[i].to]=d[x]+1;
		return !!d[t];
	}
	inline ll dfs(int x,int t,ll lim=1e18)
	{
		ll f=lim;if(x==t) return lim;
		for(int &i=cur[x];i;i=e[i].nxt) if(e[i].w&&d[e[i].to]==d[x]+1)
			{ll g=dfs(e[i].to,t,min(f,e[i].w));e[i].w-=g,e[i^1].w+=g,f-=g;if(!f) break;}
		return lim-f;
	}
	inline ll dinic(int s,int t) {ll r=0;while(bfs(s,t)) memcpy(cur,head,sizeof(cur)),r+=dfs(s,t);return r;}
}//}}}
int n,m,X,fr[505],tw[505],we[505];
inline char chk(double w)
{
	Flow::init();for(int i=1;i<=m;i++) Flow::adde(fr[i],tw[i],we[i]/w);
	return Flow::dinic(1,n)>=X;
}
int main()
{
	read(n,m,X);for(int i=1;i<=m;i++) read(fr[i],tw[i],we[i]);
	double l=0,r=1e6;for(int i=60;i;i--) if(chk((l+r)/2)) l=(l+r)/2;else r=(l+r)/2;
	return printf("%.10lf\n",X*l),0;
}