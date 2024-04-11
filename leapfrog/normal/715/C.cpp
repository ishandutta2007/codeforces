//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
const int N=100005;struct edge{int to,w,nxt;}e[N<<1];int et,head[N];map<int,int>m1,m2;
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline void exgcd(int a,int b,int &x,int &y) {if(b) exgcd(b,a%b,y,x),y-=a/b*x;else x=1,y=0;}
int n,P,dfn[N],nfd[N],dt,dep[N],pw[N<<1],pi[N<<1],iv,d1[N],d2[N],sz[N],sn[N];ll rs=0;
inline void dfs0(int x,int fa)
{
	dep[x]=dep[fa]+1,dfn[x]=++dt,nfd[dt]=x,sz[x]=1;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
	{
		d1[e[i].to]=(d1[x]*10ll+e[i].w)%P,d2[e[i].to]=(d2[x]+1ll*pw[dep[x]]*e[i].w)%P;
		dfs0(e[i].to,x),sz[x]+=sz[e[i].to];if(sz[sn[x]]<sz[e[i].to]) sn[x]=e[i].to;
	}
}
inline void ins(int x,int rt)
{
	rs+=m1[(d2[rt]-1ll*d1[x]*pw[dep[rt]*2]%P*pi[dep[x]]%P+1ll*d1[rt]*pw[dep[rt]]%P+P)%P];
	rs+=m2[(1ll*d1[rt]*pi[dep[rt]]%P-1ll*(d2[x]-d2[rt]+P)%P*pi[dep[rt]*2]%P+P)%P];
	//printf("%d %d : %lld %lld\n",x,rt,(d2[rt]-1ll*d1[x]*pw[dep[rt]*2]%P*pi[dep[x]]%P+1ll*d1[rt]*pw[dep[rt]]%P+P)%P,(1ll*d1[rt]*pi[dep[rt]]%P-1ll*(d2[x]-d2[rt]+P)%P*pi[dep[rt]*2]%P+P)%P);
}
inline void dfs1(int x,int fa)
{
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa&&e[i].to!=sn[x])
		dfs1(e[i].to,x),m1.clear(),m2.clear();
	if(sn[x]) dfs1(sn[x],x);
	ins(x,x),m1[d2[x]]++,m2[1ll*d1[x]*pi[dep[x]]%P]++;
	for(int i=head[x],y;i;i=e[i].nxt) if(e[i].to!=fa&&(y=e[i].to)!=sn[x])
	{
		for(int j=dfn[y];j<dfn[y]+sz[y];j++) ins(nfd[j],x);
		for(int j=dfn[y];j<dfn[y]+sz[y];j++) m1[d2[nfd[j]]]++,m2[1ll*d1[nfd[j]]*pi[dep[nfd[j]]]%P]++;
	}
}
int main()
{
	read(n),read(P);if(P==1) return printf("%lld\n",1ll*n*(n-1)),0;
	exgcd(10,P,iv,pw[0]),iv=(iv+P)%P,pw[0]=pi[0]=1;
	for(int i=1;i<=200000;i++) pw[i]=10ll*pw[i-1]%P,pi[i]=1ll*pi[i-1]*iv%P;
	for(int i=1,x,y,w;i<n;i++) read(x),read(y),read(w),adde(++x,++y,w),adde(y,x,w);
	return dfs0(1,0),dfs1(1,0),printf("%lld\n",rs),0;
}