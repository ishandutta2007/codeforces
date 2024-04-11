#include<bits/stdc++.h>
using namespace std;const int P=1e9+7;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct edge{int to,nxt;}e[200005];
int n,m,k,X,et,head[100005],sz[100005];long long f[100005][15][3],g[15][3];//0<k1=k2>k
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs(int x,int fa)
{
	sz[x]=1,f[x][0][0]=k-1,f[x][1][1]=1,f[x][0][2]=m-k;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs(e[i].to,x),sz[x]+=sz[e[i].to],sz[x]=min(sz[x],X);
	for(int i=head[x];i;i=e[i].nxt)
	{
		int y=e[i].to;memset(g,0,sizeof(g));if(y==fa) continue;
		for(int j=0;j<=sz[x];j++) for(int k=0;k<=sz[y];k++)
		{
			if(j+k>X) break;
			g[j+k][0]=(g[j+k][0]+1ll*(f[y][k][0]+f[y][k][1]+f[y][k][2])%P*f[x][j][0]%P)%P;
			g[j+k][1]=(g[j+k][1]+1ll*f[y][k][0]*f[x][j][1]%P)%P;
			g[j+k][2]=(g[j+k][2]+1ll*(f[y][k][0]+f[y][k][2])%P*f[x][j][2]%P)%P;
		}
		memcpy(f[x],g,sizeof(g));
	}
	// printf("%d : ",x);for(int j=0;j<=X;j++) printf("%lld,%lld,%lld%c",f[x][j][0],f[x][j][1],f[x][j][2],j!=X?' ':'\n');
}
int main()
{
	read(n),read(m),et=0,memset(head,0,sizeof(head));long long tot=0;
	for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	read(k),read(X);
	dfs(1,0);for(int j=0;j<=X&&j<=sz[1];j++) tot=(tot+f[1][j][0]+f[1][j][1]+f[1][j][2])%P;
	return printf("%lld\n",tot),0;
}