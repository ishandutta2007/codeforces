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
struct edge{int to,w,c,nxt;}e[5000005];int et=1,head[5055],a[5055],b[5055];
int n,m,l,C,D,s,t,ls[5055],fl[5055],q[50005],hd,tl,mf,mc,d[5055];char v[5055];
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
#define p(x,i) ((x)+(i)*n)
int main()
{
	read(n),read(m),read(l),read(C),read(D),t=p(1,100),s=p(0,101);
	for(int i=1,x;i<=l;i++) read(x),ls[x]++;
	for(int i=1;i<=n;i++) if(ls[i]) adde(s,p(i,0),ls[i],0);
	for(int i=1;i<=m;i++) read(ls[i]),read(fl[i]);
	for(int stp=0;stp<100;stp++)
	{
		adde(p(1,stp),p(1,stp+1),1e9,0);
		for(int i=2;i<=n;i++) adde(p(i,stp),p(i,stp+1),1e9,C);
		for(int i=1;i<=m;i++) for(int j=1;j<=l;j++)
		{
			int cost=D*j*j-D*(j-1)*(j-1)+C;
			adde(p(ls[i],stp),p(fl[i],stp+1),1,cost);
			adde(p(fl[i],stp),p(ls[i],stp+1),1,cost);
		}
	}
	return mcmf(s,t),printf("%d\n",mc),0;
}