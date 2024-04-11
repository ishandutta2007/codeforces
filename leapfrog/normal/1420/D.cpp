//Coded by Kamiyama_Shiki on 2021.11.02 {{{
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
const int N=300005,P=998244353;int n,K,tn[N<<1],ut,cf[N<<1],l[N],r[N],qwq[N<<1];
int fc[N],fi[N],iv[N];//dbinit{{{
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void dbinit(int n=N-1)
{
	fc[0]=1;for(int i=1;i<=n;i++) fc[i]=1ll*fc[i-1]*i%P;
	iv[1]=1;for(int i=2;i<=n;i++) iv[i]=1ll*iv[P%i]*(P-P/i)%P;
	fi[0]=1;for(int i=1;i<=n;i++) fi[i]=1ll*fi[i-1]*iv[i]%P;
}
inline int C(int n,int m) {return n<0||m<0||n<m?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}//}}}
int main()
{
	read(n,K),dbinit();for(int i=1;i<=n;i++) read(l[i],r[i]),tn[++ut]=l[i],tn[++ut]=r[i];
	sort(tn+1,tn+ut+1),ut=unique(tn+1,tn+ut+1)-tn-1;
	for(int i=1;i<=n;i++) cf[l[i]=lower_bound(tn+1,tn+ut+1,l[i])-tn]++,cf[r[i]=lower_bound(tn+1,tn+ut+1,r[i])-tn+1]--,qwq[l[i]]++;
	for(int i=1;i<=ut;i++) cf[i]+=cf[i-1];
	int rs=0;for(int i=1;i<=ut;i++) rs=(1ll*rs+C(cf[i],K)-C(cf[i]-qwq[i],K)+P)%P;
	return printf("%d\n",rs),0;
}