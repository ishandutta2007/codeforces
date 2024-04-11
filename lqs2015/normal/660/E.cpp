#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m,sum1,sum2,pw[1111111],t;
int main()
{
	scanf("%d%d",&n,&m);
	sum1=1;sum2=0;
	pw[0]=1;
	for (int i=1;i<=n;i++) pw[i]=1ll*pw[i-1]*m%mod;
	for (int i=1;i<=n;i++)
	{
		t=sum1;
		sum1=(2ll*sum1*m-1ll*m*sum2)%mod;
		sum2=(1ll*(m-1)*sum2+t)%mod;
	}
	printf("%d\n",(sum1+mod)%mod);
	return 0;
}