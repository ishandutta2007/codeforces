#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005,INF=1e18+5;
struct edge{int to,wei,nxt;}e[N<<1];
int n,tot=0,cnt=0,ans1=0,ans2=INF,res,head[N],cir[N],vis[N],f[N],we[N],l[N],l0[N],r[N],r0[N];
inline void adde(int x,int y,int w) {e[++tot]=(edge){y,w,head[x]},head[x]=tot;}
inline int fnd(int x,int fa=-1)
{
	if(vis[x]) return x;else vis[x]=-1;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) {res=fnd(e[i].to,x);if(res) return cir[++cnt]=x,we[cnt]=e[i].wei,vis[x]=1,res==x?0:res;}
	return 0;
}
inline void dfs(int x,int fa=-1)
{
	for(int i=head[x];i;i=e[i].nxt)
		if(vis[e[i].to]!=1&&e[i].to!=fa)
			dfs(e[i].to,x),ans1=max(ans1,f[x]+f[e[i].to]+e[i].wei),f[x]=max(f[x],f[e[i].to]+e[i].wei);
}
signed main()
{
	scanf("%lld",&n),memset(vis,0,sizeof(vis)),memset(f,0,sizeof(f));
	for(int i=1,x,y,w;i<=n;i++) scanf("%lld%lld%lld",&x,&y,&w),adde(x,y,w),adde(y,x,w);
	fnd(1),we[0]=0;for(int i=1;i<=cnt;i++) dfs(cir[i]),we[i]+=we[i-1];
	res=l[0]=l0[0]=-INF;
	for(int i=1;i<=cnt;i++) l0[i]=max(l0[i-1],f[cir[i]]+we[i]+res),l[i]=max(l[i-1],f[cir[i]]+we[i]),res=max(res,f[cir[i]]-we[i]);
	res=r[cnt+1]=r0[cnt+1]=-INF;
	for(int i=cnt;i>=1;i--) r0[i]=max(r0[i+1],f[cir[i]]-we[i]+res),r[i]=max(r[i+1],f[cir[i]]+we[cnt]-we[i]),res=max(res,f[cir[i]]+we[i]);
	for(int i=1;i<=cnt;i++) ans2=min(ans2,max(l[i-1]+r[i],max(l0[i-1],r0[i])));
	return printf("%lld\n",max(ans1,ans2)),0;
}