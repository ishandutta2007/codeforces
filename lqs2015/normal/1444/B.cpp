#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[333333],cur,iv,inv[222222];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=2*n;i++) scanf("%d",&a[i]);
	sort(a+1,a+2*n+1);
	for (int i=1;i<=n;i++) cur=(cur-a[i])%mod;
	for (int i=n+1;i<=2*n;i++) cur=(cur+a[i])%mod;
	for (int i=1;i<=2*n;i++) cur=1ll*cur*i%mod;
	inv[1]=1;
	for (int i=2;i<=n;i++) inv[i]=-1ll*inv[mod%i]*(mod/i)%mod;
	for (int i=1;i<=n;i++)
	{
		cur=1ll*cur*inv[i]%mod*inv[i]%mod;
	}
	printf("%d\n",(cur+mod)%mod);
	return 0;
}