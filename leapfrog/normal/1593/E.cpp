#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...dl) {read(x),read(dl...);}/*}}}*/
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
struct edge{int to,nxt;}e[800005];int et,head[400005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
int n,K,dep[400005],f[400005],mxd,mxw,len[400005],rs=0;
inline void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1,f[x]=fa;if(dep[x]>mxd) mxd=dep[x],mxw=x;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs(e[i].to,x);
}
inline void count(int x,int fa)
{
	len[x]=0;for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
		count(e[i].to,x),len[x]=max(len[x],len[e[i].to]);
	len[x]++,rs+=(len[x]>K);
}
inline void solve()
{
	read(n,K);
	et=mxd=mxw=rs=0;for(int i=1;i<=n;i++) head[i]=dep[i]=f[i]=len[i]=0;
	for(int i=1,x,y;i<n;i++) read(x,y),adde(x,y),adde(y,x);
	dfs(1,0);int rt=mxw;mxd=0,dfs(rt,0);int tw=mxw,dm=(dep[tw]>>1);
	for(int i=dm;i>=1;i--) tw=f[tw];
	if(dep[mxw]<=K*2) return puts("0"),void();
	rs=0,count(tw,0),printf("%d\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}