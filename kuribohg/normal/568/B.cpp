#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MOD=1000000007;
int n,f[4010][4010],s[4010],C[4010][4010],ans;
int main()
{
	scanf("%d",&n);
	C[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
	}
	for(int i=1;i<=n;i++)
	{
		f[i][1]=1;
		for(int j=2;j<=i;j++)
			f[i][j]=(f[i-1][j-1]+((LL)f[i-1][j]*j)%MOD)%MOD;
	}
	s[0]=1;
	for(int i=1;i<n;i++)
		for(int j=1;j<=i;j++)
			s[i]=(s[i]+f[i][j])%MOD;
	for(int i=0;i<n;i++) ans=(ans+((LL)C[n][i]*s[i])%MOD)%MOD;
	printf("%d\n",ans);
	return 0;
}