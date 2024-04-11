//Coded by Kamiyama_Shiki on 2021.11.01 {{{
//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=5005,P=998244353;
struct edge{int to,nxt;}e[N<<1];int et,head[N],n,K,dp[N][N],tp[N];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline int dfs(int x,int fa)
{
	int sz=1;dp[x][0]=1;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
	{
		int nx=dfs(e[i].to,x),y=e[i].to;
		for(int k=0;k<=sz+nx;k++) tp[k]=0;
		for(int j=0;j<=sz;j++) for(int k=0;k<=nx;k++)
		{
			tp[j]=(tp[j]+1ll*dp[y][k]*dp[x][j])%P;
			if(j+k+1<=K) tp[max(j,k+1)]=(tp[max(j,k+1)]+1ll*dp[x][j]*dp[y][k])%P;
		}
		sz=max(sz,nx+1);for(int i=0;i<=sz;i++) dp[x][i]=tp[i];
	}return sz;
}
int main()
{
	read(n,K);for(int i=1,x,y;i<n;i++) read(x,y),adde(x,y),adde(y,x);
	int sm=0,mx=dfs(1,0);for(int i=0;i<=mx;i++) sm=(sm+dp[1][i])%P;
	return printf("%d\n",sm),0;
}