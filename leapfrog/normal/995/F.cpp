//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
const int P=1e9+7;int n,D,dp[3005][3005],s[3005][3005],res;
struct edge{int to,nxt;}e[3005];int et,head[3005],iv[3005];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs(int x)
{
	for(int i=1;i<=n+1;i++) dp[x][i]=1;
	for(int i=head[x];i;i=e[i].nxt)
	{
		dfs(e[i].to);for(int j=1;j<=n+1;j++)
			dp[x][j]=1ll*dp[x][j]*s[e[i].to][j]%P;
	}
	for(int i=1;i<=n+1;i++) s[x][i]=(s[x][i-1]+dp[x][i])%P;
}
inline int inv(int x) {return x<0?P-iv[-x]:iv[x];}
int main()
{
	read(n),read(D);for(int i=2,f;i<=n;i++) read(f),adde(f,i);
	iv[1]=1;for(int i=2;i<=n+1;i++) iv[i]=1ll*iv[P%i]*(P-P/i)%P;
	dfs(1);for(int i=1,w=1;i<=n+1;(res+=1ll*w*s[1][i]%P)%=P,w=1,i++)
		for(int j=1;j<=n+1;j++) if(i^j) w=1ll*w*(D-j)%P*inv(i-j)%P;
	return printf("%d\n",(res+P)%P),0;
}