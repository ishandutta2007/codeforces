//{{{
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}/*}}}*/
struct edge{int to,nxt;}e[200005];char vis[200005];int we[200005],ct,vl[200005],w[200005];
int n,et,head[200005],dfn[200005],low[200005],dt,tp,st[200005],cl[200005],dg[200005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void tarjan(int x)
{
	dfn[x]=low[x]=++dt,st[++tp]=x,vis[x]=1;
	for(int i=head[x];i;i=e[i].nxt)
		if(!dfn[e[i].to]) tarjan(e[i].to),low[x]=min(low[x],low[e[i].to]);
		else low[x]=min(low[x],dfn[e[i].to]);
	if(low[x]==dfn[x]) {int y;++ct;do y=st[tp--],cl[y]=ct;while(y!=x);}
}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(w[i]);
	for(int i=1,f;i<=n;i++) read(f),adde(i,f);
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	memset(we,0x3f,sizeof(we));for(int i=1;i<=n;i++) we[cl[i]]=min(we[cl[i]],w[i]);
	for(int x=1;x<=n;x++) for(int i=head[x];i;i=e[i].nxt) if(cl[e[i].to]!=cl[x]) dg[cl[x]]=1;
	int rs=0;for(int i=1;i<=ct;i++) if(!dg[i]) rs+=we[i];
	return printf("%d\n",rs),0;
}