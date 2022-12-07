#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MOD=1000000007;
int n,K,a[210],f[210][210][1010],ans;
int main()
{
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	f[0][0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<=n;j++)
			for(int k=0;k<=K;k++)
				if(f[i][j][k])
				{
					if(k+j*(a[i+1]-a[i])>K) continue;
					f[i+1][j][k+j*(a[i+1]-a[i])]+=(LL)(j+1)*f[i][j][k]%MOD;
					f[i+1][j][k+j*(a[i+1]-a[i])]%=MOD;
					if(j>=1)
					{
						f[i+1][j-1][k+j*(a[i+1]-a[i])]+=(LL)j*f[i][j][k]%MOD;
						f[i+1][j-1][k+j*(a[i+1]-a[i])]%=MOD;
					}
					f[i+1][j+1][k+j*(a[i+1]-a[i])]+=f[i][j][k];
					f[i+1][j+1][k+j*(a[i+1]-a[i])]%=MOD;
				}
	for(int k=0;k<=K;k++) ans=(ans+f[n][0][k])%MOD;
	printf("%d\n",ans);
	return 0;
}