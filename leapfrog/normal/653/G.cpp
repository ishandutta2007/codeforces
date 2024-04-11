//Coded by Kamiyama_Shiki on 2021.11.14 {{{
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
const int N=300005,P=1000000007;
namespace Binom//{{{
{
	int fc[N],fi[N],iv[N];//dbinit
	inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
	inline void dbinit(int n=N-1)
	{
		fc[0]=1;for(int i=1;i<=n;i++) fc[i]=1ll*fc[i-1]*i%P;
		iv[1]=1;for(int i=2;i<=n;i++) iv[i]=1ll*iv[P%i]*(P-P/i)%P;
		fi[0]=1;for(int i=1;i<=n;i++) fi[i]=1ll*fi[i-1]*iv[i]%P;
	}
	inline int C(int n,int m) {return n<0||m<0||n<m?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}
}using Binom::dbinit;using Binom::C;using Binom::ksm;//}}}
const int V=N;int pr[V],pc,ls[V];char pv[V];//prinit{{{
inline void prinit(int n=V-1)
{
	pv[1]=1,ls[1]=0;for(int i=1;i<=n;i++)
	{
		if(!pv[i]) pr[++pc]=i,ls[i]=i;
		for(int j=1;j<=pc&&i*pr[j]<=n;j++) {pv[i*pr[j]]=1,ls[i*pr[j]]=pr[j];if(i%pr[j]==0) break;}
	}
}//}}}
int n,a[N],c[N],qz[N],rs=0;vector<int>fc[N];
int main()
{
	read(n),prinit(),dbinit();for(int i=1;i<=n;i++) read(a[i]);
	int pw=ksm(2,n-1);for(int i=n-1;~i;i--) qz[i]=(qz[i+1]+(c[i]=C(n-1,i)))%P;
	for(int i=1,x=a[i];i<=n;x=a[++i]) while(ls[x]) {int v=ls[x],c=0;while(x%v==0) x/=v,c++;fc[v].push_back(c);}
	for(int i=1;i<N;i++) if(!fc[i].empty())
	{
		sort(fc[i].begin(),fc[i].end());int cnt=n-fc[i].size();
		for(int j=0;j<(int)fc[i].size();j++) rs=(rs+1ll*fc[i][j]*(pw-2ll*qz[cnt+j]%P+P+c[cnt+j]))%P;
	}return printf("%d\n",rs),0;
}