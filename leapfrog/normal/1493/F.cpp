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
const int N=1005;int n,m,tx[105],xt,ty[105],yt,rn,rm;
const int V=1005;int pr[V],pc,ls[V],ph[V],mu[V];char pv[V];//prinit{{{
inline void prinit(int n=V-1)
{
	pv[1]=mu[1]=ph[1]=1,ls[1]=0;for(int i=1;i<=n;i++)
	{
		if(!pv[i]) pr[++pc]=i,mu[i]=-1,ph[i]=i-1,ls[i]=i;
		for(int j=1;j<=pc&&i*pr[j]<=n;j++)
		{
			ls[i*pr[j]]=pr[j],mu[i*pr[j]]=i%pr[j]?-mu[i]:0;
			ph[i*pr[j]]=ph[i]*(pr[j]-!!(i%pr[j]));
			pv[i*pr[j]]=1;if(i%pr[j]==0) break;
		}
	}
}//}}}
inline int qryn(int len,int l,int r)
{
	printf("? %d %d %d %d %d %d\n",len,m,l,1,r,1);
	int vl;fflush(stdout),read(vl);return vl;
}
inline int qrym(int len,int l,int r)
{
	printf("? %d %d %d %d %d %d\n",n,len,1,l,1,r);
	int vl;fflush(stdout),read(vl);return vl;
}
inline char chkn(int cnt)
{
	if(cnt==2) return qryn(rn/2,1,rn/2+1);
	int ln=rn/cnt,md=cnt/2;
	return qryn(md*ln,1,md*ln+1)&&qryn(md*ln,1,(md+1)*ln+1);
}
inline char chkm(int cnt)
{
	if(cnt==2) return qrym(rm/2,1,rm/2+1);
	int ln=rm/cnt,md=cnt/2;
	return qrym(md*ln,1,md*ln+1)&&qrym(md*ln,1,(md+1)*ln+1);
}
int main()
{
	read(n,m),prinit();int xx=0,yy=0,rs=1,c1=1,c2=1;
	int x=n;rn=n;while(x!=1) tx[++xt]=ls[x],x/=ls[x];
	int y=m;rm=m;while(y!=1) ty[++yt]=ls[y],y/=ls[y];
	for(int i=1;i<=xt;i++) if(chkn(tx[i])) rn/=tx[i],tx[++xx]=tx[i];
	for(int i=1;i<=yt;i++) if(chkm(ty[i])) rm/=ty[i],ty[++yy]=ty[i];
	for(int i=1;i<=xx;i++) if(tx[i]==tx[i-1]) c1++;else rs*=c1,c1=2;
	for(int i=1;i<=yy;i++) if(ty[i]==ty[i-1]) c2++;else rs*=c2,c2=2;
	return printf("! %d\n",rs*c1*c2),fflush(stdout),0;
}