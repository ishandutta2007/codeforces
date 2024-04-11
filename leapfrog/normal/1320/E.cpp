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
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=200005;int n,Q,K,m,F[N],cl[N],idt,id[N<<2],sp[N],qr[N],fa[N],st[N],tp;
struct edge{int to,nxt;}e[N<<1];int et,head[N],f[N][20],dep[N],dt,dfn[N],sz[N];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs0(int x,int fa)
{
	dep[x]=dep[fa]+1,f[x][0]=fa,sz[x]=1,dfn[x]=++dt;
	for(int i=1;i<20;i++) f[x][i]=f[f[x][i-1]][i-1];
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
		dfs0(e[i].to,x),sz[x]+=sz[e[i].to];
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;~i;i--) if(dep[y]<=dep[f[x][i]]) x=f[x][i];
	for(int i=19;~i;i--) if(f[x][i]^f[y][i]) x=f[x][i],y=f[y][i];
	return x^y?f[x][0]:x;
}
inline int dis(int x,int y) {return dep[x]+dep[y]-(dep[LCA(x,y)]<<1);}
inline int tim(int x,int y) {return (dis(x,y)+sp[cl[x]]-1)/sp[cl[x]];}
inline void upd(int x,int &a,int b)
{
	if(!x) return;else if(!a||!b) return a=a|b,void();
	int d1=tim(a,x),d2=tim(b,x);if(d2<d1||(d1==d2&&cl[a]>cl[b])) a=b;
}
int main()
{
	read(n);for(int i=1,x,y;i<n;i++) read(x,y),adde(x,y),adde(y,x);
	for(dfs0(1,0),read(Q);Q--;)
	{
		read(K,m),idt=0;
		for(int i=1,x,w;i<=K;i++) read(x,w),cl[x]=i,sp[i]=w,F[x]=x,id[++idt]=x;
		for(int i=1,x;i<=m;i++) read(x),id[++idt]=x,qr[i]=x;
		sort(id+1,id+idt+1,[](int a,int b){return dfn[a]<dfn[b];});
		for(int i=idt;i>1;i--) id[++idt]=LCA(id[i],id[i-1]);
		sort(id+1,id+idt+1,[](int a,int b){return dfn[a]<dfn[b];});
		idt=unique(id+1,id+idt+1)-id-1,tp=0;
		for(int i=1;i<=idt;st[++tp]=id[i],i++)
		{
			while(tp&&dfn[st[tp]]+sz[st[tp]]<=dfn[id[i]]) tp--;
			if(tp) fa[id[i]]=st[tp];
		}
		//for(int i=1;i<=idt;i++) printf("%d%c",id[i],i==idt?'\n':' ');
		for(int i=idt;i>=2;i--) upd(fa[id[i]],F[fa[id[i]]],F[id[i]]);
		//for(int i=1;i<=idt;i++) printf("%d%c",F[id[i]],i==idt?'\n':' ');
		for(int i=2;i<=idt;i++) upd(id[i],F[id[i]],F[fa[id[i]]]);
		for(int i=1;i<=m;i++) printf("%d%c",cl[F[qr[i]]],i==m?'\n':' ');
		for(int i=1;i<=idt;i++) F[id[i]]=cl[id[i]]=fa[id[i]]=0,id[i]=0;
	}return 0;
}