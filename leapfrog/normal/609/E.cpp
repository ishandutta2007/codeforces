#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct edge{int to,w,nxt;}e[400005];
struct node{int x,y,w,id;bool operator<(node b) const {return w<b.w;}}a[200005];
int n,m,et,head[200005],ds[200005][20],d[200005],f[200005][20],fa[200005],tmp[200005],tc;ll ans[200005];
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline void dfs(int x,int fa,int ls)
{
	f[x][0]=fa,ds[x][0]=ls,d[x]=d[fa]+1;
	for(int i=1;i<20;i++) f[x][i]=f[f[x][i-1]][i-1],ds[x][i]=max(ds[x][i-1],ds[f[x][i-1]][i-1]);
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs(e[i].to,x,e[i].w);
}
inline int dis(int x,int y)
{
	int res=0;if(d[x]<d[y]) swap(x,y);
	for(int i=19;~i;i--) if(d[f[x][i]]>=d[y]) res=max(res,ds[x][i]),x=f[x][i];
	if(x==y) return res;
	for(int i=19;~i;i--) if(f[x][i]!=f[y][i]) res=max(res,max(ds[x][i],ds[y][i])),x=f[x][i],y=f[y][i];
	return max(res,max(ds[x][0],ds[y][0]));
}
int main()
{
	read(n),read(m),tc=et=0,memset(head,0,sizeof(head));ll tot=0;
	for(int i=1;i<=m;i++) read(a[i].x),read(a[i].y),read(a[i].w),a[i].id=i;
	sort(a+1,a+m+1);for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) if(getf(a[i].x)!=getf(a[i].y)) {int x=a[i].x,y=a[i].y;fa[getf(x)]=getf(y),tmp[++tc]=i,tot+=a[i].w,adde(x,y,a[i].w),adde(y,x,a[i].w);}
	d[0]=0,dfs(1,0,0);for(int i=1;i<=tc;i++) ans[a[tmp[i]].id]=tot;
	for(int i=1;i<=m;i++) if(!ans[a[i].id]) ans[a[i].id]=tot+a[i].w-dis(a[i].x,a[i].y);
	for(int i=1;i<=m;i++) printf("%lld\n",ans[i]);
	return 0;
}