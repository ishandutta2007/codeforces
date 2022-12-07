#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int MAXN=1000010;
int n,m,MOD,l[MAXN];
int f[5010][5010];
LL fac[5010],P[5010],ans;
vector<LL> d[MAXN];
int main()
{
	scanf("%d%d%d",&n,&m,&MOD);
	for(int i=1;i<=n;i++) scanf("%d",&l[i]);
	P[1]=m;
	for(int i=2;i<=min(m,5000);i++) P[i]=(P[i-1]*(m-i+1))%MOD;
	fac[0]=1;
	for(int i=1;i<=5000;i++) fac[i]=(fac[i-1]*i)%MOD;
	f[1][1]=1;
	for(int i=2;i<=5000;i++)
		for(int j=1;j<=5000;j++)
			f[i][j]=((LL)f[i-1][j-1]+(LL)f[i-1][j]*(j-1))%MOD;
	for(int i=1;i<=n;i++) d[i].resize(l[i]+1);
	for(int i=1;i<=l[1];i++) d[1][i]=(P[i]*(LL)f[l[1]][i])%MOD;
	for(int i=2;i<=n;i++)
	{
		LL Sum=0;
		for(int j=1;j<=l[i-1];j++) Sum=(Sum+d[i-1][j])%MOD;
		for(int j=1;j<=l[i];j++)
		{
			d[i][j]=((P[j]*(LL)f[l[i]][j])%MOD*Sum)%MOD;
			if(j<=l[i-1]) d[i][j]=(d[i][j]-((d[i-1][j]*(LL)f[l[i]][j])%MOD*fac[j])%MOD+MOD)%MOD;
		}
	}
	for(int i=1;i<=l[n];i++) ans=(ans+d[n][i])%MOD;
	printf("%I64d\n",ans);
	return 0;
}