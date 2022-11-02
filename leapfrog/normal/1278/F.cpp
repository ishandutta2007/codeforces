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
const int P=998244353;int n,m,K,dp[5005][5005];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
int main()
{
	read(n),read(m),read(K),dp[0][0]=1;int iv=ksm(m);
	for(int i=1;i<=K;i++) for(int j=1;j<=i;j++) dp[i][j]=(1ll*dp[i-1][j]*j+1ll*dp[i-1][j-1]*(n-j+1))%P;
	int rs=0;for(int i=1;i<=K;i++) rs=(rs+1ll*dp[K][i]*ksm(iv,i))%P;
	return printf("%d\n",rs),0;
}