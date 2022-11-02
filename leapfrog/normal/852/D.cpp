//
#include<bits/stdc++.h>
#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
using namespace std;typedef int ll;char buf[1<<21],*p1=buf,*p2=buf;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x,1:1;
}
const ll INF=1e9+5;struct edge{int to;ll w;int nxt;}e[1540005];
int s,t,et,head[1205],cur[1205],d[1205];
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
int n,m,ct,K,w[605],ds[605][605];
inline char check(int md)
{
	et=0,memset(head,0,sizeof(head));
	for(int i=1;i<=n;i++) if(w[i]) adde(s,i,w[i]);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(ds[i][j]<=md) adde(i,j+n,INF);
	for(int i=1;i<=n;i++) adde(i+n,t,1);
	return dinic(s,t)>=K;
}
int main()
{
	read(n),read(m),read(ct),read(K),s=n<<1|1,t=s+1,memset(ds,0x3f,sizeof(ds));
	for(int i=1;i<=n;i++) ds[i][i]=0;
	for(int i=1,x;i<=ct;i++) read(x),w[x]++;
	for(int i=1,x,y,w;i<=m;i++) read(x),read(y),read(w),ds[x][y]=ds[y][x]=min(ds[y][x],w);
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) ds[i][j]=min(ds[i][j],ds[i][k]+ds[k][j]);
	int le=0,ri=1731311,md,rs=ri+1;while(le<=ri) {md=(le+ri)>>1;if(check(md)) rs=md,ri=md-1;else le=md+1;}
	return printf("%d\n",rs>1731311?-1:rs),0;
}