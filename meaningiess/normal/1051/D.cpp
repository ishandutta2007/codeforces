#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
#define mod 998244353
using namespace std;
ll f[1010][2010][5];int n,i,j,k;
int main()
{
	f[1][2][1]=f[1][2][2]=f[1][1][3]=f[1][1][4]=1;cin>>n>>k;
	for (i=1;i<n;i++) for (j=1;j<=k;j++)
	{
		if (f[i][j][1])
		{
			(f[i+1][j][1]+=f[i][j][1])%=mod;
			(f[i+1][j+2][2]+=f[i][j][1])%=mod;
			(f[i+1][j][4]+=f[i][j][1])%=mod;
			(f[i+1][j][3]+=f[i][j][1])%=mod;
		}
		if (f[i][j][2])
		{
			(f[i+1][j][2]+=f[i][j][2])%=mod;
			(f[i+1][j][4]+=f[i][j][2])%=mod;
			(f[i+1][j][3]+=f[i][j][2])%=mod;
			(f[i+1][j+2][1]+=f[i][j][2])%=mod;
		}
		if (f[i][j][3])
		{
			(f[i+1][j+1][1]+=f[i][j][3])%=mod;
			(f[i+1][j+1][2]+=f[i][j][3])%=mod;
			(f[i+1][j+1][4]+=f[i][j][3])%=mod;
			(f[i+1][j][3]+=f[i][j][3])%=mod;
		}
		if (f[i][j][4])
		{
			(f[i+1][j+1][1]+=f[i][j][4])%=mod;
			(f[i+1][j+1][2]+=f[i][j][4])%=mod;
			(f[i+1][j][4]+=f[i][j][4])%=mod;
			(f[i+1][j+1][3]+=f[i][j][4])%=mod;
		}
	}
	printf("%I64d\n",(f[n][k][1]+f[n][k][2]+f[n][k][3]+f[n][k][4])%mod);
}