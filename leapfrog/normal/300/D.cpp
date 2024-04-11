//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename t>inline void read(t &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
const int P=7340033;
int T,n,K,cn,f[35][1005],g[35][1005];
inline void init()
{
	for(int i=0;i<=30;i++) f[i][0]=g[i][0]=1;
	for(int i=1;i<=30;i++) for(int j=1;j<=1000;j++)
	{
		for(int k=0;k<j;k++) f[i][j]=(f[i][j]+1ll*g[i-1][k]*g[i-1][j-k-1])%P;
		for(int k=0;k<=j;k++) g[i][j]=(g[i][j]+1ll*f[i][k]*f[i][j-k])%P;
	}
}
inline void solve()
{
	read(n),read(K),cn=0;while((n&1)&&n^1) n>>=1,cn++;
	printf("%d\n",f[cn][K]);
}
int main() {for(init(),read(T);T--;) solve();return 0;}