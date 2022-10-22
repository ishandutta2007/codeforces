#include <bits/stdc++.h>
using namespace std;
#define N 3005
#define M 1<<11
#define MOD 998244353
int n,m,a[N],pw[N],invPw[N],cnt[N],ans[N],w1[N],w[N][N],dp1[N][N],dp2[N][M];
void W(int &x,int y) {x+=y;if(x>=MOD) x-=MOD;}
int add(int x,int y) {x+=y;return x<MOD?x:x-MOD;}
int qPow(int x,int y)
{int res=1;for(;y;y/=2,x=1ll*x*x%MOD) if(y&1) res=1ll*res*x%MOD;return res;}
void slv1()
{
	for(int i=1,cnt0,t;i<=n;++i)
	{
		cnt0=m-1;t=1;w[i][i+1]=!cnt0;for(int j=1;j<=m;++j) cnt[j]=0;
		for(int j=i;j;--j)
		{
			w[i][j]=w[i][j+1];if(a[i]==a[j]) continue;
			if(cnt[a[j]]) t=1ll*t*invPw[cnt[a[j]]]%MOD;
			else --cnt0;++cnt[a[j]];t=1ll*t*pw[cnt[a[j]]]%MOD;if(!cnt0) w[i][j]=t;
		}
	}for(int i=1;i<=m;++i) cnt[i]=0;w1[n+1]=1;
	for(int i=n,cnt0=m,t=1;i;--i)
	{
		if(cnt[a[i]]) t=1ll*t*invPw[cnt[a[i]]]%MOD;
		else --cnt0;++cnt[a[i]];t=1ll*t*pw[cnt[a[i]]]%MOD;
		w1[i]=add(pw[n-i+1]+1,(cnt0?0:MOD-t));
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=i/m;++j) for(int k=0;k<i;++k)
		W(dp1[i][j],1ll*dp1[k][j-1]*w[i][k+1]%MOD);
	for(int i=0;i<=n;++i) for(int j=0;j<=i/m;++j)
		W(ans[j],1ll*dp1[i][j]*w1[i+1]%MOD);
}
void slv2()
{
	for(int i=1;i<=n;++i) for(int j=i/m;j>=0;--j) for(int k=(1<<m)-1;k>=0;--k)
		if((k|(1<<a[i]-1))==(1<<m)-1) W(dp2[j+1][0],dp2[j][k]);
		else W(dp2[j][k|(1<<a[i]-1)],dp2[j][k]);
	for(int i=0;i<=n;++i) for(int j=0;j<1<<m;++j) W(ans[i],dp2[i][j]);
}
int main()
{
	scanf("%d %d",&n,&m);dp1[0][0]=dp2[0][0]=1;
	for(int i=1;i<=n;++i) pw[i]=add(pw[i-1],pw[i-1]+1),invPw[i]=qPow(pw[i],MOD-2);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	if(m>11) slv1();else slv2();W(ans[0],MOD-1);
	for(int i=0;i<=n;++i) printf("%d ",ans[i]);return 0;
}