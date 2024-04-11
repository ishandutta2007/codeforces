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
const int N=50005;int n,q,mx[N][257],f[N],ff[N],dep[N],a[N];
struct edge{int to,nxt;}e[N<<1];int et,head[N];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void chkmx(int &x,int y) {x<y?x=y:0;}
inline void dfs0(int x,int fa)
{
	f[x]=fa,dep[x]=dep[fa]+1;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs0(e[i].to,x);
	if(dep[x]<256) return;else ff[x]=x;
	for(int i=0;i<256;i++) chkmx(mx[x][(a[ff[x]]>>8)^255],(a[ff[x]]^i)|(255<<8)),ff[x]=f[ff[x]];
	for(int i=0;i<8;i++) for(int j=0;j<256;j++) chkmx(mx[x][j],mx[x][j^(1<<i)]-(256<<i));
}
int main()
{
	read(n,q);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1,x,y;i<n;i++) read(x,y),adde(x,y),adde(y,x);
	for(dfs0(1,0);q--;)
	{
		int x,y,ds,u,rs=0;read(x,y),ds=dep[y]-dep[x]+1,u=y;
		for(int i=0;i<(ds>>8);i++) rs=max(rs,mx[u][i]),u=ff[u];
		for(int i=(ds>>8)<<8;i<ds;i++) rs=max(rs,a[u]^i),u=f[u];
		printf("%d\n",rs);
	}
	return 0;
}