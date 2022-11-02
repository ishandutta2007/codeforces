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
const ll INF=1e9+5;struct edge{int to;ll w;int nxt;}e[7505005];
int s,t,et,head[60005],cur[60005],d[60005];
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
int n,m,gg,X[20005],Y[20005],id[20005],dg[40005],mnd=INF;vector<int>ans[20005];
int main()
{
	read(gg),read(n),n+=gg,read(m),s=n+m+1,t=s+1;
	for(int i=1;i<=m;i++) read(X[i]),read(Y[i]),Y[i]+=gg,dg[X[i]]++,dg[Y[i]]++;
	for(int i=1;i<=m;i++) id[i]=et+1,adde(X[i],Y[i],1);
	for(int i=1;i<=n;i++) mnd=min(mnd,dg[i]);
	for(int i=1;i<=n;i++) if(i<=gg) adde(s,i,dg[i]-mnd);else adde(i,t,dg[i]-mnd);
	for(int k=mnd;~k;k--)
	{
		dinic(s,t);for(int i=1;i<=m;i++) if(e[id[i]].w) ans[k].push_back(i);
		for(int i=head[s];i;i=e[i].nxt) e[i].w++;
		for(int i=head[t];i;i=e[i].nxt) e[rev(i)].w++;
	}
	for(int i=0;i<=mnd;i++,putchar('\n'))
	{
		printf("%d ",(int)ans[i].size());
		for(int j=0;j<(int)ans[i].size();j++) printf("%d ",ans[i][j]);
	}
	return 0;
}