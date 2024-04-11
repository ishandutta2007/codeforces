//
#include<bits/stdc++.h>
using namespace std;typedef int ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x,1:1;
}
namespace flow
{
	const ll INF=1e9+5;struct edge{int to;ll w;int nxt;}e[7505005];
	int s,t,et,head[200005],cur[200005],d[200005];
	inline void ADDE(int x,int y,ll w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
	inline void adde(int x,int y,ll w) {ADDE(x,y,w),ADDE(y,x,0);}
	inline char bfs(int s,int t)
	{
		queue<int>q;q.push(s),memset(d,0,sizeof(d)),d[s]=1;
		while(!q.empty())
		{
			int x=q.front();q.pop();
			for(int i=head[x];i;i=e[i].nxt) if(!d[e[i].to]&&e[i].w) q.push(e[i].to),d[e[i].to]=d[x]+1;
		}
		return !!d[t];
	}
	#define rev(x) ((((x)&1)?1:-1)+(x))
	inline ll dfs(int x,int t,ll lim=INF)
	{
		ll f=lim;if(x==t) return lim;
		for(int &i=cur[x];i;i=e[i].nxt) if(d[e[i].to]==d[x]+1&&e[i].w)
			{ll g=dfs(e[i].to,t,min(f,e[i].w));e[i].w-=g,e[rev(i)].w+=g,f-=g;if(!f) break;}
		return lim-f;
	}
	inline ll dinic(int s,int t) {ll r=0;while(bfs(s,t)) memcpy(cur,head,sizeof(cur)),r+=dfs(s,t);return r;}
}using flow::dinic;using flow::INF;const int N=200005;int n,m;char J[N<<3];
namespace seg
{
	using flow::adde;struct segm{int ls,rs;}t[N<<2];int rt,tt;//fa->i
	inline void build(int &x,int l,int r)
	{
		x=++tt;if(l==r) return;else build(t[x].ls,l,(l+r)>>1),build(t[x].rs,((l+r)>>1)+1,r);
		adde(x,t[x].ls,INF),adde(x,t[x].rs,INF);
	}
	inline void linkf(int x,int l,int r,int dl,int dr,int fr)
	{
		if(l>dr||dl>r||dl>dr) return;else if(dl<=l&&r<=dr) return adde(fr,x,INF);
		linkf(t[x].ls,l,(l+r)>>1,dl,dr,fr),linkf(t[x].rs,((l+r)>>1)+1,r,dl,dr,fr);
	}
	inline void linkt(int x,int l,int r,int tw)
	{
		if(l==r) return adde(x,tw,1);
		linkt(t[x].ls,l,(l+r)>>1,tw),linkt(t[x].rs,((l+r)>>1)+1,r,tw);
	}
}
namespace qzlpf//don't forget nfd!!!
{
	struct edge{int to,nxt,id;}e[N<<1];int et,head[N];
	int dep[N],sz[N],sn[N],fa[N],tp[N],dfn[N],nfd[N],dt,nid[N];
	inline void adde(int x,int y,int id) {e[++et]=(edge){y,head[x],id},head[x]=et;}
	inline void dfs0(int x,int fa)
	{
		qzlpf::fa[x]=fa,dep[x]=dep[fa]+1,sz[x]=1,sn[x]=0;
		for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
		{
			dfs0(e[i].to,x),sz[x]+=sz[e[i].to],nid[e[i].to]=e[i].id;
			if(sz[e[i].to]>=sz[sn[x]]) sn[x]=e[i].to;
		}
	}
	inline void dfs1(int x,int top)
	{
		dfn[x]=++dt,nfd[dt]=x,tp[x]=top;if(sn[x]) dfs1(sn[x],top);else return;
		for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa[x]&&e[i].to!=sn[x]) dfs1(e[i].to,e[i].to);
	}
	inline void link(int x,int y,int fr)
	{
		while(tp[x]^tp[y])
		{
			if(dep[tp[x]]<dep[tp[y]]) swap(x,y);
			seg::linkf(seg::rt,1,::n,dfn[tp[x]],dfn[x],fr),x=fa[tp[x]];
		}
		if(dfn[x]>dfn[y]) swap(x,y);
		seg::linkf(seg::rt,1,::n,dfn[x]+1,dfn[y],fr);
	}
}
namespace Fuck_Fuck
{
	using namespace seg;using namespace qzlpf;
	inline void Fuck(int x,int l,int r)
	{
		if(l==r) {if(J[x]) printf("%d ",nid[nfd[l]]);}
		else Fuck(t[x].ls,l,(l+r)>>1),Fuck(t[x].rs,((l+r)>>1)+1,r);
	}
}
int main()
{
	read(n),read(m),seg::build(seg::rt,1,n);using flow::s;using flow::t;
	for(int i=1,x,y;i<n;i++) read(x),read(y),qzlpf::adde(x,y,i),qzlpf::adde(y,x,i);
	qzlpf::dfs0(1,0),qzlpf::dfs1(1,1),s=seg::tt+m+1,t=s+1,seg::linkt(seg::rt,1,n,t);
	for(int i=1,x,y;i<=m;i++) read(x),read(y),flow::adde(s,i+seg::tt,1),qzlpf::link(x,y,i+seg::tt);
	int cnt=0,g;printf("%d\n",g=dinic(s,t));using flow::e;using flow::head;queue<int>q;q.push(s);
	while(!q.empty())
	{
		int x=q.front();q.pop(),J[x]=1;
		for(int i=head[x];i;i=e[i].nxt) if(e[i].w&&!J[e[i].to]) q.push(e[i].to);
	}
	for(int i=1;i<=m;i++) if(!J[i+seg::tt]) cnt++;
	printf("%d ",cnt);for(int i=1;i<=m;i++) if(!J[i+seg::tt]) printf("%d ",i);
	return printf("\n%d ",g-cnt),Fuck_Fuck::Fuck(seg::rt,1,n),putchar('\n'),0;
}