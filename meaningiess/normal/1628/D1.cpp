#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll f[2020][2020];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j,k;cin>>n>>m>>k;
		for (i=1;i<=n;i++)
		{
			f[i][0]=0;f[i][i]=1ll*k*i%mod;
			for (j=1;j<=m && j<i;j++)
			{
				f[i][j]=1ll*(f[i-1][j-1]+f[i-1][j])*500000004%mod;
			}
		}
		cout<<f[n][m]<<endl;
	}
}