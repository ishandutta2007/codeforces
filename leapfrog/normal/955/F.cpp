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
const int N=300005;struct edge{int to,nxt;}e[N<<1];int et,head[N];
int n,ln[N],dp[N][20];ll rs=0;
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs0(int x,int fa)
{
	ln[x]=1;for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
		dfs0(e[i].to,x),ln[x]=max(ln[e[i].to]+1,ln[x]);
	vector<int>v;dp[x][1]=n,rs+=ln[x];for(int k=2;k<20;k++)
	{
		v.clear();for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
			v.push_back(dp[e[i].to][k-1]);
		sort(v.begin(),v.end(),greater<int>());int id=0;
		for(;id<(int)v.size()&&v[id]>=id+1;id++);
		dp[x][k]=id;
	}
}
inline void dfs1(int x,int fa)
{
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs1(e[i].to,x);
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
		for(int k=1;k<20;k++) dp[x][k]=max(dp[x][k],dp[e[i].to][k]);
}
int main()
{
	read(n);for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	dfs0(1,0),dfs1(1,0);for(int i=1;i<=n;i++) for(int j=1;j<20;j++) rs+=max(dp[i][j]-1,0);
	return printf("%lld\n",rs),0;
}