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
const int N=305,P=1e9+7;int n,a[N],cn[N],bs[N],dp[N],ut,ct[N],tn[N],tp[N];
int fc[N],fi[N],iv[N];//dbinit{{{
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void dbinit(int n=N-1)
{
	fc[0]=1;for(int i=1;i<=n;i++) fc[i]=1ll*fc[i-1]*i%P;
	iv[1]=1;for(int i=2;i<=n;i++) iv[i]=1ll*iv[P%i]*(P-P/i)%P;
	fi[0]=1;for(int i=1;i<=n;i++) fi[i]=1ll*fi[i-1]*iv[i]%P;
}
inline int C(int n,int m) {return n<0||m<0||n<m?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}//}}}
const int V=31625;int pr[V],pc,ls[V],ph[V],mu[V];char pv[V];//prinit{{{
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
int main()
{
	prinit(),dbinit(),read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++)
	{
		int x=a[i];a[i]=1;for(int j=1;j<=pc&&pr[j]*pr[j]<=x;j++)
			{int c=1;while(x%pr[j]==0) c=pr[j]^1^c,x/=pr[j];a[i]*=c;}
		if(x^1) a[i]*=x;
	}// k 
	for(int i=1;i<=n;i++) tn[++ut]=a[i];
	sort(tn+1,tn+ut+1),ut=unique(tn+1,tn+ut+1)-tn-1;
	for(int i=1;i<=n;i++) cn[lower_bound(tn+1,tn+ut+1,a[i])-tn]++;
	dp[0]=1;int lim=0;
	for(int k=1;k<=ut;k++)
	{
		for(int i=0;i<cn[k];i++) bs[i]=1ll*C(cn[k]-1,i)*fc[cn[k]]%P*fi[cn[k]-i]%P;
		//printf("%d : \n",cn[k]);for(int i=0;i<cn[k];i++) printf("%d%c",bs[i],i==cn[k]-1?'\n':' ');
		for(int i=lim+cn[k]-1;i>=0;i--) tp[i]=0;
		for(int i=lim;i>=0;i--) for(int j=cn[k]-1;j>=0;j--) tp[i+j]=(tp[i+j]+1ll*dp[i]*bs[j])%P;
		lim+=cn[k]-1;for(int j=0;j<=lim;j++) dp[j]=tp[j];
	}
	for(int i=0;i<=lim;i++) dp[i]=1ll*dp[i]*fc[n-i]%P;
	//for(int i=0;i<=lim;i++) printf("%d%c",dp[i],i==lim?'\n':' ');
	int rs=0;for(int i=0;i<=lim;i++) rs=(rs+((i&1)?P-dp[i]:dp[i]))%P;
	return printf("%d\n",rs),0;
}