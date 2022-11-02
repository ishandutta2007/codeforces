//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
struct edge{int to,nxt;}e[200005];int et,head[100005];vector<pair<int,int> >q[100005];
int n,m,sz[100005],sn[100005],cl[100005],T[100005],ct[100005],rs[100005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void add(int x,int w) {if(x) for(;x<=100000;x+=x&(-x)) T[x]+=w;}
inline int qry(int x) {int r=0;for(;x;x-=x&(-x)) r+=T[x];return r;}
inline void dfs0(int x,int fa)
{
	sz[x]=1;for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
	{
		dfs0(e[i].to,x),sz[x]+=sz[e[i].to];
		if(sz[e[i].to]>=sz[sn[x]]) sn[x]=e[i].to;
	}
}
inline void pls(int x,int tg) {add(ct[x],-1),ct[x]+=tg,add(ct[x],1);}
inline void baoli(int x,int fa,int tg) {pls(cl[x],tg);for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) baoli(e[i].to,x,tg);}
inline void dfs1(int x,int fa,char tg)
{
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa&&e[i].to!=sn[x]) dfs1(e[i].to,x,1);
	if(sn[x]) dfs1(sn[x],x,0),pls(cl[x],1);else pls(cl[x],1);
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa&&e[i].to!=sn[x]) baoli(e[i].to,x,1);
	//printf("%d : ",x);for(int i=1;i<=n;i++) printf("%d%c",ct[i],i==n?'\n':' ');
	for(int i=0;i<(int)q[x].size();i++) rs[q[x][i].second]=qry(100000)-qry(q[x][i].first-1);
	if(tg) baoli(x,fa,-1);
}
int main()
{
	read(n),read(m);for(int i=1;i<=n;i++) read(cl[i]);
	for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	dfs0(1,0);for(int i=1,x,k;i<=m;i++) read(x),read(k),q[x].push_back(make_pair(k,i));
	dfs1(1,0,0);for(int i=1;i<=m;i++) printf("%d\n",rs[i]);
	return 0;
}