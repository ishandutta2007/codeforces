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
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
const int N=10000005,P=998244353;
/*
int fc[N],fi[N],iv[N];//dbinit{{{
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void dbinit(int n)
{
	fc[0]=1;for(int i=1;i<=n;i++) fc[i]=1ll*fc[i-1]*i%P;
	iv[1]=1;for(int i=2;i<=n;i++) iv[i]=1ll*iv[P%i]*(P-P/i)%P;
	fi[0]=1;for(int i=1;i<=n;i++) fi[i]=1ll*fi[i-1]*iv[i]%P;
}
inline int C(int n,int m) {return n<0||m<0||n<m?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}//}}}
*/
int pr[N],pc,ls[N],ph[N],mu[N];char pv[N];//prinit{{{
inline void prinit(int n)
{
	pv[1]=mu[1]=ph[1]=1,ls[1]=0;for(int i=1;i<=n;i++)
	{
		if(!pv[i]) pr[++pc]=i,mu[i]=-1,ph[i]=i-1;
		for(int j=1;j<=pc&&i*pr[j]<=n;j++)
		{
			ls[i*pr[j]]=pr[j],mu[i*pr[j]]=i%pr[j]?-mu[i]:0;
			ph[i*pr[j]]=ph[i]*(pr[j]-!!(i%pr[j]));
			pv[i*pr[j]]=1;if(i%pr[j]==0) break;
		}
	}
}//}}}
int n,a[500005],ra[500005],rb[500005];
int main()
{
	prinit(N-5),read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++)
	{
		int x=ls[a[i]];if(x==0) {ra[i]=rb[i]=-1;continue;}
		while(a[i]%x==0) a[i]/=x;
		if(a[i]==1) ra[i]=rb[i]=-1;else ra[i]=x,rb[i]=a[i];
	}
	for(int i=1;i<=n;i++) printf("%d%c",ra[i],i==n?'\n':' ');
	for(int i=1;i<=n;i++) printf("%d%c",rb[i],i==n?'\n':' ');
	return 0;
}