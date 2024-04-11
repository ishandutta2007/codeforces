#include<bits/stdc++.h>
using namespace std;
struct edge{int to,nxt;}e[1000005<<1];
int n,k,tot,cnt,now,head[1000005],sz[1000005],df[1000005],ck[1000005],f[1000005],t[1000005],d[1000005];
inline void adde(int x,int y) {e[++tot]=(edge){y,head[x]},head[x]=tot;}
inline int que(int x) {int r=0;for(;x;x-=(x&(-x))) r+=t[x];return r;}
inline void ins(int x,int y) {for(;x<=n;x+=(x&(-x))) t[x]+=y;}
inline void dfs(int x,int fa=0)
{
	f[x]=fa,df[x]=++cnt,d[x]=d[fa]+1,sz[x]=1;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs(e[i].to,x),sz[x]+=sz[e[i].to];
}
inline void wrk(int x)
{
	if(d[x]-que(df[x])+now>k) return;
	for(;x!=n;x=f[x]) if(ck[x]) break;else ck[x]=1,ins(df[x],1),ins(df[x]+sz[x],-1),now++;
}
int main()
{
	scanf("%d%d",&n,&k),tot=0,memset(head,0,sizeof(head)),k=n-k,memset(ck,0,sizeof(ck));
	for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),adde(x,y),adde(y,x);
	ck[n]=1,cnt=0,d[0]=0,dfs(n);
	for(int i=n-1;i>=1;i--) if(!ck[i]) wrk(i);
	for(int i=1;i<=n;i++) if(!ck[i]) printf("%d ",i);
	return puts(""),0;
}