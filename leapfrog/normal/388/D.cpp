//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
const int P=1e9+7;int n,dp[2][35][35],C[35][35],h[35][2];
inline int ksm(int x,int q) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
int main()
{
	for(int i=0;i<=30;i++) {C[i][0]=1;for(int j=1;j<=i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;}
	for(int i=0;i<=30;i++) for(int j=0;j<=i;j++) (h[i][j&1]+=C[i][j])%=P;
	read(n),dp[1][31][0]=1;for(int i=30;~i;i--) for(int j=0;j<31;j++)
	{
		(dp[0][i][j]+=1ll*dp[0][i+1][j]*ksm(2,j)%P)%=P;
		if(j) (dp[0][i][j]+=dp[0][i+1][j-1])%=P;
		if(!((n>>i)&1)) (dp[1][i][j]+=1ll*dp[1][i+1][j]*h[j][0]%P)%=P;
		else
		{
			(dp[0][i][j]+=1ll*dp[1][i+1][j]*h[j][0]%P)%=P;
			(dp[1][i][j]+=1ll*dp[1][i+1][j]*h[j][1]%P)%=P;
			if(j) (dp[1][i][j]+=dp[1][i+1][j-1])%=P;
		}
	}
	int res=0;for(int i=0;i<31;i++) (res+=(dp[0][0][i]+dp[1][0][i])%P)%=P;
	return printf("%d\n",res),0;
}