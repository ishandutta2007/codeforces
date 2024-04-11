//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int n,m,h[2000005];const int P=998244353;
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
int main()
{
	read(n),read(m),h[1]=1;
	for(int i=2;i<=n;i++) h[i]=1ll*h[P%i]*(P-P/i)%P;
	for(int i=1;i<=n;i++) h[i]=(h[i-1]+h[i])%P;
	int rs=(n+m+1)%P;rs=1ll*rs*(1ll*m*h[n]%P+1)%P;
	return printf("%lld\n",1ll*rs*ksm(m+1)%P),0;
}