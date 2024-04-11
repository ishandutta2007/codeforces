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
const int N=100005,V=10000005,P=1e9+7;
struct edge{int to,nxt;}e[N<<1];int n,Q,et,head[N];
struct node{int vl,nm;};vector<node>vc,qr[N],tmp;
int rs[N<<2],a[N],f[N][20],dep[N],qz[664585][25],hz[664585][25];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
int pr[V],pc,ls[V],pid[V];char pv[V];//prinit{{{
inline void prinit(int n=V-1)
{
	pv[1]=1,ls[1]=0;for(int i=1;i<=n;i++)
	{
		if(!pv[i]) pr[++pc]=i,pid[i]=pc,ls[i]=i;
		for(int j=1;j<=pc&&i*pr[j]<=n;j++)
		{
			ls[i*pr[j]]=pr[j];
			pv[i*pr[j]]=1;if(i%pr[j]==0) break;
		}
	}
}//}}}
inline void dfs0(int x,int fa)//LCA{{{
{
	dep[x]=dep[fa]+1,f[x][0]=fa;
	for(int i=1;i<20;i++) f[x][i]=f[f[x][i-1]][i-1];
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs0(e[i].to,x);
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;~i;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	for(int i=19;~i;i--) if(f[x][i]^f[y][i]) x=f[x][i],y=f[y][i];
	return x^y?f[x][0]:x;
}//}}}
inline void clear(vector<node>&v) {vector<node>qwq;swap(qwq,v);}
inline void fac(vector<node>&v,int val)
{
	clear(v);while(val^1)
	{
		int f=ls[val],c=0;
		while(val%f==0) val/=f,c++;
		v.push_back((node){f,c});
	}
}
inline void add(vector<node>&vc,int w)
{
	for(auto it:vc)
	{
		int wh=it.nm;int *q=qz[pid[it.vl]],*h=hz[pid[it.vl]];
		for(int i=0;i<=wh;i++) q[i]+=w;
		for(int i=wh+1;i<=24;i++) h[i]+=wh*w;
	}
}
inline void solve(int x,int fa)
{
	fac(vc,a[x]),add(vc,1);
	for(auto it:qr[x])
	{
		int id=it.nm,vl=it.vl,r=1;fac(tmp,vl);
		for(auto jt:tmp)
		{
			int wh=jt.nm;int *q=qz[pid[jt.vl]],*h=hz[pid[jt.vl]];
			r=1ll*r*ksm(jt.vl,q[wh]*jt.nm+h[wh])%P;
		}rs[id]=r;
	}
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) solve(e[i].to,x);
	fac(vc,a[x]),add(vc,-1);
}
int main()
{
	prinit(),read(n);for(int i=1,x,y;i<n;i++) read(x,y),adde(x,y),adde(y,x);
	dfs0(1,0);for(int i=1;i<=n;i++) read(a[i]);
	read(Q);for(int i=1,u,v,x,lc,g=4;i<=Q;i++,g+=4)
	{
		read(u,v,x),qr[u].push_back((node){x,g-1}),qr[v].push_back((node){x,g});
		lc=LCA(u,v),qr[lc].push_back((node){x,g-2}),rs[g-3]=__gcd(x,a[lc]);
	}
	solve(1,0);
	//for(int i=1;i<=Q*4;i++) printf("%d%c",rs[i],i%4?' ':'\n');
	for(int g=4;g<=Q*4;g+=4) printf("%lld\n",1ll*rs[g-1]*rs[g]%P*ksm(rs[g-2],P-3)%P*rs[g-3]%P);
	return 0;
}