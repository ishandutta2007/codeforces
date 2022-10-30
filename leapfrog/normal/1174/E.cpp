//Coded by leapfrog on 2021.10.29 {{{
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
const int N=1000005,P=1e9+7;
int fc[N],fi[N],iv[N];//dbinit{{{
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void dbinit(int n=N-1)
{
	fc[0]=1;for(int i=1;i<=n;i++) fc[i]=1ll*fc[i-1]*i%P;
	iv[1]=1;for(int i=2;i<=n;i++) iv[i]=1ll*iv[P%i]*(P-P/i)%P;
	fi[0]=1;for(int i=1;i<=n;i++) fi[i]=1ll*fi[i-1]*iv[i]%P;
}
inline int C(int n,int m) {return n<0||m<0||n<m?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}//}}}
const int V=N;int pr[V],pc,ls[V],ph[V],mu[V];char pv[V];//prinit{{{
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
int n,dp[N][2][21];
inline int calc(int x,int w) {return (1<<w)*(x?3:1);}
inline void pls(int &x,int y) {(x+=y)>=P?x-=P:x;}
int main()
{
	//read(n),prinit(),dbinit();int mx=0;
	//for(int i=2;i<=n;i++) if(ls[i]) vl[i]=vl[i/ls[i]]+1;else vl[i]=1;
	//for(int i=1;i<=n;i++) {mx=max(mx,vl[i]);if(vl[i]==mx) printf("%d\n",i);}
	read(n),dbinit();int K=0,W=0;while((1<<(K+1))<=n) K++;
	dp[1][0][K]=1;if((1<<(K-1))*3<=n) dp[1][1][K-1]++,W=1;
	for(int i=1;i<n;i++) for(int j=0;j<=W;j++) for(int w=0;w<=K;w++)
	{
		//printf("%d %d : %d\n",i,calc(j,w),dp[i][j][w]);
		if(i<=n/calc(j,w)) pls(dp[i+1][j][w],1ll*dp[i][j][w]*(n/calc(j,w)-i)%P);
		if(j) pls(dp[i+1][0][w],1ll*dp[i][j][w]*(n/calc(0,w)-n/calc(j,w))%P);
		if(w) pls(dp[i+1][j][w-1],1ll*dp[i][j][w]*(n/calc(j,w-1)-n/calc(j,w))%P);
	}
	return printf("%d\n",dp[n][0][0]),0;
}
//2^k  2^{k-1}*3
// dp dp[k][0/1][w]  2^k*3^{0/1}
// k  {0/1} 