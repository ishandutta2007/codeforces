//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}/*}}}*/
struct edge{int to,nxt;}e[400005];int et,head[200005];
int n,f[200005][20],sz[200005],dep[200005];ll rs[200005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs0(int x,int fa)
{
	f[x][0]=fa,sz[x]=1,dep[x]=dep[fa]+1;for(int i=1;i<20;i++) f[x][i]=f[f[x][i-1]][i-1];
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to^fa) dfs0(e[i].to,x),sz[x]+=sz[e[i].to];
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;~i;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	for(int i=19;~i;i--) if(f[x][i]^f[y][i]) x=f[x][i],y=f[y][i];
	return x^y?f[x][0]:x;
}
inline void solve()
{
	read(n),et=0;for(int i=1;i<=n;i++) head[i]=0;
	for(int i=1,x,y;i<n;i++) read(x),read(y),adde(++x,++y),adde(y,x);
	int ps1=1,ps2=1,szx,szy;dfs0(1,0);for(int i=1;i<=n+1;i++) rs[i]=0;
	int cnt=1;for(int i=head[1];i;i=e[i].nxt) rs[1]+=1ll*sz[e[i].to]*cnt,cnt+=sz[e[i].to];
	for(int i=2;i<=n;i++)
	{
		int x=LCA(ps1,i),y=LCA(ps2,i);
		if(x==ps1&&y==1) {ps1=i;if(x==1) for(int j=i;j^1;szx=sz[j],j=f[j][0]);}
		else if(y==ps2&&x==1) {ps2=i;if(y==1) for(int j=i;j^1;szy=sz[j],j=f[j][0]);}
		else if(x==i||y==i);else break;
		if(ps1==1) rs[i]=1ll*(n-szy)*sz[ps2];
		else if(ps2==1) rs[i]=1ll*sz[ps1]*(n-szx);
		else rs[i]=sz[ps1]*sz[ps2];
	}
	printf("%lld ",1ll*n*(n-1)/2-rs[1]);for(int i=1;i<=n;i++) printf("%lld%c",rs[i]-rs[i+1],i==n?'\n':' ');
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}