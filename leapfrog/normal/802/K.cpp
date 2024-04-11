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
struct edge{int to,w,nxt;}e[200005];int et,head[100005];
pair<int,int>sn[100005];int n,K,vl[100005],st,dp[100005][2];
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline void dfs(int x,int fa)
{
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs(e[i].to,x);
	st=0;for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
		sn[++st]=make_pair(vl[e[i].to]=dp[e[i].to][0]+e[i].w,e[i].to);
	sort(sn+1,sn+st+1,greater<pair<int,int> >());int tot=0;
	for(int i=1;i<=st;i++) {dp[x][0]+=sn[i].first;if(i>=K-1) break;}
	for(int i=1;i<=st;i++) {tot+=sn[i].first;if(i>=K) break;}
	for(int i=1,y;i<=st;i++)
		{y=sn[i].second,dp[x][1]=max(dp[x][1],tot+dp[y][1]-dp[y][0]);if(i>=K) break;}
}
int main()
{
	read(n),read(K);for(int i=1,x,y,w;i<n;i++)
		read(x),read(y),x++,y++,read(w),adde(x,y,w),adde(y,x,w);
	return dfs(1,0),printf("%d\n",dp[1][1]),0;
}