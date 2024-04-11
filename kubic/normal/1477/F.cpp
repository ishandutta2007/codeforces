#include <bits/stdc++.h>
using namespace std;
#define N 55
#define M 2005
#define MOD 998244353
int n,m,up,s,invS,ans,a[N],fc[M],invFc[M],pw[M][M],dp[N][N][M];
void W(int &x,int y) {x+=y;if(x>=MOD) x-=MOD;}
int qPow(int x,int y)
{int res=1;for(;y;y/=2,x=1ll*x*x%MOD) if(y&1) res=1ll*res*x%MOD;return res;}
void init(int n)
{
	fc[0]=invFc[0]=1;
	for(int i=1;i<=n;++i) fc[i]=1ll*fc[i-1]*i%MOD;invFc[n]=qPow(fc[n],MOD-2);
	for(int i=n-1;i;--i) invFc[i]=1ll*invFc[i+1]*(i+1)%MOD;
	for(int i=1;i<=n;++i)
	{pw[i][0]=1;for(int j=1;j<=n;++j) pw[i][j]=1ll*pw[i][j-1]*i%MOD*invS%MOD;}
}
int main()
{
	scanf("%d %d",&n,&m);dp[0][0][0]=1;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),s+=a[i];invS=qPow(s,MOD-2);init(2e3+1);	
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<i;++j) for(int k=0;k<=up;++k) for(int l=0;m*l<=a[i];++l)
		{
			W(dp[i][j][k+l],1ll*dp[i-1][j][k]*pw[a[i]-m*l][l]%MOD*invFc[l]%MOD);
			if(l) W(dp[i][j+1][k+l],1ll*dp[i-1][j][k]*pw[a[i]-m*l][l-1]%MOD*invFc[l-1]%MOD);
		}up+=a[i]/m;
	}
	for(int i=0,t;i<=n;++i) for(int j=i;j<=up;++j) if(i || j)
		t=1ll*qPow(pw[m*j][j-i+1],MOD-2)*fc[j-i]%MOD*dp[n][i][j]%MOD,W(ans,j&1?t:MOD-t);
	printf("%d\n",ans);return 0;
}