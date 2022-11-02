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
struct edge{int to,nxt;}e[200005];int et,head[105];
const int P=1e9+7;int n,K,dp[105][105],f[105][105];vector<int>v;
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs(int x,int fa)
{
	memset(f[x],0,sizeof(f[x])),f[x][0]=1;
	for(int i=head[x],y;i;i=e[i].nxt) if((y=e[i].to)!=fa)
		{dfs(y,x);for(int j=1;j<=n;j++) f[x][j]=(f[x][j]+f[y][j-1])%P;}
}
inline void solve()
{
	read(n),read(K),et=0,memset(head,0,sizeof(head));int rs=0;
	for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	if(K==2) return printf("%lld\n",(1ll*n*(n-1)/2)%P),void();
	for(int x=1;x<=n;x++)
	{
		dfs(x,0);for(int d=1;d<=n;d++)
		{
			v.clear();for(int i=head[x];i;i=e[i].nxt) v.push_back(f[e[i].to][d-1]);
			memset(dp,0,sizeof(dp)),dp[0][0]=1;for(int i=0;i<(int)v.size();i++)
				{dp[i+1][0]=1;for(int j=0;j<=i;j++) dp[i+1][j+1]=(dp[i][j+1]+1ll*v[i]*dp[i][j])%P;}
			/*if(x==4&&d==1)
			{
				for(int i=0;i<(int)v.size();i++) printf("%d ",v[i]);
				putchar('\n'),putchar('\n');
				for(int i=0;i<=(int)v.size();i++) for(int j=0;j<=i;j++) printf("%d%c",dp[i][j],j==i?'\n':' ');
			}*/
			rs=(rs+dp[(int)v.size()][K])%P;
		}
	}
	printf("%d\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}