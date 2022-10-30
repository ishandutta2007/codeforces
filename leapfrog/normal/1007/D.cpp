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
const int N=100005,M=6000005;vector<int>T[N<<2];
struct edge{int to,nxt;}e[M<<1];int n,m,et,head[M],low[M];
int fa[N],sn[N],sz[N],dep[N],tp[N],stp,st[M],dfn[M],dt,cnt,cl[M],clt;char v[M];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void ADDE(int x,int y) {adde(x,y),adde(y^1,x^1);}
inline void dfs1(int x,int fa)
{
	::fa[x]=fa,dep[x]=dep[fa]+1,sz[x]=1;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
	{
		dfs1(e[i].to,x),sz[x]+=sz[e[i].to];
		if(sz[e[i].to]>sz[sn[x]]) sn[x]=e[i].to;
	}
}
inline void dfs2(int x,int top)
{
	tp[x]=top,dfn[x]=++dt;if(sn[x]) dfs2(sn[x],top);else return;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa[x]&&e[i].to!=sn[x]) dfs2(e[i].to,e[i].to);
}
inline void updat(int x,int l,int r,int dl,int dr,int dw)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return T[x].push_back(dw);
	updat(x<<1,l,(l+r)>>1,dl,dr,dw),updat(x<<1|1,((l+r)>>1)+1,r,dl,dr,dw);
}
inline void modif(int x,int y,int w)
{
	while(tp[x]^tp[y])
	{
		if(dep[tp[x]]<dep[tp[y]]) swap(x,y);
		updat(1,1,n,dfn[tp[x]],dfn[x],w),x=fa[tp[x]];
	}
	if(dep[x]<dep[y]) swap(x,y);
	updat(1,1,n,dfn[y]+1,dfn[x],w);
}
inline void solvee(int x,int l,int r,int w)
{
	int qwq=T[x].size(),u=++cnt,v=cnt+=qwq;
	if(qwq) ADDE((v-1)<<1,v<<1);else ADDE(w<<1,v<<1);
	for(int i=0,y;i<qwq;++i)
	{
		y=T[x][i],ADDE(y,(u+i)<<1);
		if(i) ADDE((i+u-1)<<1,(i+u)<<1),ADDE((i+u-1)<<1,y^1);
		else if(w) ADDE(w<<1,u<<1),ADDE(w<<1,y^1);
	}
	if(l^r) solvee(x<<1,l,(l+r)>>1,v),solvee(x<<1|1,((l+r)>>1)+1,r,v);
}
inline void tarjan(int x)
{
	dfn[x]=low[x]=++dt,st[++stp]=x,v[x]=1;
	for(int i=head[x];i;i=e[i].nxt)
		if(!dfn[e[i].to]) tarjan(e[i].to),low[x]=min(low[x],low[e[i].to]);
		else if(v[e[i].to]) low[x]=min(low[x],dfn[e[i].to]);
	if(low[x]==dfn[x]) {int y=++clt;do v[y=st[stp--]]=0,cl[y]=clt;while(y^x);}
}
int main()
{
	read(n);for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	dfs1(1,0),dfs2(1,1),read(m),et=0;for(int i=1;i<=n;i++) head[i]=0;
	for(int i=2,x,y,e=m<<1|1;i<=e;i++) read(x),read(y),modif(x,y,i);
	memset(dfn,0,sizeof(dfn)),dt=0,cnt=m,solvee(1,1,n,0);
	for(int i=cnt<<1;i;i--) if(!cl[i]) tarjan(i);
	for(int i=1;i<=m;i++) if(cl[i<<1]==cl[i<<1|1]) return puts("NO"),0;
	puts("YES");for(int i=1;i<=m;i++) putchar('1'+(cl[i<<1]>cl[i<<1|1])),putchar('\n');
	return 0;
}