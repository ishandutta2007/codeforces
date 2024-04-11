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
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=100005;int n,m,cf[N],f[N][20],dep[N],rs[N];
struct edge{int to,nxt,id;}e[N<<1];int et,head[N];
inline void adde(int x,int y,int id) {e[++et]=(edge){y,head[x],id},head[x]=et;}
inline void dfs0(int x,int fa)
{
	f[x][0]=fa,dep[x]=dep[fa]+1;for(int i=1;i<20;i++) f[x][i]=f[f[x][i-1]][i-1];
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs0(e[i].to,x);
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;~i;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	for(int i=19;~i;i--) if(f[x][i]^f[y][i]) x=f[x][i],y=f[y][i];
	return x^y?f[x][0]:x;
}
inline void dfs1(int x,int fa)
{
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
		dfs1(e[i].to,x),cf[x]+=cf[e[i].to],rs[e[i].id]=cf[e[i].to];
}
int main()
{
	read(n);for(int i=1,x,y;i<n;i++) read(x,y),adde(x,y,i),adde(y,x,i);
	read(m),dfs0(1,0);for(int x,y,l;m--;) read(x,y),l=LCA(x,y),cf[x]++,cf[y]++,cf[l]-=2;
	//for(int i=1;i<=n;i++) printf("%d%c",cf[i],i==n?'\n':' ');
	dfs1(1,0);for(int i=1;i<n;i++) printf("%d%c",rs[i],i==n-1?'\n':' ');
	return 0;
}