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
const int P=998244353;int n,fc[505],fi[505],dp[505][505],a[505];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void init()
{
	fc[0]=1;for(int i=1;i<=500;i++) fc[i]=1ll*fc[i-1]*i%P;
	fi[500]=ksm(fc[500]);for(int i=500;i;i--) fi[i-1]=1ll*fi[i]*i%P;
}
inline int C(int n,int m) {return n<0||m<0||n<m?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}
int main()
{
	char f[5];read(n);int res=0;
	for(int i=1;i<=n;i++) {scanf("%s",f);if(*f=='-') a[i]=-1;else read(a[i]);}
	for(int k=1;k<=n;k++) if(~a[k])
	{
		memset(dp,0,sizeof(dp)),dp[0][0]=1;
		for(int i=1;i<k;i++)
			if(a[i]<0)
			{
				for(int j=0;j<=i;j++) dp[i][j]=(dp[i-1][j+1]+dp[i-1][j])%P;
				dp[i][0]=(dp[i][0]+dp[i-1][0])%P;
			}
			else if(a[i]<=a[k])
			{
				dp[i][0]=dp[i-1][0];
				for(int j=1;j<=i;j++) dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%P;
			}
			else for(int j=0;j<=i;j++) dp[i][j]=dp[i-1][j]*2%P;
		for(int i=0;i<=k;i++) dp[k][i]=dp[k-1][i];
		//for(int i=0;i<=k;i++) printf("%d%c",dp[k][i],i==k?'\n':' ');
		for(int i=k+1;i<=n;i++)
			if(a[i]<0) for(int j=0;j<=i;j++) dp[i][j]=(dp[i-1][j+1]+dp[i-1][j])%P;
			else if(a[i]<a[k])
			{
				dp[i][0]=dp[i-1][0];
				for(int j=1;j<=i;j++) dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%P;
			}
			else for(int j=0;j<=i;j++) dp[i][j]=dp[i-1][j]*2%P;
		int tot=0;for(int i=0;i<=n;i++) tot=(tot+dp[n][i])%P;
		//printf("%d\n",tot);
		res=(res+1ll*tot*a[k])%P;
	}
	printf("%d\n",res);
}