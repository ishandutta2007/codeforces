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
const int P=998244353;int n,m,tota,totb,tot;
int w[200005],f[3005][3005],g[3005][3005];char a[200005];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
int main()
{
	read(n),read(m);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1,x;i<=n;i++) read(x),w[i]=x,(a[i]?tota:totb)+=x,tot+=x;
	for(int i=m;~i;i--)
	{
		f[i][m-i]=g[i][m-i]=1;
		for(int j=min(m-i-1,totb);j>=0;j--)
			f[i][j]=(1ll*(tota+i+1)*f[i+1][j]+1ll*(totb-j)*f[i][j+1])%P*ksm(i-j+tot)%P,
			g[i][j]=(1ll*(tota+i)*g[i+1][j]+1ll*(totb-j-1)*g[i][j+1])%P*ksm(i-j+tot)%P;
	}
	for(int i=1;i<=n;i++) printf("%lld\n",1ll*w[i]*(a[i]?f[0][0]:g[0][0])%P);
	return 0;
}