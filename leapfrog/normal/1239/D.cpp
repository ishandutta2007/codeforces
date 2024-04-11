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
struct edge{int to,nxt;}e[1000005];char vis[1000005];int num[1000005],ct;
int T,n,m,et,head[1000005],dfn[1000005],low[1000005],dt,tp,st[1000005],col[1000005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs(int x)
{
	dfn[x]=low[x]=++dt,st[++tp]=x,vis[x]=1;
	for(int i=head[x];i;i=e[i].nxt)
		if(!dfn[e[i].to]) dfs(e[i].to),low[x]=min(low[x],low[e[i].to]);
		else if(vis[e[i].to]) low[x]=min(low[x],dfn[e[i].to]);
	if(low[x]==dfn[x]) {int y;++ct;do y=st[tp--],vis[y]=0,num[ct]++,col[y]=ct;while(y!=x);}
}
inline void solve()
{
	read(n),read(m),memset(head+1,0,n<<2),dt=0,memset(dfn+1,0,n<<2),et=0;
	ct=0,memset(num+1,0,n<<2);for(int i=1,x,y;i<=m;i++) read(x),read(y),adde(x,y);
	tp=0;for(int i=1;i<=n;i++) if(!dfn[i]) dfs(i);
	if(ct==1) return puts("No"),void();else printf("Yes\n%d %d\n",num[1],n-num[1]);
	for(int i=1;i<=n;i++) if(col[i]==1) printf("%d ",i);
	putchar('\n');for(int i=1;i<=n;i++) if(col[i]^1) printf("%d ",i);
	putchar('\n');
}
int main() {for(read(T);T--;) solve();return 0;}