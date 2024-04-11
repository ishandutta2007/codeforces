//
//
#include<bits/stdc++.h>
using namespace std;const int P=1e9+7;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct edge{int to,nxt,id;}e[600005];
int n,m,et,head[300005],fa[300005],dg[300005],rs[300005],rst=0;
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline char dfs(int x,int fa=0)
{
	int zcyakioi=dg[x];
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa&&dfs(e[i].to,x)) zcyakioi^=1,rs[++rst]=(i+1)>>1;
	if(dg[x]==-1) return 0;else return zcyakioi;
}
int main()
{
	read(n),read(m),et=0,memset(head,0,sizeof(head));int tm=0,nw=-1;
	for(int i=1;i<=n;i++) fa[i]=i,read(dg[i]),~dg[i]?(tm^=dg[i]&1):nw=i;
	for(int i=1,x,y;i<=m;i++) {read(x),read(y);if(getf(x)^getf(y)) adde(x,y),adde(y,x),fa[getf(x)]=getf(y);}
	if(tm&&nw==-1) return puts("-1"),0;else if(nw==-1) nw=1;
	dfs(nw),printf("%d\n",rst),sort(rs+1,rs+rst+1);
	for(int i=1;i<=rst;i++) printf("%d\n",rs[i]);
	return 0;
}