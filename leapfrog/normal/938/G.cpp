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
struct node{int u,v,len;}st[400005];int tp=0,et=0,bg[400005];
struct qwq{int x,y,w;}e[400005],q[400005];vector<int>E[800005];
struct xxj
{
	int a[35];
	inline void ins(int x) {for(int i=31;~i;i--) if((x>>i)&1) {if(!a[i]) return(void)(a[i]=x);else x^=a[i];}}
	inline int qry(int r) {for(int i=31;~i;i--) r=min(r,r^a[i]);return r;}
}sjq;
int n,m,qt,fa[200005],ds[200005],len[200005];map<pair<int,int>,int>mp;
inline int getf(int x) {return fa[x]==x?x:getf(fa[x]);}
inline int getd(int x) {return fa[x]==x?0:ds[x]^getd(fa[x]);}
inline void merge(int x,int y,int w)
{
	int u=getf(x),v=getf(y);if(u==v) return;else if(len[u]<len[v]) swap(u,v),swap(x,y);
	st[++tp]=(node){u,v,len[u]},ds[v]=w,len[u]+=len[v]==len[u],fa[v]=u;
}
inline void pop() {int u=st[tp].u,v=st[tp].v;fa[v]=v,len[u]=st[tp].len,ds[v]=0,tp--;}
inline void motif(int x,int l,int r,int dl,int dr,int dc)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return(void)(E[x].push_back(dc));
	motif(x<<1,l,(l+r)>>1,dl,dr,dc),motif(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc);
}
inline void adde(int x,int y,int w,int nw) {mp[make_pair(x,y)]=++et,e[et]=(qwq){x,y,w},bg[et]=nw;}
inline void dele(int x,int y,int nw) {int id=mp[make_pair(x,y)];mp[make_pair(x,y)]=0,motif(1,1,qt,bg[id],nw,id);}
inline void solve(int x,int l,int r,xxj nw)
{
	int nwt=tp;
	for(int i=0;i<(int)E[x].size();i++)
	{
		int id=E[x][i],x=e[id].x,y=e[id].y,w=e[id].w,u=getf(x),v=getf(y);
		w^=getd(x)^getd(y);if(u==v) nw.ins(w);else merge(x,y,w);
	}
	if(l==r&&q[l].w) return(void)(printf("%d\n",nw.qry(getd(q[l].x)^getd(q[l].y))));
	if(l^r) solve(x<<1,l,(l+r)>>1,nw),solve(x<<1|1,((l+r)>>1)+1,r,nw);
	while(tp>nwt) pop();
}
int main()
{
	read(n),read(m);for(int i=1;i<=n;i++) fa[i]=i,len[i]=1,ds[i]=0;
	for(int x,y,w;m--;) read(x),read(y),read(w),adde(min(x,y),max(x,y),w,1);
	read(qt);for(int fg,x,y,w,i=1;i<=qt;i++)
	{
		read(fg),read(x),read(y);
		if(fg==1) read(w),adde(min(x,y),max(x,y),w,i);
		else if(fg==2) dele(min(x,y),max(x,y),i-1);
		else q[i]=(qwq){x,y,1};
	}
	for(auto i:mp) if(i.second) dele(i.first.first,i.first.second,qt);
	return memset(sjq.a,0,sizeof(sjq.a)),solve(1,1,qt,sjq),0;
}