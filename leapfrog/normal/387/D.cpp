#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
const int INF=1e9;
struct edge{int to;int w;int nxt;}e[2000005];
int n,m,s,t,et,head[10005],cur[10005],d[10005],mp[505][505],fr[1005],to[1005];
inline void ADDE(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline void adde(int x,int y,int w) {ADDE(x,y,w),ADDE(y,x,0);}
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
inline int dfs(int x,int t,int lim=INF)
{
	int f=lim;if(x==t) return lim;
	for(int &i=cur[x];i;i=e[i].nxt) if(d[e[i].to]==d[x]+1&&e[i].w)
		{int g=dfs(e[i].to,t,min(f,e[i].w));e[i].w-=g,e[rev(i)].w+=g,f-=g;if(!f) break;}
	return lim-f;
}
#undef rev
inline int dinic(int s,int t) {int r=0;while(bfs(s,t)) memcpy(cur,head,sizeof(cur)),r+=dfs(s,t);return r;}
int main()
{
	read(n),read(m),s=n<<1|1,t=s+1;int res=INF;
	for(int i=1,x,y;i<=m;i++) read(x),read(y),mp[x][y]=1,fr[i]=x,to[i]=y;
	for(int i=1;i<=n;i++)
	{
		memset(head,0,sizeof(head)),et=0;int tp=0;
		for(int j=1;j<=n;j++) adde(s,j,1);
		for(int j=1;j<=n;j++) adde(j+n,t,1);
		for(int j=1;j<=m;j++) if(fr[j]!=i&&to[j]!=i) tp++,adde(fr[j],to[j]+n,1);
		for(int j=1;j<=n;j++) tp+=!mp[i][j],tp+=!mp[j][i];tp-=!mp[i][i];
		res=min(res,n-(dinic(s,t)<<1)+tp-1);
	}
	return printf("%d\n",res),0;
}