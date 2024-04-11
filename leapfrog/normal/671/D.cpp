//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename t>inline void read(t &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,m,cf[300005],rt[300005],dep[300005],tt;ll res=0;
struct edge{int to,nxt;}e[600005];int et,head[300005];
struct node{int ls,rs,vl,id,ds,lz;}t[300005];
struct tmpn{int x,y,w;}a[300005];vector<int>v[300005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void allp(int x,int c) {if(x) t[x].lz+=c,t[x].vl+=c;}
inline void pushdw(int x) {if(x&&t[x].lz) allp(t[x].ls,t[x].lz),allp(t[x].rs,t[x].lz),t[x].lz=0;}
inline int mrg(int x,int y)
{
	if(!x||!y) return x|y;else pushdw(x),pushdw(y);
	if(t[x].vl>t[y].vl) swap(x,y);
	t[x].rs=mrg(t[x].rs,y);if(t[t[x].ls].ds<t[t[x].rs].ds) swap(t[x].ls,t[x].rs);
	return t[x].ds=t[t[x].rs].ds+1,x;
}
inline void del(int &x) {x=mrg(t[x].ls,t[x].rs);}
inline void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to^fa)
		dfs(e[i].to,x),rt[x]=mrg(rt[x],rt[e[i].to]),cf[x]+=cf[e[i].to];
	if(!cf[x]&&x>1) res=-1e18;
	for(auto i:v[x]) t[++tt]=(node){0,0,a[i].w,i,0,0},rt[x]=mrg(rt[x],tt);
	while(dep[a[t[rt[x]].id].y]>=dep[x]) del(rt[x]);
	if(rt[x]) res+=t[rt[x]].vl,allp(rt[x],-t[rt[x]].vl);
}
int main()
{
	read(n),read(m);for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	for(int i=1,x,y,c;i<=m;i++) read(x),read(y),read(c),cf[x]++,cf[y]--,a[i]=(tmpn){x,y,c},v[x].push_back(i);
	return dfs(1,0),printf("%lld\n",res<0?-1ll:res),0;
}