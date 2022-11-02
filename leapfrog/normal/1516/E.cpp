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
const int P=1e9+7;int n,K,fc[405],fi[405],iv[405],dp[405][405];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline int C(int n,int m)
{
	if(n<0||m<0||n<m) return 0;else if(n<=400) return 1ll*fc[n]*fi[m]%P*fi[n-m]%P;
	int r=1;for(int i=1;i<=m;i++) r=1ll*r*iv[i]%P*(n-i+1)%P;return r;
}
inline void pinit(int n)
{
	fc[0]=1;for(int i=1;i<=n;i++) fc[i]=1ll*fc[i-1]*i%P;
	iv[1]=1;for(int i=2;i<=n;i++) iv[i]=1ll*iv[P%i]*(P-P/i)%P;
	fi[0]=1;for(int i=1;i<=n;i++) fi[i]=1ll*fi[i-1]*iv[i]%P;
}
int main()
{
	read(n),read(K),pinit(400);for(int i=1;i<=400;i++) dp[i][0]=1;
	for(int i=1;i<=400;i++) for(int j=1;j<=400;j++) dp[i][j]=(dp[i-1][j]+1ll*(i-1)*dp[i-1][j-1])%P;
	int rs[2]={1,0};for(int j=1;j<=K;printf("%d%c",rs[j&1],j==K?'\n':' '),j++)
	{
		for(int i=1,e=min(j<<1,n),g=0;i<=e;i++,g=0)
		{
			for(int l=0;l<=i;l++) g=(g+1ll*((l&1)?P-1:1)*C(i,l)%P*dp[i-l][j])%P;
			rs[j&1]+=1ll*C(n,i)*g%P,rs[j&1]>=P?rs[j&1]-=P:0;
		}
	}
	return 0;
}