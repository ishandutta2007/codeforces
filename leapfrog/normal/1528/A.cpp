//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int n,l[100005],r[100005];ll dp[100005][2];
struct edge{int to,nxt;}e[200005];int et,head[100005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs(int x,int fa)
{
	for(int i=head[x],y=e[i].to;i;y=e[i=e[i].nxt].to) if(y!=fa)
		dfs(y,x),dp[x][0]+=max(dp[y][0]+abs(l[y]-l[x]),dp[y][1]+abs(r[y]-l[x])),
			     dp[x][1]+=max(dp[y][0]+abs(l[y]-r[x]),dp[y][1]+abs(r[y]-r[x]));
}
inline void solve()
{
	read(n),et=0,memset(head,0,sizeof(head)),memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++) read(l[i]),read(r[i]);
	for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	dfs(1,0),printf("%lld\n",max(dp[1][0],dp[1][1]));
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}