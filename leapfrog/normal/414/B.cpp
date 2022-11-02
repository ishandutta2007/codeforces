#include<bits/stdc++.h>
using namespace std;
int n,m;long long ans,f[2005][2005];
int main()
{
	scanf("%d%d",&n,&m),ans=0,memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++) f[1][i]=1;
	for(int i=2;i<=m;i++)
		for(int j=1;j<=n;j++)
			for(int sjq=1;sjq*j<=n;sjq++)
				f[i][j]=(f[i][j]+f[i-1][j*sjq])%1000000007;
	for(int i=1;i<=n;i++) ans=(ans+f[m][i])%1000000007;
	return printf("%lld\n",ans),0;
}