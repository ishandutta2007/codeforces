#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int mod=1e9+7;
int test,n,num[66],pw[66],ans,a1,a2;
long long a[555555]; 
int main()
{
	scanf("%d",&test);
	pw[0]=1;
	for (int i=1;i<=59;i++) pw[i]=(pw[i-1]+pw[i-1])%mod;
	while(test--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
		memset(num,0,sizeof(num));ans=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<=59;j++)
			{
				if (a[i]&(1ll<<j)) num[j]++;
			}
		}
		for (int i=1;i<=n;i++)
		{
			a1=a2=0;
			for (int j=0;j<60;j++)
			{
				if (a[i]&(1ll<<j))
				{
					a1=(1ll*n*pw[j]+a1)%mod;
					a2=(1ll*num[j]*pw[j]+a2)%mod;
				}
				else
				{
					a1=(1ll*num[j]*pw[j]+a1)%mod;
				}
			}
			ans=(1ll*a1*a2+ans)%mod;
		}
		printf("%d\n",(ans+mod)%mod);
	}
	return Accepted;
}