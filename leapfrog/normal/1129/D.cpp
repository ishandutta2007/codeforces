//Coded by Kamiyama_Shiki on 2021.11.14 {{{
//
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=100005,B=316,P=998244353;int ls[N],tn[N];
int n,K,a[N],bl[N],L[N/B+5],R[N/B+5],blc,vv[N/B+5][N],tg[N/B+5],vl[N],dp[N],nw[N/B+5];
inline void pushdw(int id)
{
	for(int i=L[id];i<=R[id];i++) vv[id][vl[i]]=0;
	int v;if(!tg[id]) return;else v=tg[id],tg[id]=0;
	for(int i=L[id];i<=R[id];i++) vl[i]+=v;
}
inline void rebld(int id)
{
	nw[id]=0;for(int i=L[id];i<=R[id];i++) (vv[id][vl[i]]+=dp[i-1])%=P;
	for(int i=L[id];i<=R[id];i++) if(vl[i]<=K) nw[id]=(nw[id]+dp[i-1])%P;
}
inline void atag(int id,int w)
{
	if(w>0) nw[id]=(nw[id]-vv[id][K-tg[id]]+P)%P,tg[id]++;
	else if(w<0) tg[id]--,nw[id]=(nw[id]+vv[id][K-tg[id]])%P;
}
inline void modif(int l,int r,int c)
{
	//debug("modif %d %d %d\n",l,r,c);
	int dl=bl[l],dr=bl[r];pushdw(dl);if(dl^dr) pushdw(dr);
	if(dl==dr) {for(int i=l;i<=r;i++) vl[i]+=c;return rebld(dl);}
	for(int i=l;i<=R[dl];i++) vl[i]+=c;
	for(int i=L[dr];i<=r;i++) vl[i]+=c;
	for(int i=dl+1;i<dr;i++) atag(i,c);
	rebld(dl);if(dl^dr) rebld(dr);
}
inline int qrydl(int l,int r)
{
	int dl=bl[l],dr=bl[r],rs=0;pushdw(dl),rebld(dl);if(dl^dr) pushdw(dr),rebld(dr);
	if(dl==dr) {for(int i=l;i<=r;i++) if(vl[i]<=K) rs=(rs+dp[i-1])%P;return rs;}
	for(int i=l;i<=R[dl];i++) if(vl[i]<=K) rs=(rs+dp[i-1])%P;
	for(int i=L[dr];i<=r;i++) if(vl[i]<=K) rs=(rs+dp[i-1])%P;
	for(int i=dl+1;i<dr;i++) rs=(rs+nw[i])%P;
	return rs;
}
int main()
{
	read(n,K);for(int i=1;i<=n;i++) read(a[i]);
	blc=(n-1)/B+1;for(int i=1;i<=n;i++) bl[i]=(i-1)/B+1;
	for(int i=1;i<=n;i++) (L[bl[i]]?0:L[bl[i]]=i),R[bl[i]]=i;
	for(int i=1;i<=n;i++) ls[i]=tn[a[i]],tn[a[i]]=i;
	dp[0]=1,pushdw(bl[1]),rebld(bl[1]);
	for(int i=1;i<=n;i++)
	{
		modif(ls[i]+1,i,1);if(ls[i]) modif(ls[ls[i]]+1,ls[i],-1);
		dp[i]=qrydl(1,i),pushdw(bl[i]),rebld(bl[i]);
		//debug("dp[%d]=%d\n",i,dp[i]);
	}
	return printf("%d\n",dp[n]),0;
}