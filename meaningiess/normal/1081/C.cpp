#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
#define mod 998244353
using namespace std;
ll f[2020][2020],g[2020];
int main()
{
	int n,m,k,i,j;cin>>n>>m>>k;f[1][0]=m;
	for (i=2;i<=n;i++)
	{
		f[i][0]=f[i-1][0];
		for (j=1;j<=k;j++)
		{
			f[i][j]=(m-1)*f[i-1][j-1]+f[i-1][j];
			f[i][j]%=mod;
		}
	}
	cout<<f[n][k];
}