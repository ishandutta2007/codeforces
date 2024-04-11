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
const int P=1e9+7,N=1000005;int n,K,fc[N],F[N],fi[N],sm,rs;
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline int C(int n,int m) {return n<0||m<0||n<m?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}
int main()
{
	read(n),read(K),fc[0]=1;for(int i=1;i<=n;i++) fc[i]=1ll*fc[i-1]*i%P;
	sm=1,F[0]=1,fi[n]=ksm(fc[n]);for(int i=n;i>=1;i--) fi[i-1]=1ll*fi[i]*i%P;
	for(int i=1;i<=n;i++)
	{
		F[i]=1ll*sm*fc[i-1]%P;if(i>=K) sm=(sm+P-1ll*F[i-K]*fi[i-K]%P)%P;
		sm=(sm+1ll*F[i]*fi[i])%P,rs=(rs+1ll*F[i-1]*C(n-1,i-1)%P*fc[n-i])%P;
	}
	return printf("%d\n",(fc[n]-rs+P)%P),0;
}