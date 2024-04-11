//
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
struct node{int x,y,w,id;bool operator<(const node &b) const {return w<b.w;}}a[1000005];
struct edge{int to,w,nxt;}e[200005];
int n,m,et,head[100005],pa[100005][20],ds[100005][20],fa[100005],d[100005],rs[1000005];
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline void dfs(int x,int fa,int ls)
{
	d[x]=d[fa]+1,ds[x][0]=ls,pa[x][0]=fa;
	for(int i=1;i<20;i++) pa[x][i]=pa[pa[x][i-1]][i-1],ds[x][i]=max(ds[x][i-1],ds[pa[x][i-1]][i-1]);
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs(e[i].to,x,e[i].w);
}
inline int LCA(int x,int y)
{
	int mx=0;if(d[x]<d[y]) swap(x,y);
	for(int i=19;~i;i--) if(d[pa[x][i]]>=d[y]) mx=max(mx,ds[x][i]),x=pa[x][i];
	if(x==y) return mx;
	for(int i=19;~i;i--) if(pa[x][i]!=pa[y][i]) mx=max(mx,max(ds[x][i],ds[y][i])),x=pa[x][i],y=pa[y][i];
	return max(mx,max(ds[x][0],ds[y][0]));
}
int main()
{
	read(n),read(m),et=0,memset(head,0,sizeof(head)),memset(ds,0x3f,sizeof(ds));
	for(int i=1;i<=m;i++) read(a[i].x),read(a[i].y),read(a[i].w),a[i].id=i;
	memset(rs,-1,sizeof(rs)),sort(a+1,a+m+1);for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) if(getf(a[i].x)!=getf(a[i].y))
		{adde(a[i].x,a[i].y,a[i].w),adde(a[i].y,a[i].x,a[i].w),a[i].id=0,fa[getf(a[i].x)]=getf(a[i].y);}
	dfs(1,0,0);for(int i=1;i<=m;i++) if(a[i].id) rs[a[i].id]=LCA(a[i].x,a[i].y);
	for(int i=1;i<=m;i++) if(~rs[i]) printf("%d\n",rs[i]);
	return 0;
}