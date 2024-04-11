#include <bits/stdc++.h>
using namespace std;
#define N 85
#define N1 7006
const int lim=80,lim1=7000;
int n,m,MOD,ans,pw[N1],C[N][N],w1[N][N],w2[N][N],dp[N][N];
int add(int x,int y) {x+=y;return x<MOD?x:x-MOD;}
void W(int &x,int y) {x+=y;if(x>=MOD) x-=MOD;}
int main()
{
	scanf("%d %d %d",&n,&m,&MOD);pw[0]=1;
	for(int i=1;i<=lim1;++i) pw[i]=add(pw[i-1],pw[i-1]);
	for(int i=0;i<=lim;++i) for(int j=0;j<=i;++j)
		C[i][j]=j?add(C[i-1][j],C[i-1][j-1]):1;
	for(int i=0,up,t;i<=n;++i) for(int j=0;j<=m;++j)
	{
		w1[i][j]=w2[i][j]=1;
		for(int k=1;k<=i;++k)
		{
			w1[i][j]=1ll*w1[i][j]*pw[j]%MOD;
			w2[i][j]=1ll*w2[i][j]*add(pw[j],MOD-k)%MOD;
		}
		for(int k=0;k<j;++k)
		{
			W(w1[i][j],MOD-1ll*w1[i][k]*C[j][k]%MOD);
			W(w2[i][j],MOD-1ll*w2[i][k]*C[j][k]%MOD);
		}dp[i][j]=w1[i][j];up=i-(i==n && n&1);
		for(int k=0;k<up;++k) for(int l=0;l<=j;++l)
		{
			t=1ll*dp[k][l]*w2[i-k][j-l]%MOD;
			t=1ll*t*C[i][k]%MOD*C[j][l]%MOD;
			W(dp[i][j],MOD-1ll*t*pw[(i-k)*l]%MOD);
		}
	}for(int i=0;i<=m;++i) W(ans,1ll*dp[n][i]*C[m][i]%MOD);
	printf("%d\n",ans);return 0;
}