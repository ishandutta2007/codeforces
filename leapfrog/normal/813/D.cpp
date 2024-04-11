//Coded by Kamiyama_Shiki on 2021.11.12 {{{
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
const int N=5005;
namespace Flow//{{{
{
	struct edge{int to,w,c,nxt;}e[5000005];int et=1,head[20005];
	int ls[20005],fl[20005],q[45000005],hd,tl,mf,mc,d[20005];char v[20005];
	inline void ADDE(int x,int y,int w,int c) {e[++et]=(edge){y,w,c,head[x]},head[x]=et;}
	inline void adde(int x,int y,int w,int c) {ADDE(x,y,w,c),ADDE(y,x,0,-c);}
	inline char spfa(int s,int t)
	{
		memset(d,~0x3f,sizeof(d)),memset(v,0,sizeof(v)),q[hd=tl=1]=s,d[s]=0,fl[s]=1e9,ls[t]=0;
		for(int x=s;hd<=tl;v[x=q[++hd]]=0) for(int i=head[x],y=e[i].to;i;y=e[i=e[i].nxt].to)
			if(e[i].w&&d[y]<d[x]+e[i].c) {d[y]=d[x]+e[i].c,ls[y]=i,fl[y]=min(fl[x],e[i].w);if(!v[y]) v[q[++tl]=y]=1;}
		return !!ls[t];
	}
	inline void upd(int s,int t)
	{
		mf+=fl[t],mc+=fl[t]*d[t];int x=t;
		for(;x^s;x=e[ls[x]^1].to) e[ls[x]].w-=fl[t],e[ls[x]^1].w+=fl[t];
	}
	inline int mcmf(int s,int t) {mf=mc=0;while(spfa(s,t)) upd(s,t);return mc;}
}//}}}
int n,a[N],s,t;
int main()
{
	read(n),s=n*4+1,t=s+1,Flow::adde(n*4+3,s,2,0);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++)
	{
		Flow::adde(s,i+2*n,1e9,0),Flow::adde(i,i+2*n,1e9,0);
		Flow::adde(i+n,i+2*n,1e9,0),Flow::adde(i+2*n,i+3*n,1,1),Flow::adde(i+3*n,t,1e9,0);
		for(int j=i+1;j<=n;j++) if(a[i]-a[j]==1) {Flow::adde(i+3*n,j+n,1e9,0);break;}
		for(int j=i+1;j<=n;j++) if(a[j]-a[i]==1) {Flow::adde(i+3*n,j+n,1e9,0);break;}
		for(int j=i+1;j<=n;j++) if((a[i]-a[j])%7==0) {Flow::adde(i+3*n,j,1e9,0),Flow::adde(i,j,1e9,0);break;}
		for(int j=i+1;j<=n;j++) if(a[i]==a[j]) {Flow::adde(i+n,j+n,1e9,0);break;}
	}
	fflush(stdout);
	return printf("%d\n",Flow::mcmf(n*4+3,t)),0;
}