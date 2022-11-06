#include<bits/stdc++.h>
using namespace std;
#define re register
int f[2];
const int mod=1e9+7;
int main()
{
	re int n,m,ans=0;
	scanf("%d%d",&n,&m);
	f[0]=2;
	for(re int i=1;i<n;i++)
	{
		re int x=f[0];
		f[0]=(f[1]+f[0])%mod;
		f[1]=x;
	}
	ans=(f[0]+f[1])%mod;
	f[0]=2;f[1]=0;
	for(re int i=1;i<m;i++)
	{
		re int x=f[0];
		f[0]=(f[1]+f[0])%mod;
		f[1]=x;
	}
	ans=((long long)ans+f[0]+f[1]-2+mod)%mod;
	printf("%d\n",ans);
}