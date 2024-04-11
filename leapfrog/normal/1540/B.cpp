//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
const int P=1e9+7,I2=(P+1)>>1;char lcv[205];int dp[205][205];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
struct edge{int to,nxt;}e[405];int et,head[205],n,lc[205][205],dep[205];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs0(int x,int fa)
{
	for(int i=1;i<=n;i++) if(lcv[i]) lc[i][x]=lc[x][i]=lc[fa][i];
	lcv[x]=1,lc[x][x]=x,dep[x]=dep[fa]+1;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs0(e[i].to,x);
}
int main()
{
	read(n);for(int i=1,x,y;i<n;i++) read(x,y),adde(x,y),adde(y,x);
	for(int i=0;i<=n;i++) dp[0][i]=1;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=1ll*(dp[i-1][j]+dp[i][j-1])*I2%P;
	//for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) printf("%d%c",dp[i][j],j==n?'\n':'\t');
	int rs=0;for(int rt=1;rt<=n;rt++)
	{
		dfs0(rt,0);for(int x=1,l;x<=n;x++) for(int y=1;y<x;y++)
			l=lc[x][y],rs=(rs+dp[dep[x]-dep[l]][dep[y]-dep[l]])%P;
	}
	return printf("%lld\n",1ll*rs*ksm(n)%P),0;
}