#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define MOD 1000000007
int n,ans,fc[N],invF[N];
int qPow(int x,int y)
{
	int res=1;
	for(;y;y/=2,x=1ll*x*x%MOD) if(y&1)
		res=1ll*res*x%MOD;return res;
}
int C(int x,int y)
{return 1ll*fc[x]*invF[y]%MOD*invF[x-y]%MOD;} 
int main()
{
	scanf("%d",&n);fc[0]=invF[0]=1;
	for(int i=1;i<=n;++i) fc[i]=1ll*fc[i-1]*i%MOD;
	invF[n]=qPow(fc[n],MOD-2);
	for(int i=n-1;i;--i) invF[i]=1ll*invF[i+1]*(i+1)%MOD;
	for(int i=(n+1)/2;i<=n;++i) if(!(i&1))
		ans=(ans+2ll*(i<n?C(i,n-i)+C(i-1,n-i-1):1)*fc[i])%MOD;
	printf("%d\n",ans);return 0;
}