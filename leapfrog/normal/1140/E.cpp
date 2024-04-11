#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,P=998244353,ans,beg,dp[200005][2],a[200005],m=0,b[200005];
inline int ksm(int a,int q) {int r=1;for(;q;q>>=1,a=1ll*a*a%P) if(q&1) r=1ll*r*a%P;return r%P;}
inline int wrk(int n,int a[])
{
	int ret=1;
	for(int i=1;i<n;i++) if(a[i]!=-1&&a[i]==a[i+1]) return 0;
	for(int i=1,j;i<=n;i=j+1)
	{
		while(i<=n&&a[i]!=-1) i++;j=i;
		while(j<=n&&a[j]==-1) j++;j--;
		if(i>j||i<1||j>n) continue;
		else if(i==1&&j==n) ret=1ll*ret*ksm(k-1,n-1)%P*k%P;
		else if(i==1||j==n) ret=1ll*(dp[j-i][0]+1ll*(k-1)*dp[j-i][1]%P)%P*ret%P;
		else ret=1ll*ret*dp[j-i+1][a[i-1]!=a[j+1]]%P;
	}
	return ret;
}
signed main()
{
	scanf("%lld%lld",&n,&k),dp[0][0]=0,dp[0][1]=1,ans=1;
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	for(int i=1;i<=n;i++) dp[i][0]=1ll*dp[i-1][1]*(k-1)%P,dp[i][1]=(1ll*dp[i-1][1]*(k-2)%P+dp[i-1][0])%P;
	for(int i=1;i<=n;i+=2) b[++m]=a[i];
	ans=1ll*ans*wrk(m,b)%P,m=0;
	for(int i=2;i<=n;i+=2) b[++m]=a[i];
	return ans=1ll*ans*wrk(m,b)%P,printf("%lld\n",ans),0;
}