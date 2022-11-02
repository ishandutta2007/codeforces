//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;int c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
const int P=998244353;int n,p,pw1[4000005],pw2[4000005],dp[2005][2005],f[2005],g[2005],h[2005];
inline int ksm(int x,int q=P-2) {x%=P;int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
int main()
{
	read(n);int a,b;read(a),read(b),p=1ll*a*ksm(b)%P,pw1[0]=pw2[0]=1;
	if(n==1) return puts("0"),0;else if(n==2) return puts("1"),0;
	for(int i=1;i<=n*n;i++) pw1[i]=1ll*pw1[i-1]*p%P,pw2[i]=1ll*pw2[i-1]*(P-p+1)%P;
	for(int i=0;i<=n;i++) {dp[i][0]=1;for(int j=1;j<=i;j++) dp[i][j]=(1ll*dp[i-1][j]*pw1[j]%P+1ll*dp[i-1][j-1]*pw2[i-j]%P)%P;}
	for(int i=1;i<=n;i++) {f[i]=1;for(int j=1;j<i;j++) f[i]=(f[i]-1ll*f[j]*dp[i][j]%P+P)%P;}
	for(int i=3;i<=n;i++)
	{
		int res=1ll*i*(i-1)%P*ksm(2)%P;for(int j=1;j<i;j++) res=(res+1ll*(g[j]+h[i-j])*f[j]%P*dp[i][j]%P)%P;
		g[i]=1ll*res*ksm(1+P-f[i])%P,res=1ll*f[i]*g[i]%P;
		for(int j=1;j<i;j++) res=(res+1ll*(g[j]+h[i-j])*f[j]%P*dp[i][j]%P)%P;
		h[i]=res;
	}
	return printf("%d\n",g[n]),0;
}