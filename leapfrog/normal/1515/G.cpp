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
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
const int N=200005;struct edge{int to,w,nxt;}e[N];int n,m,q,et,head[N];
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
int dt,dfn[N],low[N],cl[N],st[N],tp,ct;ll ds[N],gd[N];char tv[N],vs[N];
inline void tarjan(int x)
{
	dfn[x]=low[x]=++dt,st[++tp]=x,tv[x]=1;
	for(int i=head[x];i;i=e[i].nxt)
		if(!dfn[e[i].to]) tarjan(e[i].to),low[x]=min(low[x],low[e[i].to]);
		else if(tv[e[i].to]) low[x]=min(low[x],dfn[e[i].to]);
	if(low[x]==dfn[x]) {int y=++ct;do tv[y=st[tp--]]=0,cl[y]=ct;while(y^x);}
}
inline void dfs(int x,int col)
{
	vs[x]=1;for(int i=head[x];i;i=e[i].nxt) if(cl[e[i].to]==col)
	{
		if(!vs[e[i].to]) ds[e[i].to]=ds[x]+e[i].w,dfs(e[i].to,col);
		else gd[col]=__gcd(gd[col],ds[x]+e[i].w-ds[e[i].to]);
	}
}
int main()
{
	read(n,m);for(int i=1,x,y,w;i<=m;i++) read(x,y,w),adde(x,y,w);
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=n;i++) if(!vs[i]) dfs(i,cl[i]);
	//for(int i=1;i<=n;i++) printf("%d%c",cl[i],i==n?'\n':' ');
	//for(int i=1;i<=ct;i++) printf("%lld%c",gd[i],i==ct?'\n':' ');
	int Ca,v;read(Ca);for(ll s,t;Ca--;) read(v,s,t),puts(s%__gcd(t,gd[cl[v]])?"NO":"YES");
	return 0;
}