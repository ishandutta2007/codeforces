//
#include<bits/stdc++.h>
using namespace std;typedef int ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x,1:1;
}
const ll INF=1e9+5;struct edge{int to;ll w;int nxt;}e[1540005];
int s,t,et,head[120005],cur[120005],d[120005];
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
int n,B,Q;pair<int,int>p[100005];
int main()
{
	read(n),read(B),read(Q),s=7+Q+B,t=s+1;
	for(int i=1;i<=Q;i++) read(p[i].first),read(p[i].second);
	sort(p+1,p+Q+1),p[Q+1]=make_pair(B,n),++Q;
	for(int i=1;i<=5;i++) adde(s,i,n/5);
	for(int i=1;i<=B;i++) adde(i%5+1,i+5,1);
	for(int i=1;i<=Q;i++)
		if(p[i].second<p[i-1].second||p[i].second-p[i-1].second>p[i].first-p[i-1].first) return puts("unfair"),0;
		else adde(i+B+5,t,p[i].second-p[i-1].second);
	for(int i=1;i<=Q;i++) for(int j=p[i-1].first+1;j<=p[i].first;j++) adde(j+5,i+B+5,1);
	return puts(dinic(s,t)==n?"fair":"unfair"),0;
}