//Coded by Kamiyama_Shiki on 2021.11.08 {{{
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
const int N=200005;int n,a[N],rs=0,f[N][2],g[N][2];
struct edge{int to,nxt;}e[N<<1];int et,head[N];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs(int x,int fa)
{
	if(a[x]==3) g[x][0]=g[x][1]=-1e7,f[x][0]=f[x][1]=0;
	else g[x][a[x]&1]=-1e7,f[x][a[x]&1]=0,g[x][(a[x]&1)^1]=f[x][(a[x]&1)^1]=1e7;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
	{
		int y=e[i].to,vl;dfs(y,x);
		if(a[x]&2) vl=min(f[y][0],f[y][1]+1),g[x][0]=max(g[x][0],f[x][0]+vl),f[x][0]=max(f[x][0],vl);
		if(a[x]&1) vl=min(f[y][1],f[y][0]+1),g[x][1]=max(g[x][1],f[x][1]+vl),f[x][1]=max(f[x][1],vl);
	}rs=max(rs,min(g[x][0],g[x][1]));
	//printf("%d %d ( %d %d )\n",g[x][0],g[x][1],f[x][0],f[x][1]);
}
inline void solve()
{
	read(n),rs=0,et=0;for(int i=1;i<=n;i++) head[i]=0;
	for(int i=1;i<=n;i++) read(a[i]),a[i]=3^a[i];
	for(int i=1,x,y;i<n;i++) read(x,y),adde(x,y),adde(y,x);
	dfs(1,0),printf("%d\n",(rs+1)/2+1);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}