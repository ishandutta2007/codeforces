//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
const int P=998244353;int n,dp[1505][1505],cnt=0;
struct node{int u,v,w;bool operator<(node b) const {return w<b.w;}}q[2250005];
struct edge{int to,nxt;}e[3005];int rt,et,head[3005],fa[3005],sz[3005],te[3005];
int qt,a[1505][1505],L[3005],R[3005];char tg[3005];vector<int>v[1505];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline void add(int x) {tg[x]=(++te[x]==1ll*sz[x]*(sz[x]-1)/2);}
inline void mrg(int x,int y)
{
	x=getf(x),y=getf(y);if(x==y) return add(x);++rt,adde(rt,x),adde(rt,y);
	sz[rt]=sz[x]+sz[y],te[rt]=te[x]+te[y],fa[x]=fa[y]=fa[rt]=rt,add(rt);
}
inline void dfs(int x)
{
	if(x<=n) return L[x]=R[x]=++cnt,void();else L[x]=n+1;
	for(int i=head[x];i;i=e[i].nxt) dfs(e[i].to),L[x]=min(L[x],L[e[i].to]);
	R[x]=cnt;if(tg[x]) v[R[x]].push_back(L[x]);
}
int main()
{
	read(n),rt=n;for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1,te[i]=0,tg[i]=1,v[i].push_back(i);
	for(int i=1,x;i<=n;i++) for(int j=1;j<=n;j++) {read(x);if(i<j) q[++qt]=(node){i,j,x};}
	sort(q+1,q+qt+1);for(int i=1;i<=qt;i++) mrg(q[i].u,q[i].v);
	dfs(rt),dp[0][0]=1;for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) for(auto k:v[i]) dp[i][j]=(dp[i][j]+dp[k-1][j-1])%P;
	for(int i=1;i<=n;i++) printf("%d%c",dp[n][i],i==n?'\n':' ');
	return 0;
}