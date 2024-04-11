#include <bits/stdc++.h>	
using namespace std;
#define N 1005
#define MOD 998244353
int n,fc,cnt1,a1[N],a2[N],ps1[N],ps2[N],dp[N],cnt[2][2];
bool vs[N],tg1[N],tg2[N];
void W(int &x,int y) {x+=y;if(x>=MOD) x-=MOD;}
int add(int x,int y) {return x<MOD?x:x-MOD;}
int main()
{
	scanf("%d",&n);fc=dp[0]=1;
	for(int i=1;i<=n;++i) scanf("%d",&a1[i]);
	for(int i=1;i<=n;++i) scanf("%d",&a2[i]);
	for(int i=1;i<=n;++i)
	{
		if(!a1[i] && !a2[i]) ++cnt[1][1];tg1[a1[i]]=tg2[a2[i]]=1;
		ps1[a1[i]]=a2[i];ps2[a2[i]]=a1[i];
	}
	for(int i=1,lst;i<=n;++i) if((tg1[i] || tg2[i]) && !ps2[i])
	{for(int j=i;j;j=ps1[j]) vs[j]=1,lst=j;++cnt[tg2[i]][tg1[lst]];}
	for(int i=1;i<=n;++i) if((tg1[i] || tg2[i]) && !vs[i])
	{vs[i]=1;for(int j=ps1[i];j!=i;j=ps1[j]) vs[j]=1;++cnt1;}
	for(int i=1;i<=cnt[1][1]+cnt[0][1];++i)
	{for(int j=n;j;--j) dp[j]=(dp[j-1]+1ll*dp[j]*(i-1))%MOD;dp[0]=0;}
	for(int i=1;i<=cnt[1][0];++i)
	{
		for(int j=n;j;--j)
			dp[j]=(dp[j-1]+1ll*dp[j]*(i+cnt[1][1]-1))%MOD;dp[0]=0;
	}
	for(int i=1;i<=cnt[0][0];++i)
	{for(int j=n;j;--j) dp[j]=1ll*dp[j]*(cnt[1][1]-i+1)%MOD;dp[0]=0;}
	for(int i=1;i<=cnt[1][1]-cnt[0][0];++i) fc=1ll*fc*i%MOD;
	for(int i=n;i>=cnt1;--i) dp[i]=1ll*dp[i-cnt1]*fc%MOD;
	for(int i=0;i<cnt1;++i) dp[i]=0;reverse(dp,dp+n+1);
	for(int i=0;i<n;++i) printf("%d ",dp[i]);return 0;
}