//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x,1:1;
}
struct edge{int to,nxt;}e[200005];int et,head[100005],f[100005][20],dep[100005],dfn[100005],dt;
int Q,n,T[100005],rs[100005],sz[100005],sn[100005];vector<pair<int,int> >p[100005];char avd[100005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs0(int x,int fa)
{
	f[x][0]=fa,dep[x]=dep[fa]+1,sz[x]=1,dfn[x]=++dt;
	for(int i=1;i<20;i++) f[x][i]=f[f[x][i-1]][i-1];
	for(int i=head[x];i;i=e[i].nxt)
	{
		dfs0(e[i].to,x),sz[x]+=sz[e[i].to];
		if(sz[e[i].to]>=sz[sn[x]]) sn[x]=e[i].to;
	}
}
inline int getk(int x,int k) {for(int i=0;i<20;i++) if((k>>i)&1) x=f[x][i];return x;}
inline void baoli(int x,int tg) {T[dep[x]]+=tg;for(int i=head[x];i;i=e[i].nxt) if(!avd[e[i].to]) baoli(e[i].to,tg);}
inline void dfs1(int x,char isw)
{
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=sn[x]) dfs1(e[i].to,0);
	if(sn[x]) dfs1(sn[x],1),avd[sn[x]]=1;else;baoli(x,1),avd[sn[x]]=0;
	//printf("%d : ",x);for(int i=1;i<=n;i++) printf("%d%c",T[i],i==n?'\n':' ');
	for(int i=0;i<(int)p[x].size();i++) rs[p[x][i].second]=T[p[x][i].first+dep[x]]-1;
	if(!isw) baoli(x,-1);
}
int main()
{
	read(n),++n;for(int i=2,x;i<=n;i++) read(x),adde(++x,i);
	dfs0(1,0),read(Q);for(int i=1,x,l;i<=Q;i++)
	{
		read(x),read(l);int fp=getk(++x,l);
		if(fp>1) p[fp].push_back(make_pair(l,i));
	}
	dfs1(1,0);for(int i=1;i<=Q;i++) printf("%d%c",rs[i],i==Q?'\n':' ');
	return 0;
}