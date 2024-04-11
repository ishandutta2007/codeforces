//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct edge{int to,w,nxt;}e[4005];
struct node{int x,y,w;bool operator<(node b) const {return w<b.w;}}a[4000005];
int n,d[2005][2005],fa[2005],et,head[2005],ds[2005];
inline int getf(int x) {return fa[x]==x?fa[x]:fa[x]=getf(fa[x]);}
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et,e[++et]=(edge){x,w,head[y]},head[y]=et;}
inline void dfs(int x,int fa,int ls) {ds[x]=ds[fa]+ls;for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs(e[i].to,x,e[i].w);}
int main()
{
	read(n),ds[0]=0;int at=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {read(d[i][j]);if((i^j)&&!d[i][j]) return puts("NO"),0;}
	for(int i=1;i<=n;i++) if(d[i][i]) return puts("NO"),0;
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(d[i][j]^d[j][i]) return puts("NO"),0;else a[++at]=(node){i,j,d[i][j]};
	sort(a+1,a+at+1);for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1,tot=0;i<=at&&tot<n;i++) if(getf(a[i].x)!=getf(a[i].y)) fa[getf(a[i].x)]=getf(a[i].y),adde(a[i].x,a[i].y,a[i].w),++tot;
	for(int i=1;i<=n;i++) {dfs(i,0,0);for(int j=1;j<=n;j++) if(ds[j]!=d[i][j]) return puts("NO"),0;}
	return puts("YES"),0;
}