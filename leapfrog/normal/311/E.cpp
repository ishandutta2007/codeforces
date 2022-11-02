#include<bits/stdc++.h>
#define int long long
using namespace std;const int INF=(int)0x3f3f3f3f3f3f3f3f;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
template<typename T>inline void write(T x) {{if(x<0) putchar('-'),x=-x;}{if(x>9) write(x/10);}putchar(x%10+48);}
struct edge{int to,w,nxt;}e[500005];
int n,q,g,et,a[100005],head[100005],s,t,d[100005],cr[100005],sm=0;
inline void ADDE(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline void adde(int x,int y,int w) {ADDE(x,y,w),ADDE(y,x,0);}
inline char bfs(int s,int t)
{
	queue<int>q;memset(d,0,sizeof(d)),d[s]=1,q.push(s);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=head[x];i;i=e[i].nxt) if(e[i].w>0&&!d[e[i].to]) d[e[i].to]=d[x]+1,q.push(e[i].to);
	}
	return !!d[t];
}
#define R(x) ((((x)&1)?1:-1)+(x))
inline int dfs(int x,int t,int lim=INF)
{
	int g=lim;if(x==t) return lim;
	for(int i=cr[x];i;cr[x]=i=e[i].nxt) if(d[e[i].to]==d[x]+1&&e[i].w>0)
	{
		int f=dfs(e[i].to,t,min(e[i].w,g));
		e[i].w-=f,e[R(i)].w+=f,g-=f;if(g==0) break;
	}
	return lim-g;
}
inline int dinic(int s,int t) {int r=0;while(bfs(s,t)) memcpy(cr,head,sizeof(cr)),r+=dfs(s,t);return r;}
signed main()
{
	read(n),read(q),read(g),s=n+q+1,t=s+1;
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1,v;i<=n;i++) {read(v);if(a[i]) adde(i,t,v);else adde(s,i,v);}
	for(int z,w,k,x,f,i=1;i<=q;i++)
	{
		read(z),read(w),read(k),sm+=w;
		if(z) while(k--) read(x),adde(x,i+n,INF);else while(k--) read(x),adde(i+n,x,INF);
		read(f);if(z) adde(i+n,t,w+f*g);else adde(s,i+n,w+f*g);
	}
	return write(sm-dinic(s,t)),putchar('\n'),0;
}