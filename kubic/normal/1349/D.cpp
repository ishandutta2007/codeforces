#include <bits/stdc++.h>
using namespace std;
#define N 300005
const int MOD=998244353;
int n,m,ans,inv[N],a[N],f[N];
int main()
{
	scanf("%d",&n);inv[1]=1;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),m+=a[i];
	for(int i=2;i<=m;++i)	
		inv[i]=1ll*inv[MOD%i]*(MOD-MOD/i)%MOD; 
	for(int i=1,t1,t2;i<m;++i)
	{
		t1=(1ll*m*(n-1)%MOD*inv[m-i]%MOD-n+2)*f[i]%MOD;
		t2=1ll*i*(n-1)%MOD*inv[m-i]%MOD*(f[i-1]+1)%MOD;
		f[i+1]=(t1-t2)%MOD; 
	}ans=-f[m];for(int i=1;i<=n;++i) ans=(ans+f[a[i]])%MOD;
	printf("%d\n",(ans+MOD)%MOD);return 0;
}