#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000,mod=1e9+7;
int n,a[5555555],num[5555555],pw[5555555],res[5555555],ans;
int main()
{
	pw[0]=1;
	for (int i=1;i<=maxn;i++) pw[i]=(pw[i-1]+pw[i-1])%mod;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) num[a[i]]++;
	for (int i=1;i<=maxn;i++)
	{
		for (int j=i+i;j<=maxn;j+=i) num[i]+=num[j];
	}
	for (int i=1;i<=maxn;i++)
	{
		if (!num[i]) res[i]=0;
		else res[i]=1ll*num[i]*pw[num[i]-1]%mod;
	}
	for (int i=maxn;i>=1;i--)
	{
		for (int j=i+i;j<=maxn;j+=i) res[i]=(res[i]-res[j])%mod;
	}
	for (int i=2;i<=maxn;i++) ans=(1ll*res[i]*i+ans)%mod;
	printf("%d\n",(ans+mod)%mod);
	return 0;
}