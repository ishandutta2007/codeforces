//
#include<bits/stdc++.h>
using namespace std;typedef long long typf;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
struct edge{int to,w,nxt;}e[2551005];int et=1,head[3005],s,t;
int d[3005],cur[3005];const typf INF=(typf)0x3f3f3f3f3f3f3f3f;
inline void ADDE(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline void adde(int x,int y,int w) {ADDE(x,y,w),ADDE(y,x,0);}
inline char	bfs(int s,int t)
{
	queue<int>q;memset(d,0,sizeof(d)),d[s]=1,q.push(s);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=head[x];i;i=e[i].nxt) if(!d[e[i].to]&&e[i].w) q.push(e[i].to),d[e[i].to]=d[x]+1;
	}
	return !!d[t];
}
inline int dfs(int x,int t,int lim=(int)INF)
{
	int f=lim;if(x==t) return lim;
	for(int &i=cur[x];i;i=e[i].nxt) if(e[i].w&&d[e[i].to]==d[x]+1)
		{int g=dfs(e[i].to,t,min(f,e[i].w));e[i].w-=g,e[i^1].w+=g,f-=g;if(!f) break;}
	return lim-f;
}
inline typf dinic(int s,int t) {typf r=0;while(bfs(s,t)) memcpy(cur,head,sizeof(cur)),r+=dfs(s,t);return r;}
int n,a[3005],b[3005];
int main()
{
	read(n),s=n+1,t=s+1;for(int i=1;i<=n;i++) read(a[i]);
	int cnt=0;for(int i=1;i<=n;i++) read(b[i]);
	for(int i=1;i<=n;i++) if(b[i]<0) adde(i,t,-b[i]);else cnt+=b[i],adde(s,i,b[i]);
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(a[j]%a[i]==0&&b[j]>0&&b[i]<0) adde(j,i,(int)INF);
	return printf("%lld\n",cnt-dinic(s,t)),0;
}