#include<bits/stdc++.h>
using namespace std;
struct edge{int to,tag,nxt;}e[200005];
int n,m,et,head[100005],sz[100005],f[100005],dp[100005];
inline char chk(int x) {while(x) if(x%10!=4&&x%10!=7) return 0;else x/=10;return 1;}
inline void adde(int x,int y,int w) {e[++et]=(edge){y,chk(w),head[x]},head[x]=et;}
inline void dfs1(int x,int fa)
{
	sz[x]=1,f[x]=0;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs1(e[i].to,x),sz[x]+=sz[e[i].to],f[x]+=e[i].tag?sz[e[i].to]:f[e[i].to];
}
inline void dfs2(int x,int fa,int ls)
{
	if(ls) dp[x]=sz[1]-sz[x]+f[x];else dp[x]=dp[fa];
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs2(e[i].to,x,e[i].tag);
}
int main()
{
	scanf("%d",&n);long long r=0;
	for(int i=1,x,y,w;i<n;i++) scanf("%d%d%d",&x,&y,&w),adde(x,y,w),adde(y,x,w);
	dfs1(1,0),dp[1]=f[1];for(int i=head[1];i;i=e[i].nxt) dfs2(e[i].to,1,e[i].tag);
	for(int i=1;i<=n;i++) r=r+1ll*dp[i]*(dp[i]-1);
//	for(int i=1;i<=n;i++) printf("%d%c",dp[i],i==n?'\n':' ');
	return printf("%lld\n",r),0;
}