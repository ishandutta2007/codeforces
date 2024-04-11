//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x,1:1;
}
const ll INF=1e9+5;struct edge{int to;ll w;int nxt;}e[1540005];
int n,m,s,t,et,head[120005],cur[120005],d[120005];
inline void ADDE(int x,int y,ll w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline void adde(int x,int y,ll w) {ADDE(x,y,w),ADDE(y,x,0);}
inline char bfs(int s,int t)
{
	queue<int>q;q.push(s),memset(d,0,sizeof(d)),d[s]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=head[x];i;i=e[i].nxt) if(!d[e[i].to]&&e[i].w) q.push(e[i].to),d[e[i].to]=d[x]+1;
	}
	return !!d[t];
}
#define rev(x) ((((x)&1)?1:-1)+(x))
inline ll dfs(int x,int t,ll lim=INF)
{
	ll f=lim;if(x==t) return lim;
	for(int &i=cur[x];i;i=e[i].nxt) if(d[e[i].to]==d[x]+1&&e[i].w)
		{ll g=dfs(e[i].to,t,min(f,e[i].w));e[i].w-=g,e[rev(i)].w+=g,f-=g;if(!f) break;}
	return lim-f;
}
inline ll dinic(int s,int t) {ll r=0;while(bfs(s,t)) memcpy(cur,head,sizeof(cur)),r+=dfs(s,t);return r;}
int main()
{
	read(n),read(m),s=n+m+1,t=s+1;ll cnt=0;
	for(int i=1,w;i<=n;i++) read(w),adde(i,t,w);
	for(int i=1,x,y,w;i<=m;i++) read(x),read(y),read(w),cnt+=w,adde(s,i+n,w),adde(i+n,x,INF),adde(i+n,y,INF);
	return printf("%lld\n",cnt-dinic(s,t)),0;
}