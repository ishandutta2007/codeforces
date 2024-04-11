//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
struct edge{int x,y,t,w;bool operator<(edge b) const {return w>b.w;}};
struct dsub{int x,y,ds,sz,ct;}st[300005];int tp,fa[300005],ds[300005],sz[300005];
priority_queue<edge>q;vector<edge>T[1200005];int n,m,cnt=0,rs[300005];
inline int getf(int x) {return fa[x]==x?x:getf(fa[x]);}
inline void mrg(int x,int y)
{
	x=getf(x),y=getf(y);if(x==y) return;else if(ds[x]<ds[y]) swap(x,y);
	st[++tp]=(dsub){x,y,ds[x],sz[x],cnt},cnt-=(sz[x]&1)+(sz[y]&1),sz[x]+=sz[y],ds[x]+=ds[x]==ds[y],fa[y]=x,cnt+=sz[x]&1;
}
inline void pop() {int x=st[tp].x,y=st[tp].y;sz[x]=st[tp].sz,ds[x]=st[tp].ds,fa[y]=y,cnt=st[tp].ct,tp--;}
inline void modif(int x,int l,int r,int dl,int dr,edge dc)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return T[x].push_back(dc);
	modif(x<<1,l,(l+r)>>1,dl,dr,dc),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc);
}
inline void solve(int x,int l,int r,int nw)
{
	int ls=tp;for(int i=0;i<(int)T[x].size();i++) mrg(T[x][i].x,T[x][i].y),nw=max(nw,T[x][i].w);
	if(l^r) {solve(x<<1|1,((l+r)>>1)+1,r,nw),solve(x<<1,l,(l+r)>>1,nw);while(tp>ls) pop();return;}
	queue<edge>t;while(cnt&&!q.empty()) {edge x=q.top();q.pop();if(x.t<=l) mrg(x.x,x.y),nw=max(nw,x.w),t.push(x);}
	if(cnt) rs[l]=-1;else {rs[l]=nw;while(!t.empty()) modif(1,1,m,t.front().t,l-1,t.front()),t.pop();}while(tp>ls) pop();
}
int main()
{
	read(n),read(m);for(int i=1;i<=n;i++) fa[i]=i,ds[i]=sz[i]=1;
	for(int i=1,x,y,w;i<=m;i++) read(x),read(y),read(w),q.push((edge){x,y,i,w});
	cnt=n,solve(1,1,m,-1);for(int i=1;i<=m;i++) printf("%d\n",rs[i]);
	return 0;
}