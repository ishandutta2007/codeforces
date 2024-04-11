#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MOD=1000000007;
int n,a[1010],f[1010][20010],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	f[0][10000]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=20000;j++)
			f[i][j]=((j+a[i]<=20000?f[i-1][j+a[i]]:0)+(j-a[i]>=0?f[i-1][j-a[i]]:0))%MOD;
		ans=(ans+f[i][10000])%MOD;
		f[i][10000]=(f[i][10000]+1)%MOD;
	}
	printf("%d\n",ans);
	return 0;
}