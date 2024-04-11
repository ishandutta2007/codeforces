//Coded by Kamiyama_Shiki on 2021.11.10 {{{
//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=300005;vector<int>E[N];
struct edge{int to,nxt;}e[N<<1];int et,head[N];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
int n,m,dt,dfn[N],low[N],st[N],tp,cl[N],clt;
inline void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++dt,st[++tp]=x;
	for(int i=head[x];i;i=e[i].nxt)
		if(!dfn[e[i].to]) tarjan(e[i].to,x),low[x]=min(low[x],low[e[i].to]);
		else if(e[i].to!=fa) low[x]=min(low[x],dfn[e[i].to]);
	if(dfn[x]==low[x]) {int y;++clt;do y=st[tp--],cl[y]=clt;while(y^x);}
}
int pos,mxd;char vis[N];
inline void dfs(int x,int fa,int dep)
{
	vis[x]=1;if(dep>mxd) pos=x,mxd=dep;
	for(int y:E[x]) if(y^fa) dfs(y,x,dep+1);
}
int main()
{
	read(n,m);for(int i=1,x,y;i<=m;i++) read(x,y),adde(x,y),adde(y,x);
	int ans=0;for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,0);
	for(int x=1;x<=n;x++) for(int i=head[x];i;i=e[i].nxt)
		if(cl[e[i].to]^cl[x]) E[cl[x]].push_back(cl[e[i].to]);
	for(int i=1;i<=n;i++) if(!vis[i]) mxd=-1,dfs(i,0,0),mxd=-1,dfs(pos,0,0),ans=max(ans,mxd);
	return printf("%d\n",ans),0;
}