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
int n,K,et,head[500005],T[505],sz[500005],f[500005],st[500005],tp;
struct edge{int to,nxt;}e[1000005];char v[500005];long long ans=0;
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void init(int x,int fa=0)
{
	sz[x]=1,f[x]=0;for(int i=head[x];i;i=e[i].nxt) if(!v[e[i].to]&&e[i].to!=fa)
		init(e[i].to,x),sz[x]+=sz[e[i].to],f[x]=max(f[x],sz[e[i].to]);
}
inline void findrt(int x,int fa,int &rt,int tot)
{
	if(max(f[x],tot-sz[x])<max(f[rt],tot-sz[rt])) rt=x;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa&&!v[e[i].to]) findrt(e[i].to,x,rt,tot);
}
inline int qry(int x) {if(x<=K) return T[K-x];else return 0;}
inline void dfs(int x,int fa,int len,int &mxl)
{
	if(len>K) return;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa&&!v[e[i].to]) dfs(e[i].to,x,len+1,mxl);
	st[++tp]=len,ans+=qry(len),mxl=max(mxl,len);
}
inline void ins() {for(;tp;tp--) T[st[tp]]++;}
inline void solve(int x)
{
	init(x);int rt,mxl=0;if(v[x]) return;else v[x]=1,T[0]=1;
	for(int i=head[x];i;i=e[i].nxt) if(!v[e[i].to]) dfs(e[i].to,x,1,mxl),ins();
	for(int i=0;i<=mxl;i++) T[i]=0;
	for(int i=head[x];i;i=e[i].nxt) if(!v[e[i].to]) rt=e[i].to,findrt(e[i].to,x,rt,sz[e[i].to]),solve(rt);
}
int main()
{
	read(n),read(K);for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	int rt=1;return init(1,0),findrt(1,0,rt,n),solve(rt),printf("%lld\n",ans),0;
}