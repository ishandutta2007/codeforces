//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
const int P=998244353;
struct edge{int to,nxt;}e[600005];int et,head[300005];
int n,K,col[300005],dep[300005],dp[300005][2],tim[300005],pa[300005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void dfs0(int x,int fa) {dep[x]=dep[fa]+1,pa[x]=fa;for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs0(e[i].to,x);}
inline void dfs1(int x,int fa)
{
	int res=1;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs1(e[i].to,x),res=1ll*res*(dp[e[i].to][0]+dp[e[i].to][1])%P;
	if(col[x]) return(void)(dp[x][0]=res,dp[x][1]=0);else dp[x][0]=0,dp[x][1]=res;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dp[x][0]=(dp[x][0]+1ll*res*dp[e[i].to][0]%P*ksm(dp[e[i].to][0]+dp[e[i].to][1])%P)%P;
}
int main()
{
	read(n),K=2;for(int i=1;i<=n;i++) read(col[i]),tim[col[i]]++;
	for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	dfs0(1,0);priority_queue<pair<int,int> >q;for(int i=1;i<=n;i++) if(col[i]) q.push(make_pair(dep[i],i));
	while(!q.empty())
	{
		int x=q.top().second;q.pop();if(!pa[x]) continue;
		if(col[x]==col[pa[x]]) {tim[col[x]]--;continue;}
		if(tim[col[x]]!=1) {if(col[pa[x]]) return puts("0"),0;else col[pa[x]]=col[x],q.push(make_pair(dep[pa[x]],pa[x]));}
	}
	return dfs1(1,0),printf("%d\n",dp[1][0]),0;
}