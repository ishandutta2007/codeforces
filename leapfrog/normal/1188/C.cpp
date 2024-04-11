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
// 100000/k 
// x  >=x 
// dp  i  j 
//dp[i][j]=dp[k][j-1] +
// a[i]-a[k]>=lim
// 100000/k*k*n=100000*n = O(100000000) 
const int P=998244353;
int n,K,a[1005],mx=0,rs[100005],dp[1005][1005],sm[1005][1005];
inline void solve(int lim)
{
	dp[0][0]=1;for(int i=0;i<=n;i++) sm[0][i]=1;
	for(int j=1;j<=K;j++)
	{
		int it=0;for(int i=1;i<=n;i++)
		{
			while(a[i]-a[it+1]>=lim) it++;
			dp[j][i]=sm[j-1][it];
		}
		//for(int i=1;i<=n;i++) printf("%d%c",dp[j][i],i==n?'\n':' ');
		for(int i=1;i<=n;i++) sm[j][i]=(sm[j][i-1]+dp[j][i])%P;
	}
	for(int i=1;i<=n;i++) rs[lim]=(rs[lim]+dp[K][i])%P;
	//printf("%d : %d\n",lim,rs[lim]);
}
int main()
{
	read(n),read(K);for(int i=1;i<=n;i++) read(a[i]),mx=max(mx,a[i]);
	int L=mx/(K-1);sort(a+1,a+n+1),a[n+1]=1e9;for(int i=1;i<=L;i++) solve(i);
	for(int i=1;i<=L;i++) rs[i]=(rs[i]-rs[i+1]+P)%P;
	int ans=0;for(int i=1;i<=mx/(K-1);i++) ans=(ans+1ll*i*rs[i])%P;
	return printf("%d\n",ans),0;
}