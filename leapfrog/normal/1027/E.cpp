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
const int P=998244353;int n,K,dp[505][505],rs,r[505];
int main()
{
	read(n),read(K);for(int i=1;i<=n;i++)
	{
		dp[i][0]=1;for(int j=1;j<=n;j++)
			for(int k=1;k<=i&&k<=j;k++) dp[i][j]=(dp[i][j]+dp[i][j-k])%P;
	}//dp[i][j] :  j  i 
	for(int i=1;i<=n;i++) r[i]=(dp[i][n]-dp[i-1][n]+P)%P;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i*j<K) rs=(rs+1ll*r[i]*r[j])%P;
	return printf("%d\n",(rs<<1)%P),0;
}