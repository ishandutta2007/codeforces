//
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct edge{int to,nxt;}e[200005];
int n,et,head[100005],dp[100005][3],de[100005],ds[100005],pa[100005],res;
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void ins(int *a,int w) {if(w>0) {if(a[0]<=w) a[2]=a[1],a[1]=a[0],a[0]=w;else if(a[1]<=w) a[2]=a[1],a[1]=w;else if(a[2]<=w) a[2]=w;}}
inline int dison(int x) {if(dp[x][1]!=-1) return dp[x][0]+dp[x][1];else return dp[x][0];}
inline void dfs1(int x,int fa)
{
	dp[x][0]=dp[x][1]=dp[x][2]=-1,pa[x]=fa;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs1(e[i].to,x),ins(dp[x],dp[e[i].to][0]+1);
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) de[x]=max(de[x],de[e[i].to]);
	if(e[head[x]].to==fa&&!e[head[x]].nxt) dp[x][0]=0;else de[x]=max(de[x],dison(x));
}
inline int disfa(int x,int son)
{
	if(dp[x][1]==-1) return ds[x];
	int w;if(dp[son][0]+1==dp[x][0]) w=dp[x][1];else w=dp[x][0];
	int r;if(dp[son][0]+1==dp[x][1]) r=dp[x][2];else r=dp[x][1];
	if(w==dp[x][1]) return w+max(ds[x],dp[x][2]);else return w+max(r,ds[x]);
}
inline void dfs2(int x,int fa)
{
	if(dp[x][0]+1==dp[fa][0]) ds[x]=max(ds[fa],dp[fa][1])+1;else ds[x]=max(ds[fa],dp[fa][0])+1;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs2(e[i].to,x);
}
int main()
{
	read(n);for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	dfs1(1,0);for(int i=head[1];i;i=e[i].nxt) dfs2(e[i].to,1);
	// for(int i=1;i<=n;i++) printf("%d%c",de[i],i==n?'\n':' ');
	// for(int i=1;i<=n;i++) printf("%d -> %d : %d\n",i,pa[i],disfa(pa[i],i));
	// printf("%d , %d , %d , %d ; %d\n",dp[7][0],dp[7][1],dp[7][2],ds[7],dp[6][0]);
	for(int i=2;i<=n;i++) res=max(res,de[i]*disfa(pa[i],i));
	return printf("%d\n",res),0;
}