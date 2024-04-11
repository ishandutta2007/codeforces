//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
struct edge{int to,w,c,nxt;}e[5000005];int et=1,head[5005],a[5005],b[5005];
int n,m,s,t,ls[5005],fl[5005],q[50005],hd,tl,mf,mc,d[5005];char v[5005];
inline void ADDE(int x,int y,int w,int c) {e[++et]=(edge){y,w,c,head[x]},head[x]=et;}
inline void adde(int x,int y,int w,int c) {ADDE(x,y,w,c),ADDE(y,x,0,-c);}
inline char spfa(int s,int t)
{
	memset(d,0x3f,sizeof(d)),memset(v,0,sizeof(v)),q[hd=tl=1]=s,d[s]=0,fl[s]=1e9,ls[t]=0;
	for(int x=s;hd<=tl;v[x=q[++hd]]=0) for(int i=head[x],y=e[i].to;i;y=e[i=e[i].nxt].to)
		if(e[i].w&&d[y]>d[x]+e[i].c) {d[y]=d[x]+e[i].c,ls[y]=i,fl[y]=min(fl[x],e[i].w);if(!v[y]) v[q[++tl]=y]=1;}
	return !!ls[t];
}
inline void upd(int s,int t)
{
	mf+=fl[t],mc+=fl[t]*d[t];int x=t;
	for(;x^s;x=e[ls[x]^1].to) e[ls[x]].w-=fl[t],e[ls[x]^1].w+=fl[t];
}
inline void mcmf(int s,int t) {mf=mc=0;while(spfa(s,t)) upd(s,t);}
int main()
{
	read(n),read(m);for(int i=1;i<=n;i++) read(a[i]);
	s=n+n+1,t=s+1;for(int i=1;i<=n;i++) read(b[i]);
	for(int i=1;i<=n;i++) {adde(i,i+n,1,0),adde(i+n,t,1,0);if(i^n) adde(i,i+1,m-1,0);}
	for(int i=1;i<=n;ls[a[i]]=i,i++) {adde(s,i,1,b[a[i]]);if(ls[a[i]]) adde(i-1,ls[a[i]]+n,1,-b[a[i]]);}
	return mcmf(s,t),printf("%d\n",mc),0;
}