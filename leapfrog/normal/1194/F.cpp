	//{{{
#include<bits/stdc++.h>
	using namespace std;typedef long long ll;
	template<typename T>inline void read(T &x)
	{
		x=0;char c=getchar(),bz=0;
		for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
		for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
		bz?x=-x:x;
	}/*}}}*/
const int P=1e9+7;int n,a[200005],fc[200005],fi[200005],N,M,S,rs=0,pw[200005];ll T,s[200005];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline int C(int n,int m) {return n<0||m<0||n<m?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}
inline void init(int n)
{
	fc[0]=1;for(int i=1;i<=n;i++) fc[i]=1ll*fc[i-1]*i%P;
	fi[n]=ksm(fc[n]);for(int i=n;i;i--) fi[i-1]=1ll*fi[i]*i%P;
	int I=(P+1)>>1;pw[0]=1;for(int i=1;i<=n;i++) pw[i]=1ll*pw[i-1]*I%P;
}
int main()
{
	read(n),read(T),init(200002);for(int i=1;i<=n;i++) read(a[i]),s[i]=s[i-1]+a[i];
	N=1,M=max(min(T-s[1],1ll*N),-1ll);for(int i=0;i<=M;i++) S=(S+C(N,i))%P;
	for(int i=1;i<=n;i++)
	{
		for(;N<i;N++) S=(2ll*S-C(N,M)+P)%P;
		for(int end=max(min(T-s[i],1ll*N),-1ll);M>end&&M>-1;M--) S=(S-C(N,M)+P)%P;
		for(int end=max(min(T-s[i],1ll*N),-1ll);M<end;M++) S=(S+C(N,M+1))%P;
		rs=(rs+1ll*S*pw[i])%P;
	}
	return printf("%d\n",rs),0;
}