//
//
#include<bits/stdc++.h>
using namespace std;const int P=1e9+7;
template<typename T>inline void read(T &x)
{
	x=0;register char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct edge{int to,w,nxt;}e[200005];
int n,m,et,head[100005],cnt=0,v[100005];
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline int ksm(int x,int q) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void dfs(int x,int w)
{
	if(v[x]!=-1&&v[x]!=w) puts("0"),exit(0);else if(v[x]!=-1) return;else v[x]=w;
	for(int i=head[x];i;i=e[i].nxt) dfs(e[i].to,w^e[i].w);
}
int main()
{
	read(n),read(m),memset(v,-1,sizeof(v));
	for(int i=1,x,y,w;i<=m;i++) read(x),read(y),read(w),w^=1,adde(x,y,w),adde(y,x,w);
	for(int i=1;i<=n;i++) if(v[i]==-1) dfs(i,0),++cnt;
	return printf("%d\n",ksm(2,cnt-1)),0;
}